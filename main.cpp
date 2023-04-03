#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include"item.h"

int main()
{	
	Item arrInventory[INVENTORY_SIZE] = {};	//Array to store up to 50 item objects
	int numItem;							//Will number of items in inventory 
	
	bool isIdSorted = false;
	bool isNameSorted = false;
	bool isPriceSorted = false;

	numItem = populateArray(arrInventory);	//Populates array with data from list

	//Outputs table data to console
	std::cout << "\n\t\t############## Item's within Inventory ##############" << std::endl;
	outputInventory(arrInventory, numItem);

	quickSortId(arrInventory, 0, (numItem - 1), isIdSorted);
	saveSort(arrInventory, "InventoryId.txt", numItem);

	std::cout << "\n\t\t############## Item's within Inventory ##############" << std::endl;
	outputInventory("InventoryId.txt", numItem);

	return 0;
}
