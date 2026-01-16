/* --- RobotomyRequestForm.h --- */

/* ------------------------------------------
Author: Webxxcom
Date: 1/16/2026
------------------------------------------ */

#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H

#include "AForm.h"

class RobotomyRequestForm : public AForm{
public:
    RobotomyRequestForm(std::string const &target);
    ~RobotomyRequestForm();
    
    void executeItself() const;

private:
    std::string target;

};

#endif // ROBOTOMYREQUESTFORM_H
