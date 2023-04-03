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

	int tick = 0;
	while (start <= end)
	{
		mid = (start + end) / 2;
		
		if (arrInventory[tick].get_id() < key)
		{
			end = mid - 1;
		}
		
		else if (arrInventory[tick].get_id() > key)
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

	int tick = 0;
	while (start <= end)
	{
		mid = (start + end) / 2;

		if (arrInventory[tick].get_name() < key)
		{
			end = mid - 1;
		}

		else if (arrInventory[tick].get_name() > key)
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

void menu()
{
	std::cout << "************ Welcome to Grocery Store Inventory ************";

	std::cout << "Please select an option listed below";
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

		//Only need to do .ignore() when you are doing a getline immediately after a extraction in the same stream
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

//Outpus 
void outputInventory(Item arrInventory[], int numItem)
{
	//Outputs header for table in console
	tableSeperation();
	std::cout << std::left << std::setw(9) << "\n| ID" << std::setw(30) << "| Name" << std::setw(58) << "| Description" << "| Price |";
	tableSeperation();

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
	tableSeperation();
	std::cout << std::left << std::setw(9) << "\n| ID" << std::setw(30) << "| Name" << std::setw(58) << "| Description" << "| Price |";
	tableSeperation();

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

//Outputs speration line in console
void tableSeperation()
{
	std::cout << std::right;
	std::cout << "\n+" << std::setfill('-') << std::setw(104) << "+";
	std::cout << std::setfill(' ');
}