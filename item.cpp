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

int populateArray(Item arrInventory[])
{
	std::ifstream inventory;
	inventory.open("InventoryList.txt");

	//Will temporarily hold values pertaining to corresponding members
	int tempID;
	std::string tempName;
	std::string tempDescription;
	double tempPrice;

	int tick = 0;
	while (!inventory.eof() && tick < INVENTORY_SIZE)
	{
		inventory >> tempID;
		arrInventory[tick].set_id(tempID);

		//Only need to do .ignore() when you are doing a getline immediately after a extraction in the same stream
		inventory.ignore();
		std::getline(inventory, tempName);
		arrInventory[tick].set_name(tempName);

		std::getline(inventory, tempDescription);
		arrInventory[tick].set_description(tempDescription);

		inventory >> tempPrice;
		arrInventory[tick].set_price(tempPrice);

		tick++;
	}

	inventory.close();
	return tick;
}

void outputInventory(Item arrInventory[], int numItem)
{
	for (int i = 0; i < numItem; i++)
	{
		std::cout << "\nItem " << (i + 1) << "\n__________________________";
		std::cout << "\nID: " << arrInventory[i].get_id()
			<< "\nName: " << arrInventory[i].get_name()
			<< "\nDescription: " << arrInventory[i].get_description()
			<< "\nPrice: " << arrInventory[i].get_price() << std::endl;
	}
}