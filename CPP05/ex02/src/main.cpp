#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Bureaucrat.h"
#include "AForm.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"

int main()
{
    std::srand(std::time(NULL));

    std::cout << "===== BUREAUCRATS =====\n";
    Bureaucrat boss("Boss", 1);
    Bureaucrat mid("Middle Manager", 50);
    Bureaucrat intern("Intern", 150);

    std::cout << boss << std::endl;
    std::cout << mid << std::endl;
    std::cout << intern << std::endl;

    std::cout << "\n===== FORMS =====\n";
    ShrubberyCreationForm shrub("home");
    RobotomyRequestForm robot("Bender");
    PresidentialPardonForm pardon("Arthur Dent");

    std::cout << shrub << std::endl;
    std::cout << robot << std::endl;
    std::cout << pardon << std::endl;

    std::cout << "\n===== EXECUTE UNSIGNED FORMS =====\n";
    boss.executeForm(shrub);
    boss.executeForm(robot);
    boss.executeForm(pardon);

    std::cout << "\n===== SIGNING TESTS =====\n";
    intern.signForm(shrub);   // should fail
    mid.signForm(shrub);      // should succeed
    mid.signForm(robot);      // should succeed
    mid.signForm(pardon);     // should fail
    boss.signForm(pardon);    // should succeed

    std::cout << "\n===== EXECUTION TESTS =====\n";
    intern.executeForm(shrub);   // too low
    mid.executeForm(shrub);      // should succeed (creates file)
    mid.executeForm(robot);      // too low
    boss.executeForm(robot);     // should succeed (50% success)
    boss.executeForm(pardon);    // should succeed

    std::cout << "\n===== FINAL STATES =====\n";
    std::cout << shrub << std::endl;
    std::cout << robot << std::endl;
    std::cout << pardon << std::endl;

    return 0;
}
