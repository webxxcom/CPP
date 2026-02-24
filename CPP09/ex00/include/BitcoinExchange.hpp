/* --- BitcoinExchange.h --- */

/* ------------------------------------------
Author: Webxxcom
Date: 2/23/2026
------------------------------------------ */

#pragma once

#include <map>
#include <string>
#include <ctime>

class BitcoinExchange {
public:
    BitcoinExchange(std::string const &db_filename);
    ~BitcoinExchange();

    void calculate(std::string const& file) const;
private:
    void parse_database();
    time_t extract_time(std::string const &str) const;
    float extract_btc(std::string const &str) const;

    const std::string db_filename;
    std::map<time_t, float> db;
};
