#include "PhoneBook.hpp"

int	checkPhoneNumber(std::string phoneNumber)
{
	int i = 0;

	while (phoneNumber[i])
	{
		if (!isdigit(phoneNumber[i]))
			return (0);
		i++;
	}
	return (1);
}

void	addingProcess(PhoneBook pb)
{
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;

	std::cout << "Ahhh.. what a great choice!" << std::endl;
	std::cout << "***************" << std::endl;
	
	// Taking inputs from user
	std::cout << "Please enter a first name for contact : ";
	getline(std::cin, firstName);
	std::cout << std::endl << "Please enter a last name for contact : ";
	getline(std::cin, lastName);
	std::cout << std::endl << "Please enter a nick name for contact : ";
	getline(std::cin, nickName);
	std::cout << std::endl << "Please enter a phone number for contact : ";
	getline(std::cin, phoneNumber);
	std::cout << std::endl << "Please enter a darkest secret for contact : ";
	getline(std::cin, darkestSecret);
	
	if (checkPhoneNumber(phoneNumber) == 0)
	{
		std::cout << "You know what you are doing right 🤠, please enter a numerical phone number next time!" << std::endl;
		return ;
	}
	std::cout << "There you go! now we have an additional contact!" << std::endl;
	pb.addContact(firstName, lastName, nickName, phoneNumber, darkestSecret);
}

void	searchingProcess(PhoneBook pb)
{
	int size = pb.getTotalContact();

	for (int i = 0; i <= size; i++)
	{
		Contact c = pb.getContactByIndex(i);
		std::cout << "FirstName : " << c.getFirstName() << std::endl;
		std::cout << "LastName : " << c.getLastName() << std::endl;
		std::cout << "NickName : " << c.getNickName() << std::endl;
		std::cout << "PhoneNumber : " << c.getPhoneNumber() << std::endl;
		std::cout << "DarkestSecret : " << c.getDarkestSecret() << std::endl;
	}
}

int main(int argc, char *argv[])
{
	std::cout << "Hello and welcome to the PhoneBook the one of the greatest technology from 80s!" << std::endl;
	std::cout << "Now we are entering the magical world of the PhoneBook, if you are ready please write your command!" << std::endl;
	std::string command;
	PhoneBook pb;

	while (true)
	{
		std::cout << "Your command : ";
		std::cin >> command;

		if (command.compare("ADD") == 0)
			addingProcess(pb);
		else if (command.compare("SEARCH") == 0)
			searchingProcess(pb);
		else if (command.compare("EXIT") == 0)
			break;
		else
			std::cout << "Command not found, please try again!" << std::endl;
	}
	std::cout << "Thank you for using PhoneBook, see you again." << std::endl;
	return (0);

}