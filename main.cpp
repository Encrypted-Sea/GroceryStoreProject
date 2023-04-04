#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include"item.h"

int main()
{	
	Item arrInventory[INVENTORY_SIZE] = {};	//Array to store up to 50 item objects
	int numItem;							//Will count number of items in inventory 
	
	numItem = populateArray(arrInventory);	//Populates array with data from list

	menuChoice(arrInventory, numItem);

	return 0;
}
