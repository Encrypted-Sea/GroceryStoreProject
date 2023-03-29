#include"item.h"

//------------ Item Accessors and Mutators ------------

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

void quicksortId(Item arr[], int start, int end)
{
	//Will keep on executing as long as the 'subarray' contains more than 1 element thanks to recursion
	if (start < end)
	{
		int pIndex;								//Stores where the break point is in a partition during a pass
		pIndex = partitionId(arr, start, end);	//Partitions array and returns where the break point occurs


		//Constantly breaks array into 'subarrays' defined by the boundaries of new partitions

		quicksortId(arr, start, (pIndex - 1));	//Recursive call to sort low partition
		quicksortId(arr, (pIndex + 1), end);	//Recursive call to sort high partition
	}
}

void quicksortName(Item arr[], int start, int end)
{
	//Will keep on executing as long as the 'subarray' contains more than 1 element thanks to recursion
	if (start < end)
	{
		int pIndex;									//Stores where the break point is in a partition during a pass
		pIndex = partitionName(arr, start, end);	//Partitions array and returns where the break point occurs


		//Constantly breaks array into 'subarrays' defined by the boundaries of new partitions

		quicksortName(arr, start, (pIndex - 1));	//Recursive call to sort low partition
		quicksortName(arr, (pIndex + 1), end);		//Recursive call to sort high partition
	}
}

void quicksortPrice(Item arr[], int start, int end)
{
	//Will keep on executing as long as the 'subarray' contains more than 1 element thanks to recursion
	if (start < end)
	{
		int pIndex;								//Stores where the break point is in a partition during a pass
		pIndex = partitionPrice(arr, start, end);	//Partitions array and returns where the break point occurs


		//Constantly breaks array into 'subarrays' defined by the boundaries of new partitions

		quicksortPrice(arr, start, (pIndex - 1));	//Recursive call to sort low partition
		quicksortPrice(arr, (pIndex + 1), end);		//Recursive call to sort high partition
	}
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

//Outputs speration line in console
void tableSeperation()
{
	std::cout << std::right;
	std::cout << "\n+" << std::setfill('-') << std::setw(104) << "+";
	std::cout << std::setfill(' ');
}

