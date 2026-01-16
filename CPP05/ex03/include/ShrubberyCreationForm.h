/* --- ShrubberyCreationForm.h --- */

/* ------------------------------------------
Author: Webxxcom
Date: 1/16/2026
------------------------------------------ */

#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H

#include "AForm.h"

class ShrubberyCreationForm : public AForm{
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string const &target);
    ShrubberyCreationForm(ShrubberyCreationForm const &other);
    ShrubberyCreationForm &operator=(ShrubberyCreationForm const &other);
    virtual ~ShrubberyCreationForm();

    void executeItself() const;
private:
    std::string target;
};

#endif // SHRUBBERYCREATIONFORM_H
