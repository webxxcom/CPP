/* --- Intern.h --- */

/* ------------------------------------------
Author: Webxxcom
Date: 1/16/2026
------------------------------------------ */

#ifndef INTERN_H
#define INTERN_H

#include "AForm.h"
#include <string>

class Intern {
public:
    Intern();
    Intern(Intern const& other);
    Intern &operator=(Intern const& other);
    ~Intern();

    AForm *makeForm(std::string const &form_name, std::string const &form_target) const;

    struct FormEntry{
        const char *name;
        AForm* (*creator)(std::string const &target);

    public:
        static AForm *createPresidentialPardonForm(std::string const &target);
        static AForm *createRobotomyRequestForm(std::string const &target);
        static AForm *createShrubberyCreationForm(std::string const &target);
    };
};

#endif // INTERN_H
