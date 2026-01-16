/* --- Bureaucrat.h --- */

/* ------------------------------------------
Author: Webxxcom
Date: 1/15/2026
------------------------------------------ */

#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include "Grade.h"
#include "Form.h"
#include <string>
#include <iostream>

class Bureaucrat {
private:
    std::string const name;
    Grade grade;
public:
    Bureaucrat();
    Bureaucrat(std::string const name, Grade grade);
    Bureaucrat(Bureaucrat const &other);
    Bureaucrat &operator=(Bureaucrat const &other);
    ~Bureaucrat();

    const std::string& getName() const;
    
    short getGrade() const;
    void incrementGrade();
    void decrementGrade();

    void signForm(Form &f) const;

    friend std::ostream &operator<<(std::ostream &out, Bureaucrat const &other);
};

#endif // BUREAUCRAT_H
