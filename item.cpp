#include"item.h"

//	============ Item Accessors and Mutators ============

void Item::set_id(int new_id)
{
	id = new_id;
}

int Item::get_id()
{
	return id;
}

void Item::set_price(double new_price)
{
	price = new_price;
}

double Item::get_price()
{
	return price;
}

void Item::set_name(std::string new_name)
{
	name = new_name;
}

std::string Item::get_name()
{
	return name;
}

void Item::set_description(std::string new_description)
{
	description = new_description;
}

std::string Item::get_description()
{
	return description;
}

Item::Item()
{
	id = 0;
	price = 0.0;
	name = "No name";
	description = "No description";
}

//	============ Function Defenitions ============

//	------ Search & Sort Functions ------

//Returns index of item with Id identical to search key
int binarySearch(Item arrInventory[], int key, int SIZE)
{
	int start = 0;		//Will store starting index of array partitions
	int end = SIZE - 1;	//Will store ending index of array partitions
	int mid;			//Will store middle index of array partitions
	int midValue;		//Will store ID of middle index

	//While starting index is less than or equal to ending boundary
	while (start <= end)
	{
		//Calculates middle index and its value
		mid = (start + end) / 2;
		midValue = arrInventory[mid].get_id();
		
		if (key < midValue)
		{
			end = mid - 1;
		}
		
		else if (key > midValue)
		{
			start = mid + 1;
		}

		else //Only executes if item with identical key is found
		{
			return mid;
		}
	}

	return -1;	//Signifies that no results were found
}

//Returns index of item with name identical to search key
int binarySearch(Item arrInventory[], std::string key, int SIZE)
{
	int start = 0;			//Will store starting index of array partitions
	int end = SIZE - 1;		//Will store ending index of array partitions
	int mid;				//Will store middle index of array partitions
	std::string midValue;	//Will store name of middle index

	//While starting index is less than or equal to ending boundary
	while (start <= end)
	{
		//Calculates middle index of current partition and its value
		mid = (start + end) / 2;
		midValue = arrInventory[mid].get_name();

		if (key < midValue)
		{
			end = mid - 1;
		}

		else if (key > midValue)
		{
			start = mid + 1;
		}

		else //Only executes if item with identical Id is found
		{
			return mid;
		}
	}

	return -1;	//Signifies that no results were found
}

//Sorts Item array in ascending order of Id number
void quickSortId(Item arrInventory[], int start, int end, bool& isSorted)
{
	//Will keep on executing as long as the 'subarray' contains more than 1 element thanks to recursion
	if (start < end)
	{
		int pIndex;										//Stores where the break point is in a partition during a pass
		pIndex = partitionId(arrInventory, start, end);	//Partitions array and returns where the break point occurs

		//Constantly breaks array into 'subarrays' defined by the boundaries of new partitions
		
		quickSortId(arrInventory, start, (pIndex - 1), isSorted);	//Recursive call to sort low partition
		quickSortId(arrInventory, (pIndex + 1), end, isSorted);		//Recursive call to sort high partition
	}

	isSorted = true;
}

//Sorts Item array in ascending order of name 
void quickSortName(Item arrInventory[], int start, int end, bool& isSorted)
{
	//Will keep on executing as long as the 'subarray' contains more than 1 element thanks to recursion
	if (start < end)
	{
		int pIndex;											//Stores where the break point is in a partition during a pass
		pIndex = partitionName(arrInventory, start, end);	//Partitions array and returns where the break point occurs


		//Constantly breaks array into 'subarrays' defined by the boundaries of new partitions

		quickSortName(arrInventory, start, (pIndex - 1), isSorted);	//Recursive call to sort low partition
		quickSortName(arrInventory, (pIndex + 1), end, isSorted);	//Recursive call to sort high partition
	}

	isSorted = true;
}

//Sorts Item array in ascending order of price 
void quickSortPrice(Item arrInventory[], int start, int end, bool& isSorted)
{
	//Will keep on executing as long as the 'subarray' contains more than 1 element thanks to recursion
	if (start < end)
	{
		int pIndex;											//Stores where the break point is in a partition during a pass
		pIndex = partitionPrice(arrInventory, start, end);	//Partitions array and returns where the break point occurs


		//Constantly breaks array into 'subarrays' defined by the boundaries of new partitions

		quickSortPrice(arrInventory, start, (pIndex - 1), isSorted);	//Recursive call to sort low partition
		quickSortPrice(arrInventory, (pIndex + 1), end, isSorted);		//Recursive call to sort high partition
	}

	isSorted = true;
}

//Partitions the array by Item Id
int partitionId(Item arrInventory[], int start, int end)
{
	int pivot = arrInventory[end].get_id();	//Sets the value of pivot to the value of the ending index of the partition
	int pIndex = start;						//Used to mark where the break between the high and low partitions is

	//Loops through the current iteration of the current partition
	for (int i = start; i < end; i++)
	{
		//Part of the low partition
		//If the element at pIndex is less than the pivot, swap values of element at index i with index pIndex
		if (arrInventory[i].get_id() < pivot)
		{
			swapElements(arrInventory, i, pIndex);
			pIndex++;
		}
	}

	swapElements(arrInventory, pIndex, end); //Swaps pivit with pIndex after a pass has be done
	return pIndex;                           //Returns where the break between the high and low partitions is
}

//Partitions the array by Item name
int partitionName(Item arrInventory[], int start, int end)
{
	std::string pivot = arrInventory[end].get_name();	//Sets the value of pivot to the value of the ending index of the partition
	int pIndex = start;									//Used to mark where the break between the high and low partitions is

	//Loops through the current iteration of the current partition
	for (int i = start; i < end; i++)
	{
		//Part of the low partition
		//If the element at pIndex is less than the pivot, swap values of element at index i with index pIndex
		if (arrInventory[i].get_name() < pivot)
		{
			swapElements(arrInventory, i, pIndex);
			pIndex++;
		}
	}
	swapElements(arrInventory, pIndex, end); //Swaps pivit with pIndex after a pass has be done
	return pIndex;                           //Returns where the break between the high and low partitions is
}

//Partitions the array by Item price
int partitionPrice(Item arrInventory[], int start, int end)
{
	double pivot = arrInventory[end].get_price();	//Sets the value of pivot to the value of the ending index of the partition
	int pIndex = start;								//Used to mark where the break between the high and low partitions is

	//Loops through the current iteration of the current partition
	for (int i = start; i < end; i++)
	{
		//Part of the low partition
		//If the element at pIndex is less than the pivot, swap values of element at index i with index pIndex
		if (arrInventory[i].get_price() < pivot)
		{
			swapElements(arrInventory, i, pIndex);
			pIndex++;
		}
	}
	swapElements(arrInventory, pIndex, end); //Swaps pivit with pIndex after a pass has be done
	return pIndex;                           //Returns where the break between the high and low partitions is
}

//Swaps positions of two elements of type Item given their indexes
void swapElements(Item arrInvetory[], int a, int b)
{
	Item temp;

	temp = arrInvetory[a];
	arrInvetory[a] = arrInvetory[b];
	arrInvetory[b] = temp;

}

//	------- Populate & Output Table Functions -------

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
					quickSortPrice(arrInventory, 0, (numItem -1), wasPriceSorted);
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
				std::cout << "Invalid input, please try again...";
				userChoice = 0;
		}

	}while(userChoice > -1);
}

//Returns amount of items in list while populating array from file
int populateArray(Item arrInventory[])
{
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
	while (input < -1 || std::cin.fail())
	{
		//Wipes the buffer
		std::cin.clear();
		std::cin.ignore();
		
		//Prompt to input new value
		std::cout << "\tPlease input a valid value!: ";
		std::cin >> input;
	}
}