/* --- Grade.cpp --- */

/* ------------------------------------------
author: Webxxcom
date: 1/15/2026
------------------------------------------ */

#include "Grade.h"
#include <stdexcept>

Grade::Grade(short value)
{
    this->set(value);
}

Grade::Grade(Grade const &other)
{
    *this = other;
}

Grade &Grade::operator=(Grade const &other)
{
    this->set(other);
    return (*this);
}

Grade::~Grade() { }
Grade::operator short() const { return value; }

void Grade::set(short value)
{
    if (value < 1)
        throw GradeTooHighException("The grade is too high to be set");
    if (value > 150)
        throw GradeTooLowException("The grade is too low to be set") ;
    this->value = value;
}

short Grade::operator++()
{
    this->set(value + 1);
    return value;
}

short Grade::operator--()
{
    this->set(value - 1);
    return value;
}

Grade::GradeTooHighException::GradeTooHighException(const std::string &msg)
    : std::runtime_error(msg) { }
    
Grade::GradeTooLowException::GradeTooLowException(const std::string &msg)
    : std::runtime_error(msg) { }
