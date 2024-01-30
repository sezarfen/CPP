#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

# include "Contact.class.hpp"
# include <iomanip>
std::string cutToTen(std::string var);

class PhoneBook
{
	private:
		int		index;
		Contact contacts[8];		
	public:
		PhoneBook(void);
		void	AddContact(Contact);
		Contact	GetContact(int index);
		int		GetIndex(void);
		void	addIndex(void);
		void	printContacts(void);
};

PhoneBook::PhoneBook(void)
{
	index = 0;
}

void	PhoneBook::printContacts(void)
{
	for (int a = 0; a < this->index; a++)
	{
		std::cout << std::setw(10) << a << "|";
		std::cout << std::setw(10) << cutToTen(this->GetContact(a).getFirstName()) << "|";
		std::cout << std::setw(10) << cutToTen(this->GetContact(a).getLastName()) << "|";
		std::cout << std::setw(10) << cutToTen(this->GetContact(a).getNickName()) << "|" << std::endl;
	}
}

void	PhoneBook::addIndex(void)
{
	(this->index)++;
}

void		PhoneBook::AddContact(Contact newContact)
{
	if (this->index == 8)
		this->index = 0;
	contacts[this->index] = newContact;
	(this->index)++;
}

Contact		PhoneBook::GetContact(int index)
{
	return (contacts[index]);
}

int		PhoneBook::GetIndex(void)
{
	return (this->index);
}

#endif