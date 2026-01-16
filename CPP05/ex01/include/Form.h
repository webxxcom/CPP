/* --- Form.h --- */

/* ------------------------------------------
Author: Webxxcom
Date: 1/16/2026
------------------------------------------ */

#ifndef FORM_H
#define FORM_H

#include <string>
#include <stdexcept>
#include "Grade.h"

class Bureaucrat;

class Form {
public:
    Form(std::string const name, Grade const sign_grade, Grade const execute_grade);
    Form(std::string const name, Grade const sign_grade, Grade const execute_grade, bool is_signed);
    Form(Form const &other);
    Form &operator=(Form const &other);
    ~Form();

    const std::string& getName() const;
    const Grade &getSignGrade() const;
    const Grade &getExecuteGrade() const;
    bool isSigned() const;
    void setIsSigned(bool is_signed);

    void beSigned(Bureaucrat const &b);

    friend std::ostream &operator<<(std::ostream &out, Form &f);
private:
    std::string const name;
    Grade const sign_grade;
    Grade const execute_grade;
    bool is_signed;

};

#endif // FORM_H
