/* --- PhoneBook.h --- */

/* ------------------------------------------
Author: Webxxcom
Date: 9/21/2025
------------------------------------------ */

#pragma once

#include "Contact.h"

class PhoneBook
{
private:
    static const int MAX_CONTACTS = 8;
    Contact contacts[MAX_CONTACTS];
    size_t size;

    void add();
    void search();
    void exit();

public:
    PhoneBook();

    void    start();
};
