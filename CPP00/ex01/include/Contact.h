/* --- Contact.h --- */
#include <string>

/* ------------------------------------------
Author: Webxxcom
Date: 9/21/2025
------------------------------------------ */

#pragma once

#include "inpval.h"

class Contact
{
private:
    std::string first_name;
    std::string lastname;
    std::string nickname;
    std::string phone_number;

public:
    Contact();

    static Contact inputContact();

    std::string const& getName() const;
    std::string const& getLastname() const;
    std::string const& getPhone_number() const;
    std::string const& getNickname() const;

    void setName(std::string name);
    void setLastname(std::string lastname);
    void setPhone_number(std::string phone_number);
    void setNickname(std::string nickname);
};
