/* --- Data.cpp --- */

/* ------------------------------------------
author: Webxxcom
date: 1/17/2026
------------------------------------------ */

#include "Data.h"

Data::Data() : name(), num() { }
Data::Data(std::string const &name, int num) : name(name), num(num) { }
Data::Data(Data const &other) : name(other.name), num(other.num) { }
Data::~Data() { }
Data &Data::operator=(Data const &other)
{
    name = other.name;
    num = other.num;
    return (*this);
}

const std::string &Data::getName() const { return name; }
void Data::setName(std::string name) { this->name = name; }

int Data::getNum() const { return num; }
void Data::setNum(int num) { this->num = num; }