/* --- Bureaucrat.cpp --- */

/* ------------------------------------------
author: Webxxcom
date: 1/15/2026
------------------------------------------ */

#include "Bureaucrat.h"
#include "AForm.h"

Bureaucrat::Bureaucrat(std::string const name, Grade grade)
    : name(name), grade(grade) { }

Bureaucrat::Bureaucrat(Bureaucrat const &other)
    : name(other.name), grade(other.grade) { }

Bureaucrat::~Bureaucrat() { }

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
    this->grade = other.grade;
    return (*this);
}


const std::string &Bureaucrat::getName() const { return name; }
short Bureaucrat::getGrade() const { return grade; }

void Bureaucrat::incrementGrade()
{
    --this->grade;
}

void Bureaucrat::decrementGrade()
{
    ++this->grade;
}

void Bureaucrat::signForm(AForm &f) const
{
    try
    {
        f.beSigned(*this);
        std::cout << name << " signed " << f.getName() << std::endl;
    }
    catch(const std::runtime_error& e)
    {
        std::cout << name << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const &f) const
{
    try
    {
        f.execute(*this);
        std::cout << name << " executed " << f.getName() << std::endl;
    }
    catch(const std::runtime_error& e)
    {
        std::cout << name << " couldn't execute " << f.getName() << " because " << e.what() << std::endl;
    }
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &other)
{
    out << other.name << ", bureaucrat grade " << other.grade << ".";
    return (out);
}
