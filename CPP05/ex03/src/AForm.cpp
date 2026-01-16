/* --- AForm.cpp --- */

/* ------------------------------------------
author: Webxxcom
date: 1/16/2026
------------------------------------------ */

/* --- Form.cpp --- */

/* ------------------------------------------
author: Webxxcom
date: 1/16/2026
------------------------------------------ */

#include "AForm.h"
#include "Bureaucrat.h"
#include <iostream>

AForm::AForm(std::string const name, Grade const sign_grade, Grade const execute_grade)
    : name(name), sign_grade(sign_grade), execute_grade(execute_grade), is_signed() {}

AForm::AForm(std::string const name, Grade const sign_grade, Grade const execute_grade, bool is_signed)
    : name(name), sign_grade(sign_grade), execute_grade(execute_grade), is_signed(is_signed) {}

AForm::~AForm() {}

const std::string &AForm::getName() const { return name; }

const Grade &AForm::getSignGrade() const { return sign_grade; }

const Grade &AForm::getExecuteGrade() const { return execute_grade; }

bool AForm::isSigned() const { return is_signed; }
void AForm::setIsSigned(bool is_signed) { this->is_signed = is_signed; }

void AForm::beSigned(Bureaucrat const &b)
{
    if (b.getGrade() > this->sign_grade)
        throw Grade::GradeTooLowException("The grade is too low to sign the form");
    is_signed = true;
}

void AForm::execute(Bureaucrat const &executor) const
{
    if (!this->is_signed)
        throw FormIsNotSigned("Unable to execute a form because it's not signed");
    else if (executor.getGrade() > this->execute_grade)
        throw Grade::GradeTooLowException("Bureaucrat's grade is too low to execute a form");
    this->executeItself();
}

std::ostream &operator<<(std::ostream &out, AForm &f)
{
    out << f.name << ": sign grade " << f.sign_grade
        << ", execution grade " << f.execute_grade
        << ", " << (f.is_signed ? "is signed" : "is not signed") << std::endl;

    return (out);
}

AForm::FormIsNotSigned::FormIsNotSigned(const std::string &msg)
    : std::runtime_error(msg) { }
