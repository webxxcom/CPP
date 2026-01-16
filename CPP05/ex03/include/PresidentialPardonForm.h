/* --- PresidentialPardonForm.h --- */

/* ------------------------------------------
Author: Webxxcom
Date: 1/16/2026
------------------------------------------ */

#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H

#include "AForm.h"
#include "Bureaucrat.h"

class PresidentialPardonForm : public AForm {
public:
    PresidentialPardonForm();
    PresidentialPardonForm(std::string const &target);
    PresidentialPardonForm(PresidentialPardonForm const &other);
    PresidentialPardonForm &operator=(PresidentialPardonForm const &other);
    virtual ~PresidentialPardonForm();
    void executeItself() const;

private:
    std::string target;
};

#endif // PRESIDENTIALPARDONFORM_H
