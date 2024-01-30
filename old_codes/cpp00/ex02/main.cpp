#include <iomanip>
#include "Contact.class.hpp"
#include "PhoneBook.class.hpp"

void	add_contact(PhoneBook *phoneBook)
{
	Contact 	new_contact;
	std::string	firstname;
	std::string lastname;
	std::string nickname;
	std::string darkest_secret;
	std::string	phone_number;

	std::cout << "| Please enter a firstname: | ";
	std::getline(std::cin, firstname);

	std::cout << "| Please enter a lastname: | ";
	std::getline(std::cin, lastname);

	std::cout << "| Please enter a nickname: | ";
	std::getline(std::cin, nickname);

	std::cout << "| Please enter a darkest_secret: | ";
	std::getline(std::cin, darkest_secret);

	std::cout << "| Please enter a phone number: | ";
	std::getline(std::cin, phone_number);

	// controls
	if (firstname.empty() || lastname.empty()
	||	nickname.empty() || darkest_secret.empty()
	|| 	phone_number.empty())
	{
		std::cout << "Empty input\n";
		return ;
	}

	new_contact.setFirstname(firstname);
	new_contact.setLastname(lastname);
	new_contact.setNickname(nickname);
	new_contact.setDarkestSecret(darkest_secret);
	new_contact.setPhoneNumber(phone_number);
	(*phoneBook).AddContact(new_contact);
}

std::string cutToTen(std::string var)
{
	if (var.length() > 10)
		return (var.substr(0, 9).append("."));
	return (var);
}

void	search_contact(PhoneBook *phoneBook)
{
	int i = (*phoneBook).GetIndex();
	int	index;

	std::cout << std::setw(10) << "index" << "|";
	std::cout << std::setw(10) << "first name" << "|";
	std::cout << std::setw(10) << "last name" << "|";
	std::cout << std::setw(10) << "nickname" << "|" << std::endl;

	(*phoneBook).printContacts();

	std::cout << "\nPlease enter an index to show Contact:";
	std::cin >> index;
	if (index >= i || index < 0)
		std::cout << "Index out of bounds!" << std::endl;
	else
	{
		std::cout << std::setw(10) << index << "|";
		std::cout << std::setw(10) << (*phoneBook).GetContact(index).getFirstName().substr(0, 10) << "|";
		std::cout << std::setw(10) << (*phoneBook).GetContact(index).getLastName().substr(0, 10) << "|";
		std::cout << std::setw(10) << (*phoneBook).GetContact(index).getNickName().substr(0, 10) << "|" << std::endl;
	}
}

int main(void)
{
	PhoneBook phoneBook;

	std::cout << "Welcome THE PhoneBook ☎️" << std::endl;
	while (1)
	{
		std::string prompt;

		std::cout << "Please enter a command :\n";
		std::cout << "ADD -> To add contact" << std::endl;
		std::cout << "SEARCH -> To print and search contact" << std::endl;
		std::cout << "EXIT -> exit the program" << std::endl;
		std::cout << "> ";
		std::getline(std::cin, prompt);
		if (!prompt.compare("ADD"))
			add_contact(&phoneBook);
		else if (!prompt.compare("SEARCH"))
			search_contact(&phoneBook);
		else if (!prompt.compare("EXIT"))
			break ;
		else
		{
			std::cout << ">>Connat find that command<<" << std::endl;
			std::cout << "----------------------------" << std::endl;
		}
	}
	return (0);
}
