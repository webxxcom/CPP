#include <iostream>
#include <stdexcept>
#include "Bureaucrat.h"
#include "AForm.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"
#include "Intern.h"

int main()
{
    std::cout << "===== INTERN FORM CREATION TESTS =====\n";

    Intern someRandomIntern;

    AForm* form1 = 0;
    AForm* form2 = 0;
    AForm* form3 = 0;

    std::cout << "\n-- Creating ShrubberyCreationForm --\n";
    try {
        form1 = someRandomIntern.makeForm("shrubbery creation", "home");
        std::cout << *form1 << std::endl;
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n-- Creating RobotomyRequestForm --\n";
    try {
        form2 = someRandomIntern.makeForm("robotomy request", "Bender");
        std::cout << *form2 << std::endl;
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n-- Creating PresidentialPardonForm --\n";
    try {
        form3 = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
        std::cout << *form3 << std::endl;
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n-- Attempting to create an unknown form --\n";
    AForm *unknownForm = someRandomIntern.makeForm("nonexistent form", "Target");
    if (unknownForm)
    {
        std::cout << *unknownForm << std::endl; // should not reach here
        throw std::logic_error("Form with that name does not exist");
    }

    std::cout << "\n===== CLEANUP =====\n";
    delete form1;
    delete form2;
    delete form3;
    delete unknownForm;

    return 0;
}
