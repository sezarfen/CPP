#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : totalContact(0), current(0)
{
	// this->totalContact = 0;
}

int PhoneBook::getTotalContact()
{
	return (this->totalContact);
}

Contact PhoneBook::getContactByIndex(int index)
{
	return (this->contacts[index]);
}

void PhoneBook::addContact(std::string firstName, std::string lastName,
	std::string nickName, std::string phoneNumber, std::string darkestSecret)
{
	Contact newContact(firstName, lastName, nickName, phoneNumber, darkestSecret);
	this->contacts[this->current] = newContact;
	this->current = (this->current + 1) % 8;
	if (this->totalContact < 8) // it will stop, when we reach to 8
		this->totalContact++;
}