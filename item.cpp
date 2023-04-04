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
	int start = 0;
	int end = SIZE - 1;
	int mid;
	int midValue;

	int tick = 0;
	while (start <= end)
	{
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

		else //Only executes if item with identical Id is found
		{
			return mid;
		}
	}

	return -1;	//Signifies that no results were found
}

//Returns index of item with name identical to search key
int binarySearch(Item arrInventory[], std::string key, int SIZE)
{
	int start = 0;
	int end = SIZE - 1;
	int mid;
	std::string midValue;

	int tick = 0;
	while (start <= end)
	{
		mid = (start + end) / 2;

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
		int pIndex;									//Stores where the break point is in a partition during a pass
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
	//Used to open diffrent files throughout the program
	std::string fileName;
	
	//Will store user input and results of desired search result
	int indexFound;
	int keyId;
	std::string keyName;

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
		
		std::cout << "\nChoose a listed option: ";
		std::cin >> userChoice;
		numValid(userChoice);
		
		switch (userChoice)
		{
			case 1:	//Search through Inventory by Id
				
				fileName = "InventoryId.txt";
				if (wasIdSorted)
				{
					populateArray(arrInventory, fileName, numItem);

					std::cout << "\nEnter ID: ";
					std::cin >> keyId;
					numValid(keyId);

					indexFound = binarySearch(arrInventory, keyId, numItem);

					outputSearch(arrInventory, indexFound);
					
					pressEnter();
				}
				
				else
				{
					quickSortId(arrInventory, 0, (numItem - 1), wasIdSorted);
					saveSort(arrInventory, fileName, numItem);
					
					std::cout << "\nEnter ID: ";
					std::cin >> keyId;

					indexFound = binarySearch(arrInventory, keyId, numItem);

					outputSearch(arrInventory, indexFound);

					pressEnter();
				}
				break;

			case 2:
				//Search by Name
				break;

			case 3:
			fileName = "InventoryList.txt";
			outputInventory(fileName, numItem);

			case 4:
				//Sort by Id
				break;

			case 5:
				//sort by Name
				break;

			case 6:
				//Sort by Price
				break;

			case 7:
				userChoice = -1;
				break;
				
			default:
				std::cout << "Invalid input, please try again...";
				userChoice = 0;
		}

	}while(userChoice > -1);
}

//Returns amount of items in list while populating array
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

//Only populates array 
void populateArray(Item arrInventory[], std::string fileName, int numItem)
{
	std::ifstream inventory;
	inventory.open(fileName);

	//Will temporarily hold values pertaining to corresponding Item members
	int tempID;
	std::string tempName;
	std::string tempDescription;
	double tempPrice;

	//Will read the inventoy file until it is over or 
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

void saveSort(Item arrInventory[], std::string fileName, int numItem)
{
	std::ofstream savedSort;
	savedSort.open(fileName);
	
	int tick = 0;
	
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

void outputSearch(Item arrInventory[], int index)
{
	std::cout << "\nItem found at index: " << index;

	tableHeader();

	std::cout << std::left
		<< "\n| " << std::setw(5) << arrInventory[index].get_id()
		<< " | " << std::setw(27) << arrInventory[index].get_name()
		<< " | " << std::setw(55) << arrInventory[index].get_description()
		<< " | " << arrInventory[index].get_price() << "  |";

	tableSeperation();
}

//Outpus 
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
	while (!savedSort.eof() && tick < INVENTORY_SIZE)
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

void pressEnter()
{
	std::cout << "\nPress Enter to Continue...";
	std::cin.ignore();
	std::cin.get();
}

void tableHeader()
{
	//Outputs header for table in console
	tableSeperation();
	std::cout << std::left << std::setw(9) << "\n| ID" << std::setw(30) << "| Name" << std::setw(58) << "| Description" << "| Price |";
	tableSeperation();
}

//Seperates 
void tableSeperation()
{
	std::cout << std::right;
	std::cout << "\n+" << std::setfill('-') << std::setw(104) << "+";
	std::cout << std::setfill(' ');
}

void numValid(int input)
{
	while (input < -1 || std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore();
		std::cout << "\n\tPlease input a valid value!: ";
		std::cin >> input;
		std::cin.clear();
		std::cin.ignore();
	}
}