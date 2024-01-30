#include "Contact.hpp"

Contact::Contact()
{
	
}

Contact::Contact(std::string firstName, std::string lastName,
			std::string nickName, std::string phoneNumber,
			std::string darkestSecret) : firstName(firstName),
			lastName(lastName), nickName(nickName), phoneNumber(phoneNumber),
			darkestSecret(darkestSecret)
{

}

std::string Contact::getFirstName()
{
	return (this->firstName);
}

std::string Contact::getLastName()
{
	return (this->lastName);
}

std::string Contact::getNickName()
{
	return (this->nickName);
}

std::string Contact::getPhoneNumber()
{
	return (this->phoneNumber);
}

std::string Contact::getDarkestSecret()
{
	return (this->darkestSecret);	
}