/* --- ShrubberyCreationForm.cpp --- */

/* ------------------------------------------
author: Webxxcom
date: 1/16/2026
------------------------------------------ */

#include "ShrubberyCreationForm.h"
#include "AForm.h"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
    : AForm("ShrubberyCreationForm", 145, 137), target(target) { }

ShrubberyCreationForm::~ShrubberyCreationForm() {
    // Destructor
}

void ShrubberyCreationForm::executeItself() const
{
    std::ofstream ofs((this->target + "_shrubbery").c_str());
    ofs << "ASCII tree" << std::endl;
    ofs.close();
}
