#include "item.h"
#include "localfunctions.h"

//Checks if search was found within inventory 
bool searchValid(int index, int key)
{
	if (index == -1)
	{
		std::cout << "\nNo results found matching ID search " << key << ", try again later!";
		return false;
	}
	else
	{
		return true;
	}
}

//Checks if search was found within inventory 
bool searchValid(int index, std::string key)
{
	//The search was not found within the inventory
	if (index == -1)
	{
		std::cout << "\nNo results found matching Name search " << key << ", try again later!";
		return false;
	}

	else
	{
		return true;
	}
}

//Validates integer input until program may store it
void numValid(int& input)
{	
	//Constantly checks if input is invalid
	while (std::cin.fail() || input < 0)
	{		
		//Prompt for a new input
		std::cout << "\n*********** Please input a valid value! ***********\n";

		//While the value is a negative numerical value
		while (input < 0)
		{
			std::cin >> input;
		}
		
		//While the value can not be stored in int variable
		//Catches and clears every or any characters within buffer (strings)
		while (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore();
			std::cin >> input;
		}
	}

	std::cout << std::endl;
}