/* --- Intern.cpp --- */

/* ------------------------------------------
author: Webxxcom
date: 1/16/2026
------------------------------------------ */

#include "Intern.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"
#include "ShrubberyCreationForm.h"

Intern::Intern() {
    // Constructor
}

Intern::~Intern() {
    // Destructor
}

AForm *Intern::makeForm(std::string const &form_name, std::string const &form_target) const
{
    FormEntry accepted_forms[] = {
        {"robotomy request", FormEntry::createRobotomyRequestForm},
        {"shrubbery creation", FormEntry::createShrubberyCreationForm},
        {"presidential pardon", FormEntry::createPresidentialPardonForm}
    };
    
    for (size_t i = 0; i < sizeof (accepted_forms) / sizeof (accepted_forms[0]); ++i)
        if (accepted_forms[i].name == form_name)
            return (accepted_forms[i].creator(form_target));
    std::cerr << "The provided form name \'" << form_name << "\' does not exist\n";
    return (0);
}

AForm *Intern::FormEntry::createPresidentialPardonForm(std::string const &target)
{
    return new PresidentialPardonForm(target);
}

AForm *Intern::FormEntry::createRobotomyRequestForm(std::string const &target)
{
    return new RobotomyRequestForm(target);
}

AForm *Intern::FormEntry::createShrubberyCreationForm(std::string const &target)
{
    return new ShrubberyCreationForm(target);
}
