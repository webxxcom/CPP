/* --- RobotomyRequestForm.cpp --- */

/* ------------------------------------------
author: Webxxcom
date: 1/16/2026
------------------------------------------ */

#include "RobotomyRequestForm.h"
#include "AForm.h"
#include <iostream>
#include <stdlib.h>

RobotomyRequestForm::RobotomyRequestForm(std::string const &target)
    : AForm("RobotomyRequestForm", 72, 45), target(target) { }

RobotomyRequestForm::~RobotomyRequestForm() {
    // Destructor
}

void RobotomyRequestForm::executeItself() const
{
    std::cout << "DRILLLL DRILL.." << std::endl;
    if (rand() % 2)
        std::cout << target << " has been robotomized" << std::endl;
    else
        std::cout << this->getName() << " failed to robotomize " << target << std::endl;
}
