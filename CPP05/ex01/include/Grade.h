/* --- Grade.h --- */

/* ------------------------------------------
Author: Webxxcom
Date: 1/15/2026
------------------------------------------ */

#ifndef GRADE_H
#define GRADE_H

#include <stdexcept>
#include <string>

class Grade {
private:
    short value;
public:
    Grade();
    Grade(short value);
    Grade(Grade const &other);
    Grade &operator=(Grade const &other);
    ~Grade();
    operator short() const;

    void set(short value);
    short operator++();
    short operator--();

    class GradeTooHighException : public std::runtime_error {
    public:
        GradeTooHighException(const std::string& msg);
    };
    class GradeTooLowException : public std::runtime_error {
    public:
        GradeTooLowException(const std::string& msg);
    };
};

#endif // GRADE_H
