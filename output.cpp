#include "item.h"
#include "localfunctions.h"

//Outputs data of Item at an index
void outputSearchResults(Item arrInventory[], int index)
{
	std::cout << "\nItem found at index: " << index;

	//Outputs data of Item to console as a table
	tableHeader();
	std::cout << std::left
		<< "\n| " << std::setw(5) << arrInventory[index].get_id()
		<< " | " << std::setw(27) << arrInventory[index].get_name()
		<< " | " << std::setw(55) << arrInventory[index].get_description()
		<< " | " << arrInventory[index].get_price() << "  |";
	tableSeperation();
}

//Outputs data of Items in array to console as a table
void outputInventory(Item arrInventory[], int numItem)
{
	tableHeader();
	//Loop to output item members in table in console
	for (int i = 0; i < numItem; i++)
	{
		std::cout << std::left
			<< "\n| " << std::setw(5) << arrInventory[i].get_id()
			<< " | " << std::setw(27) << arrInventory[i].get_name()
			<< " | " << std::setw(55) << arrInventory[i].get_description()
			<< " | " << arrInventory[i].get_price() << "  |";
	}
	tableSeperation();

}

//Outputs data of Item from a text file
void outputInventory(std::string fileName, int numItem)
{
	int tick = 0;												//Counter that will tell us when we passed the maximum inventory size
	std::string tempId, tempName, tempDescription, tempPrice;	//Varaiables that will temperarily hold Item member data
	std::ifstream savedSort;									//File with sorted data that will be read from
	savedSort.open(fileName);

	if (savedSort.fail())
	{
		std::cout << "\nProgram could not locate file by name " << fileName << std::endl;
		return;
	}

	//Outputs header for table in console
	tableHeader();
	//Loop to read the text file of a saved sort and output it into the console
	while (!savedSort.eof() && tick < numItem)
	{
		//Reads file to store Id of Item to output to console
		savedSort >> tempId;

		savedSort.ignore();

		//Reads file to store Id of Item to output to console
		std::getline(savedSort, tempName);

		//Reads file to store Id of Item to output to console
		std::getline(savedSort, tempDescription);

		//Reads file to store Id of Item to output to console
		savedSort >> tempPrice;

		//Outputs temperary variable values to console to display Item data as a table
		std::cout << std::left
			<< "\n| " << std::setw(5) << tempId
			<< " | " << std::setw(27) << tempName
			<< " | " << std::setw(55) << tempDescription
			<< " | " << tempPrice << "  |";

		tick++;
	}
	tableSeperation();
	savedSort.close();
}

//'Eats' an input so that user has to press enter to continue, used to limit data displayed at once
void pressEnter(bool isGetline)
{
	//Works diffrently depending on what previous method was used to collect data from user.
	//Getline already 'eats' an input if implememted properly.

	if (isGetline)
	{
		std::cout << "\nPress Enter to Continue...";
		std::cin.ignore();
	}

	//Implying we used cin to collect last user input
	else
	{
		std::cout << "\nPress Enter to Continue...";
		std::cin.ignore();
		std::cin.get();	//'Eats' an input
	}
}

//Displays column names of table header using Item attributes
void tableHeader()
{
	//Outputs header for table in console
	tableSeperation();
	std::cout << std::left << std::setw(9) << "\n| ID" << std::setw(30) << "| Name" << std::setw(58) << "| Description" << "| Price |";
	tableSeperation();
}

//Creates the horizontal lines seperating the table of Items; 'creates the lines for the rows'
void tableSeperation()
{
	std::cout << std::right;
	std::cout << "\n+" << std::setfill('-') << std::setw(104) << "+";
	std::cout << std::setfill(' ');
}