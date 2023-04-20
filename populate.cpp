#include "item.h"
#include "localfunctions.h"

void menuChoice(Item arrInventory[], int numItem)
{
	//Used to open different files throughout the program
	std::string fileName = "";

	//Used to see if a search result was found
	bool isSearchFound;

	//Will store user input of search and its results
	int keyId = -1;
	int indexFound = -1;
	std::string keyName = "No key";

	//Used to see if the array has been sorted a specific way before.
	bool wasIdSorted = false;
	bool wasNameSorted = false;
	bool wasPriceSorted = false;

	int userChoice = 0;
	do
	{
		std::cout << std::showpoint << std::fixed << std::setprecision(2);
		std::cout << "\n-*-*-*-*-*-*-*-*-*-*-*-* Grocery Store Inventory *-*-*-*-*-*-*-*-*-*-*-*-" << std::endl;
		std::cout << "\n\t1. Search Inventory by ID"
			<< "\n\t2. Search Invemtory by Name"
			<< "\n\t3. Display Inventory Unsorted"
			<< "\n\t4. Display Inventory by ID (Asc)"
			<< "\n\t5. Display Inventory by Name (Asc)"
			<< "\n\t6. Display Inventory by Price (Asc)"
			<< "\n\t7. Exit Program" << std::endl;

		//Prompt for user input of menu choices
		std::cout << "\nChoose a listed option: ";
		std::cin >> userChoice;
		numValid(userChoice);

		switch (userChoice)
		{
		case 1:	//Search through Inventory for Id

			fileName = "InventoryId.txt";
			if (wasIdSorted)
			{
				//Populates array from sorted text file to search through later
				populateArray(arrInventory, fileName, numItem);

				//Prompt for user input of keyId to search through inventory for
				std::cout << "\nEnter ID: ";
				std::cin >> keyId;
				numValid(keyId);

				//Calculates index if and where searched Item is within array
				indexFound = binarySearch(arrInventory, keyId, numItem);
				isSearchFound = searchValid(indexFound, keyId);

				//Outputs where Item was found in inventory
				if (isSearchFound)
				{
					outputSearchResults(arrInventory, indexFound);
				}

				pressEnter();
			}

			else
			{
				//Sorts array by ID and then saves the result as a text file
				quickSortId(arrInventory, 0, (numItem - 1), wasIdSorted);
				saveSort(arrInventory, fileName, numItem);

				//Prompt for user input of keyId to search through inventory for
				std::cout << "\nEnter ID: ";
				std::cin >> keyId;
				numValid(keyId);

				//Calculates index if and where searched Item is within array
				indexFound = binarySearch(arrInventory, keyId, numItem);
				isSearchFound = searchValid(indexFound, keyId);

				//Outputs where Item was found in inventory
				if (isSearchFound)
				{
					outputSearchResults(arrInventory, indexFound);
				}

				pressEnter();
			}
			break;

		case 2:	//Search through Inventory for Name

			fileName = "InventoryName.txt";
			if (wasNameSorted)
			{
				//Populates array from sorted text file to through later
				populateArray(arrInventory, fileName, numItem);

				//Prompt for user input of keyName to search through inventory for
				std::cout << "\nEnter Name: ";
				std::cin.ignore();
				std::getline(std::cin, keyName);

				//Calculates index if and where searched Item is within array
				indexFound = binarySearch(arrInventory, keyName, numItem);
				isSearchFound = searchValid(indexFound, keyName);

				//Outputs where Item was found in inventory
				if (isSearchFound)
				{
					outputSearchResults(arrInventory, indexFound);
				}

				pressEnter(true);
			}

			else
			{
				//Sorts array by Name and then saves the result as a text file
				quickSortName(arrInventory, 0, (numItem - 1), wasNameSorted);
				saveSort(arrInventory, fileName, numItem);

				//Prompt for user input of keyName to search through inventory
				std::cout << "\nEnter Name: ";
				std::cin.ignore();
				std::getline(std::cin, keyName);

				//Calculates index if and where searched Item is within array
				indexFound = binarySearch(arrInventory, keyName, numItem);
				isSearchFound = searchValid(indexFound, keyName);

				//Outputs where Item was found in inventory
				if (isSearchFound)
				{
					outputSearchResults(arrInventory, indexFound);
				}

				pressEnter(true);
			}
			break;

		case 3:	//Display Inventory unsorted (how textfile was ordered originally)

			fileName = "InventoryList.txt";
			outputInventory(fileName, numItem);

			pressEnter();
			break;

		case 4:	//Display Inventory sorted by ID

			fileName = "InventoryId.txt";
			if (wasIdSorted)
			{
				//Outputs contents of the saved ID sort to console
				outputInventory(fileName, numItem);

				pressEnter();
			}

			else
			{
				//Sorts array by ID and then saves the result as a text file
				quickSortId(arrInventory, 0, (numItem - 1), wasIdSorted);
				saveSort(arrInventory, fileName, numItem);

				//Outputs sorted array to console
				outputInventory(arrInventory, numItem);

				pressEnter();
			}
			break;

		case 5:	//Display Inventory Sorted by Name

			fileName = "InventoryName.txt";
			if (wasNameSorted)
			{
				//Outputs contents of the saved Name sort to console
				outputInventory(fileName, numItem);

				pressEnter();
			}

			else
			{
				//Sorts array by Name and then saves the result as a text file
				quickSortName(arrInventory, 0, (numItem - 1), wasNameSorted);
				saveSort(arrInventory, fileName, numItem);

				//Outputs sorted array to console
				outputInventory(arrInventory, numItem);

				pressEnter();
			}
			break;

		case 6:	//Display Inventory sorted by Price

			fileName = "InventoryPrice.txt";
			if (wasPriceSorted)
			{
				//Outputs contents of the saved Price sort to console
				outputInventory(fileName, numItem);

				pressEnter();
			}

			else
			{
				//Sorts array by Price and then saves the result as a text file
				quickSortPrice(arrInventory, 0, (numItem - 1), wasPriceSorted);
				saveSort(arrInventory, fileName, numItem);

				//Outputs sorted array to console
				outputInventory(arrInventory, numItem);

				pressEnter();
			}
			break;

		case 7:	//Exit the program
			std::cout << "\nExiting program...";
			userChoice = -1;
			break;

		default:
			std::cout << "Input not found within menu, please try again...";
			userChoice = 0;
		}

	} while (userChoice > -1);
}

//Returns amount of items in list while populating array from file
int populateArray(Item arrInventory[])
{
	//Opens the default inventory list
	std::ifstream inventory;
	inventory.open("InventoryList.txt");

	//Will temporarily hold values pertaining to corresponding Item members
	int tempID;
	std::string tempName;
	std::string tempDescription;
	double tempPrice;

	//Will read the inventoy file until it is over or storage is over capacity
	int tick = 0;
	while (!inventory.eof() && tick < INVENTORY_SIZE)
	{
		//Stores tempID to corresponding Item ID member
		inventory >> tempID;
		arrInventory[tick].set_id(tempID);

		inventory.ignore();

		//Stores name to corresponding Item name member
		std::getline(inventory, tempName);
		arrInventory[tick].set_name(tempName);

		//Stores description to corresponding Item description
		std::getline(inventory, tempDescription);
		arrInventory[tick].set_description(tempDescription);

		//Stores price to corresponding Item price member
		inventory >> tempPrice;
		arrInventory[tick].set_price(tempPrice);

		tick++;
	}

	inventory.close();
	return tick;
}

//Populates array using the passed file name
void populateArray(Item arrInventory[], std::string fileName, int numItem)
{
	std::ifstream inventory;
	inventory.open(fileName);

	//Will temporarily hold values pertaining to corresponding Item members
	int tempID;
	std::string tempName;
	std::string tempDescription;
	double tempPrice;

	//Will read the inventoy file until it is over or exceeds inventory limit
	int tick = 0;
	while (!inventory.eof() && tick < numItem)
	{
		//Stores tempID to corresponding Item ID member
		inventory >> tempID;
		arrInventory[tick].set_id(tempID);

		inventory.ignore();

		//Stores name to corresponding Item name member
		std::getline(inventory, tempName);
		arrInventory[tick].set_name(tempName);

		//Stores description to corresponding Item description
		std::getline(inventory, tempDescription);
		arrInventory[tick].set_description(tempDescription);

		//Stores price to corresponding Item price member
		inventory >> tempPrice;
		arrInventory[tick].set_price(tempPrice);

		tick++;
	}

	inventory.close();
}

//Saves current state of array to text file array. Presumably used after a array was sorted
void saveSort(Item arrInventory[], std::string fileName, int numItem)
{
	//Creates text file using passed value of fileName
	std::ofstream savedSort;
	savedSort.open(fileName);

	int tick = 0;

	//Stores array to text file until inventory limit is exceeded
	while (tick < numItem)
	{
		savedSort << arrInventory[tick].get_id() << std::endl;
		savedSort << arrInventory[tick].get_name() << std::endl;
		savedSort << arrInventory[tick].get_description() << std::endl;
		savedSort << arrInventory[tick].get_price() << std::endl;

		tick++;
	}

	savedSort.close();
}