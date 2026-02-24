/* --- BitcoinExchange.cpp --- */

/* ------------------------------------------
author: Webxxcom
date: 2/23/2026
------------------------------------------ */

#include "BitcoinExchange.hpp"
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <ctime>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <limits>

BitcoinExchange::BitcoinExchange(std::string const &db_filename)
    : db_filename(db_filename) { parse_database(); }

BitcoinExchange::~BitcoinExchange() { }

void BitcoinExchange::calculate(std::string const &file) const
{
    // What if database is empty?
    if (db.empty())
        throw std::runtime_error("Error! Database is empty..");

    // It's not!
    std::ifstream ifs(file.c_str());
    if (!ifs)
        throw std::runtime_error("Error! Couldn't open input file");
    
    // Read the header
    std::string line;
    if (!std::getline(ifs, line))
        throw std::runtime_error("Error! The input file is empty");

    // Validate header plssss
    if (line != "date | value")
        throw std::runtime_error("Error! Invalid input header");

    // Start line by line reading
    while (std::getline(ifs, line))
    {
        try
        {
            // The `|' must be present in the line
            std::size_t lpos = line.find('|');
            if (lpos == std::string::npos)
                throw std::runtime_error("Error! Invalid line format: `|' is absent");
            
            // The `|' must be surrounded with single spaces
            if (line[lpos - 1] != ' ' || line[lpos + 1] != ' ' || !std::isdigit(line[lpos - 2]) || !std::isdigit(line[lpos + 2]))
                throw std::runtime_error("Error! Invalid format: must be `date | value'");

            // Extract date and btc strs
            std::string date_str = line.substr(0, lpos - 1);
            std::string btcn_str = line.substr(lpos + 2);

            // Convert them appropriately
            time_t date = extract_time(date_str);
            float btcn = extract_btc(btcn_str);
            
            // Print the closest lower date
            std::map<time_t, float>::const_iterator it = db.lower_bound(date);
            std::cout << date_str + " => " << btcn << " = " << it->second * btcn << std::endl;
        }
        catch(const std::runtime_error& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}

static int extract_value(std::string const &str)
{
    char *endptr;
    long res = std::strtoul(str.c_str(), &endptr, 10);
    if (errno == ERANGE || res > std::numeric_limits<int>::max())
    {
        errno = 0;
        throw std::runtime_error("Error! Too large number");
    }
    if (*endptr)
        throw std::runtime_error("Error! Incorrect value format: `" + str + "'");
    return (res);
}

time_t BitcoinExchange::extract_time(std::string const &str) const
{
    std::istringstream iss(str);
    std::string ys, ms, ds;
    
    // Extract year 
    if (!std::getline(iss, ys, '-'))
        throw std::runtime_error("Error! Invalid format: `-' is absent! -> `" + str + "'");

    int yn = extract_value(ys);
    if (yn < 1900)
        throw std::runtime_error("Error! Invalid year -> `" + ys + "'");

    // Extract month
    if (!std::getline(iss, ms, '-'))
        throw std::runtime_error("Error! Invalid format: month is absent! -> `" + str + "'");

    int mn = extract_value(ms);
    if (mn < 1 || mn > 12)
        throw std::runtime_error("Error! Invalid month -> `" + ms + "'");

    // Extract day
    if (!std::getline(iss, ds, '-'))
        throw std::runtime_error("Error! Invalid format: day is absent! -> `" + str + "'");

    int dn = extract_value(ds);
    if (dn < 1 || dn > 31)
        throw std::runtime_error("Error! Invalid day -> `" + ds + "'");

    // If there are extra characters in the date
    if (!iss.eof())
        throw std::runtime_error("Error! Invalid format -> `" + str + "'");

    // Convert to epoch time
    std::tm t;
    std::memset(&t, 0, sizeof (std::tm));
    t.tm_year = yn - 1900;
    t.tm_mon = mn - 1;
    t.tm_mday = dn;
    t.tm_isdst = -1;

    time_t res = timegm(&t);
    if (res == static_cast<time_t>(-1) || t.tm_year != yn - 1900 || t.tm_mon != mn - 1 || t.tm_mday != dn)
        throw std::runtime_error("Error! Invalid date or conversion failure");
    return res;
}

float BitcoinExchange::extract_btc(std::string const &str) const
{
    // Extract float btc value
    char *endptr;
    double res = std::strtod(str.c_str(), &endptr);
    if (errno == ERANGE || res > std::numeric_limits<int>::max() || res > std::numeric_limits<float>::max())
    {
        errno = 0;
        throw std::runtime_error("Error! Too large number");
    }
    if (*endptr)
        throw std::runtime_error("Error! Ivalid number format");
    if (res < 0)
        throw std::runtime_error("Error! not a positive btc number");
    return res;
}

void BitcoinExchange::parse_database()
{
    // Open database file
    std::ifstream ifs(db_filename.c_str());
    if (!ifs)
        throw std::runtime_error("Error! The file can't be open");

    // Read header line
    std::string line;
    if (!std::getline(ifs, line))
        throw std::runtime_error("Error! Empty database");

    // Verify the header line
    if (line != "date,exchange_rate")
        throw std::runtime_error("Error! Incorrect database header");

    // Start line by line parsing
    while (std::getline(ifs, line))
    {
        // Check if coma is there
        size_t cpos = line.find(',');
        if (cpos == std::string::npos)
            throw std::runtime_error("Error! Incorrect line format: coma is absent");

        // Extract fields
        time_t date = extract_time(line.substr(0, cpos));
        float nbtc = extract_btc(line.substr(cpos + 1));
        if (db.insert(std::pair<time_t, float>(date, nbtc)).second)
            throw std::runtime_error("Error! Duplicate date in database");
    }
}
