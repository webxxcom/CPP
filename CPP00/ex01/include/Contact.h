/* --- Contact.h --- */
#include <string>

/* ------------------------------------------
Author: Webxxcom
Date: 9/21/2025
------------------------------------------ */

#ifndef CONTACT_H
#define CONTACT_H

#include "inpval.h"

class Contact
{
public:
    Contact();
    ~Contact();

    static Contact inputContact();
    const std::string &getName() const;
    void setName(std::string name);

    const std::string &getLastname() const;
    void setLastname(std::string lastname);

    const std::string &getPhone_number() const;
    void setPhone_number(std::string phone_number);

    const std::string &getNickname() const;
    void setNickname(std::string nickname);

private:
    std::string first_name;
    std::string lastname;
    std::string nickname;
    std::string phone_number;
};

#endif // CONTACT_H
