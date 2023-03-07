#include<iostream>
#include<fstream>
#include<string>

#ifndef ITEM_H
#define ITEM_H
const int INVENTORY_SIZE = 50; //Maximum capacity of items inventory/array can manage


//	-------------- Class Decloration --------------

class Item
{
	private:
		//Attributes of item (member variables)
		//Primitave data types to describe item
		
		int id;						//Unique numerical ID of an item
		double price;				//Price of an item (USD)
		std::string name;			//Name of an item
		std::string description;	//Brief description of an item

	public:
		//Accesors and mutators methods (member functions)
		//Retrieves or modifies value of attributes respectively
		
		void set_id(int);					//Mutator for ID
		int get_id();						//Accessor for ID

		void set_price(double);				//Mutator for price
		double get_price();					//Accessor for price

		void set_name(std::string);			//Mutator for name
		std::string get_name();				//Accessor for name

		void set_description(std::string);	//Mutator for description
		std::string get_description();		//Accessor for description

		//Constructor to initialize object with defualt values
		Item();
};

#endif
