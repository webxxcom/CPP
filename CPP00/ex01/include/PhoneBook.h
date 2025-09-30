/* --- PhoneBook.h --- */

/* ------------------------------------------
Author: Webxxcom
Date: 9/21/2025
------------------------------------------ */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.h"

class PhoneBook
{
public:
    PhoneBook();
    ~PhoneBook();

    void    start();
private:
    static const int MAX_CONTACTS = 8;
    Contact contacts[MAX_CONTACTS];
    size_t  size;

    void    addContact(Contact const &contact);
    void    add();
    void    search();
    void    exit();
};

#endif // PHONEBOOK_H
