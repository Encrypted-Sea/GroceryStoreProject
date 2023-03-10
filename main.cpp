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

	std::cout << "\n\t\t-------------- New Item's within Inventory --------------" << std::endl;
	for (int i = 0; i < numItem; i++)
	{
		std::cout << "\nItem " << (i + 1) << "\n__________________________";
		std::cout << "\nID: " << arrInventory[i].get_id()
				<< "\nName: " << arrInventory[i].get_name()
				<< "\nDescription: " << arrInventory[i].get_description()
				<< "\nPrice: " << arrInventory[i].get_price() << std::endl;
	}

	return 0;
}
