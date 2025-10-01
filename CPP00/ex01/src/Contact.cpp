/* --- Contact.cpp --- */

/* ------------------------------------------
author: Webxxcom
date: 9/21/2025
------------------------------------------ */

#include "Contact.h"

Contact::Contact() : first_name(), lastname(), nickname(), phone_number() { }

std::string const& Contact::getName() const { return first_name; }
std::string const& Contact::getLastname() const {return lastname;}
std::string const& Contact::getPhone_number() const {return phone_number;}
std::string const& Contact::getNickname() const { return nickname; }

void Contact::setName(std::string first_name) { this->first_name = first_name; }
void Contact::setLastname(std::string lastname) { this->lastname = lastname;}
void Contact::setPhone_number(std::string phone_number) { this->phone_number = phone_number;}
void Contact::setNickname(std::string nickname) { this->nickname = nickname; }

Contact Contact::inputContact()
{
	Contact res;
 
	inpval::getValidInput("Please enter the first_name: ", res.first_name);
	inpval::getValidInput("Please enter the lastname: ", res.lastname);
	inpval::getValidInput("Please enter the nickname: ", res.nickname);
	inpval::getValidInput("Please enter the phone number: ", res.phone_number);
	return (res);
}
