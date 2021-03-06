#include "passserver.h"
#include <iostream>
#include <string>

using namespace std;
using namespace cop4530;

void Menu()
{
  cout << "\n\n";
  cout << "l - Load From File" << endl;
  cout << "a - Add User" << endl;
  cout << "r - Remove User" << endl;
  cout << "c - Change User Password" << endl;
  cout << "f - Find User" << endl;
  cout << "d - Dump HashTable" << endl;
  cout << "s - HashTable Size" << endl;
  cout << "w - Write to Password File" << endl;
  cout << "x - Exit program" << endl;
  cout << "\nEnter choice : ";
}


int main()
{
	char choice;
	size_t size;
	char passFile [100];
	std::string username;
	std::string password;
	std::string newpassword;
	
	std::cout << "Enter preffered hash table size: ";
	std::cin >> size;
	
	PassServer ps(size);
	
	Menu();

	while(cin >> choice)
	{	
		if(choice == 'x')
			break;

		if(choice == 'l')
		{
			std::cout << "Enter password file name to load from: ";
			std::cin >> passFile;

			ps.load(passFile);

		}
		else if(choice == 'a')
		{
			std::cout << "Enter Username: ";
			std::cin >> username;
			std::cout << "Enter Password: ";
			std::cin >> password;
			
			ps.addUser(make_pair(username, password));

		}
		else if(choice == 'r')
		{
			std::cout << "Enter username: ";
			std::cin >> username;
			
			ps.removeUser(username);

		}
		else if(choice == 'c')
		{
			std::cout << "Enter Username: ";
			std::cin >> username;
			std::cout << "Enter Password: ";
			std::cin >> password;
			
			std::cout << "\nEnter new password: ";
			std::cin >> newpassword;
			
			ps.changePassword(make_pair(username, password), newpassword);
			
		}
		else if(choice == 'f')
		{
			std::cout << "Enter Username: ";
			std::cin >> username;
			
			if(ps.find(username))
				std::cout << "User \'" << username << "\' found.";
			else
				std::cout << "User \'" << username << "\' not found.";
		}
		else if(choice == 'd')
		{
			ps.dump();
		}
		else if(choice == 's')
		{ 
			std::cout << "Size of hashtable: " << ps.size();
		}
		else if(choice == 'w')
		{
			std::cout << "Enter password file name to write to: ";
			std::cin >> passFile;
			ps.write_to_file(passFile);
		}
		else
			std::cout << "*****Error: Invalid entry.  Try again.";
		
		Menu();
	}
	
	return 0;
}
		
		
		
	
