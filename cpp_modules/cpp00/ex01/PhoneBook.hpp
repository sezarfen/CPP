#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contacts[8];
		int		current;
		int		totalContact;

	public:
		PhoneBook();
		
		Contact getContactByIndex(int index);
		int getTotalContact();
		void addContact(std::string firstName,
			std::string lastName, std::string nickName,
			std::string phoneNumber, std::string darkestSecret);
};

#endif /* end of PHONEBOOK_H */