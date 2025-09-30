/* --- PhoneBook.cpp --- */

/* ------------------------------------------
author: Webxxcom
date: 9/21/2025
------------------------------------------ */

#include "PhoneBook.h"
#include <iomanip>
#include <string>
#include <cstdlib>
#include <sstream>
#include <iostream>

PhoneBook::PhoneBook() : size(0)
{
    // Constructor
}

PhoneBook::~PhoneBook()
{
    // Destructor
}

void PhoneBook::add()
{
    contacts[this->size++ % MAX_CONTACTS] = Contact::inputContact();
    std::cout << "The contact was successfully added\n";
}

template<typename T>
static std::string getFormattedBox(T const& content, const int width = 10)
{
    std::stringstream ss;
    std::stringstream content_str;

    content_str << content;
    ss << std::setw(width)
       << std::setfill(' ')
       << (content_str.str().size() > 10 ? content_str.str().substr(0, 7) + "..." : content_str.str());
    return (ss.str());
}

void PhoneBook::search()
{
    if (!size)
        std::cout << "You don't have any saved contacts yet\n";
    else
    {
        std::cout << getFormattedBox("Index") << '|'
                  << getFormattedBox("First name") << '|'
                  << getFormattedBox("Last name") << '|'
                  << getFormattedBox("Nickname") << '\n'
                  << std::setfill('-') << std::setw(44) << '-' << std::endl;
        for (size_t i = 0; i < size && i < MAX_CONTACTS; ++i)
        {
            std::cout << getFormattedBox(i) << '|'
                      << getFormattedBox(contacts[i].getName()) << '|'
                      << getFormattedBox(contacts[i].getLastname()) << '|'
                      << getFormattedBox(contacts[i].getNickname()) << '\n';
        }
    }
}

void PhoneBook::exit()
{
    std::cout << "Goodbye!" << std::endl;
    std::exit(0);
}

static void display_choices()
{
    static std::string options[] = {
        "Add",
        "Search",
        "Exit"};
    for (std::size_t i = 0; i < options->length(); ++i)
        std::cout << i + 1 << ") " << options[i] << std::endl;
}

void PhoneBook::start()
{
    while (1)
    {
        display_choices();
        int choice;
        while (1)
        {
            std::cout << "Your choice: ";
            std::cin >> choice;
            inpval::cleanBuffer(std::cin);
            if (std::cin.eof())
                return;
            if (!std::cin.fail())
                break ;
        };
        switch (choice)
        {
        case 1:
            this->add();
            break;
        case 2:
            this->search();
            break;
        case 3:
            this->exit();
            break;
        default:
            std::cout << "Please enter valid option" << std::endl;
            break;
        }
    }
}
