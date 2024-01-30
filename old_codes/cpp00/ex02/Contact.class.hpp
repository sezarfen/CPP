#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

# include <iostream>

class Contact
{
	private:
		std::string firstname;
		std::string lastname;
		std::string nickname;
		std::string	phone_number;
		std::string darkest_secret;
	public:
		// setters
		void setFirstname(std::string);
		void setLastname(std::string);
		void setNickname(std::string);
		void setDarkestSecret(std::string);
		void setPhoneNumber(std::string);
		// getters
		std::string getFirstName(void);
		std::string getLastName(void);
		std::string getNickName(void);
		std::string getDarkestSecret(void);
		std::string	getPhoneNumber(void);
};

//////////////////// setters

void Contact::setFirstname(std::string firstname)
{
	this->firstname = firstname;
}

void Contact::setLastname(std::string lastname)
{
	this->lastname = lastname;
}
void Contact::setNickname(std::string nickname)
{
	this->nickname = nickname;
}
void Contact::setDarkestSecret(std::string secret)
{
	this->darkest_secret = secret;
}

void Contact::setPhoneNumber(std::string phoneNumber)
{
	this->phone_number = phoneNumber;
}

//////////////////////// getters

std::string Contact::getFirstName(void)
{
	return (this->firstname);
}

std::string Contact::getLastName(void)
{
	return (this->lastname);
}
std::string Contact::getNickName(void)
{
	return (this->nickname);
}
std::string Contact::getDarkestSecret(void)
{
	return (this->darkest_secret);
}

std::string Contact::getPhoneNumber(void)
{
	return (this->phone_number);
}

#endif