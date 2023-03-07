#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include"item.h"

int main()
{
	Item pineapple;
	Item arrInventory[INVENTORY_SIZE] = {};

	std::cout << std::showpoint << std::setprecision(2) << std::fixed; 

	//Code for printing object attributes does not look pretty
	//Try to see of you can replace all of the tabs with setwidth functions and so on
	
	//Prints default attributes of type item object "pineapple" immediately after initialization of object
	std::cout << "\n\t\tDefault Item Attributes of Instance Pineapple"
			<< "\n\nName: \t\t" << pineapple.get_name()
			<< "\nID: \t\t" << pineapple.get_id()
			<< "\nPrice: \t\t" << "$" << pineapple.get_price()
			<< "\nDescription: \t" << pineapple.get_description() << std::endl;

	//Test mutating attributes of type Item object "pineapple"
	pineapple.set_name("pineapple");
	pineapple.set_id(85963);
	pineapple.set_price(3.24);
	pineapple.set_description("A refrence to a dead song");

	//Prints new attributes of type item object "pineapple" immediately after initialization of object
	std::cout << "\n\t\tNew Item Attributes of Instance Pineapple"
		<< "\n\nName: \t\t" << pineapple.get_name()
		<< "\nID: \t\t" << pineapple.get_id()
		<< "\nPrice: \t\t" << "$" << pineapple.get_price()
		<< "\nDescription: \t" << pineapple.get_description() << std::endl;

	return 0;
}
