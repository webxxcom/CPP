/* --- Form.cpp --- */

/* ------------------------------------------
author: Webxxcom
date: 1/16/2026
------------------------------------------ */

#include "Form.h"
#include "Bureaucrat.h"
#include <iostream>

Form::Form(std::string const name, Grade const sign_grade, Grade const execute_grade)
    : name(name), sign_grade(sign_grade), execute_grade(execute_grade), is_signed() {}

Form::Form(std::string const name, Grade const sign_grade, Grade const execute_grade, bool is_signed)
    : name(name), sign_grade(sign_grade), execute_grade(execute_grade), is_signed(is_signed) {}

Form::Form(Form const &other)
    : name(other.name), sign_grade(other.sign_grade),
      execute_grade(other.execute_grade), is_signed(other.is_signed) {}

Form::~Form() {}

const std::string &Form::getName() const { return name; }

const Grade &Form::getSignGrade() const { return sign_grade; }

const Grade &Form::getExecuteGrade() const { return execute_grade; }

bool Form::isSigned() const { return is_signed; }
void Form::setIsSigned(bool is_signed) { this->is_signed = is_signed; }

void Form::beSigned(Bureaucrat const &b)
{
    if (b.getGrade() > this->sign_grade)
        throw Grade::GradeTooLowException("The grade is too low for bureaucrat to sign the form");
    is_signed = true;
}

std::ostream &operator<<(std::ostream &out, Form &f)
{
    out << f.name << ": sign grade " << f.sign_grade
        << ", execution grade " << f.execute_grade
        << ", " << (f.is_signed ? "is signed" : "is not signed") << std::endl;

    return (out);
}
