#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include"item.h"

int main()
{
	Item arrInventory[INVENTORY_SIZE] = {};
	int numItem;

	numItem = populateArray(arrInventory);

	std::cout << "\n\t\t############## New Item's within Inventory ##############" << std::endl;
	outputInventory(arrInventory, numItem);

	return 0;
}
