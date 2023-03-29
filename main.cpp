#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include"item.h"

int main()
{	
	Item arrInventory[INVENTORY_SIZE] = {};	//Array to store up to 50 item objects
	int numItem;							//Will number of items in inventory 

	numItem = populateArray(arrInventory);	//Populates array with data from list

	//Outputs table data to console
	std::cout << "\n\t\t############## Item's within Inventory ##############" << std::endl;
	outputInventory(arrInventory, numItem);

	quicksortPrice(arrInventory, 0, (numItem - 1));

	std::cout << "\n\t\t############## Item's within Inventory ##############" << std::endl;
	outputInventory(arrInventory, numItem);

	return 0;
}
