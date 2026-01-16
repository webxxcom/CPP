/* --- AForm.h --- */

/* ------------------------------------------
Author: Webxxcom
Date: 1/16/2026
------------------------------------------ */

#ifndef AFORM_H
#define AFORM_H

#include "Grade.h"

class Bureaucrat;

class AForm {
protected:
    AForm(std::string const name, Grade const sign_grade, Grade const execute_grade);
    AForm(std::string const name, Grade const sign_grade, Grade const execute_grade, bool is_signed);
    virtual ~AForm();
    
    virtual void executeItself() const = 0;
    
public:
    const std::string& getName() const;
    const Grade &getSignGrade() const;
    const Grade &getExecuteGrade() const;
    bool isSigned() const;
    void setIsSigned(bool is_signed);

    void beSigned(Bureaucrat const &b);
    void execute(Bureaucrat const& executor) const;

    friend std::ostream &operator<<(std::ostream &out, AForm &f);

    class FormIsNotSigned : public std::runtime_error{
    public:
        FormIsNotSigned(const std::string &msg);
    };
private:
    std::string const name;
    Grade const sign_grade;
    Grade const execute_grade;
    bool is_signed;
};

#endif // AFORM_H
