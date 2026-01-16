/* --- PresidentialPardonForm.cpp --- */

/* ------------------------------------------
author: Webxxcom
date: 1/16/2026
------------------------------------------ */

#include "PresidentialPardonForm.h"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(std::string const &target)
    : AForm("PresidentialPardonForm", 25, 5), target(target) { }

PresidentialPardonForm::~PresidentialPardonForm() {
    // Destructor
}

void PresidentialPardonForm::executeItself() const
{
    std::cout << "Informing that " << target << " has been pardoned  by Zaphod Beeblebrox." << std::endl;
}
