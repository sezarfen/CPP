#include "PhoneBook.hpp"
#include <iomanip>
#include <iostream>
#include <sstream>

int	checkPhoneNumber(std::string phoneNumber)
{
	int i = 0;

	while (phoneNumber[i])
	{
		if (!isdigit(phoneNumber[i]) && phoneNumber[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

void	addingProcess(PhoneBook &pb)
{
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;

	std::cout << "Ahhh.. what a great choice!" << std::endl;
	std::cout << "***************";
	
	// Taking inputs from user
	std::cout << std::endl << "Please enter a first name for contact : ";
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

void	checkAndWrite(std::string text)
{
	if (text.length() > 9)
		std::cout << std::setw(10) << text.substr(0, 9) + ".";
	else
		std::cout << std::setw(10) << text;
}

void	searchingProcess(PhoneBook &pb)
{
	int size = pb.getTotalContact();
	std::string choose;

	for (int i = 0; i < size; i++)
	{
		Contact c = pb.getContactByIndex(i);

		std::cout << std::setw(10) << i << "|";
		checkAndWrite(c.getFirstName());
		std::cout << "|";
		checkAndWrite(c.getLastName());
		std::cout << "|";
		checkAndWrite(c.getNickName());
		std::cout << "|" << std::endl;
	}
	std::cout << "Please choose an index to see more informations individually : ";
	getline(std::cin, choose);
	if (checkPhoneNumber(choose) == 0)
	{
		std::cout << "please choose an correct index next time" << std::endl;
		return ;
	}
	// to convert string to int in c++
	int ch = 0;
	std::istringstream iss(choose);
	iss >> ch;
	// end of converting process
	if (ch >= size)
		std::cout << "We don't have that much Contact right now :( " << std::endl; 
	else
	{
		Contact c = pb.getContactByIndex(ch);
		std::cout << "First Name: " << c.getFirstName() << std::endl;
		std::cout << "Last Name:" << c.getLastName() << std::endl;
		std::cout << "Nick Name:" << c.getNickName() << std::endl;
		std::cout << "Phone Number:" << c.getPhoneNumber() << std::endl;
		std::cout << "Darkest Secret:" << c.getDarkestSecret() << std::endl;
	}
}

int main( void )
{
	std::cout << "Hello and welcome to the PhoneBook the one of the greatest technology from 80s!" << std::endl;
	std::cout << "Now we are entering the magical world of the PhoneBook, if you are ready please write your command!" << std::endl;
	std::string command;
	PhoneBook pb;
	
	std::cout << "Your command :";
	while (getline(std::cin, command))
	{
		if (command.compare("ADD") == 0)
			addingProcess(pb);
		else if (command.compare("SEARCH") == 0)
			searchingProcess(pb);
		else if (command.compare("EXIT") == 0)
			break;
		else
			std::cout << "Command not found, please try again!" << std::endl;
		std::cout << "Your command :";
	}
	std::cout << "Thank you for using PhoneBook, see you again." << std::endl;
	return (0);

}