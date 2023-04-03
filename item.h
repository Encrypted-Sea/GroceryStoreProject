#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>

#ifndef ITEM_H
#define ITEM_H
const int INVENTORY_SIZE = 50; //Maximum capacity of items inventory/array can manage


//	============ Class Decloration ============

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

//	============ Function Declarations ============

//	------ Search & Sort Functions ------

//Overloaded Binary Searches Algorithms to find index of Item with identical key
int binarySearch(Item[], int, int);
int binarySearch(Item[], std::string, int);

//Quick Sort Algorithms that fully sort an Item array based on which variation is called
void quickSortId(Item[], int, int, bool&);
void quickSortName(Item[], int, int, bool&);
void quickSortPrice(Item[], int, int, bool&);

//Quick Sort Algorithms that do a single sorting pass of an Item array based on which variation is called
int partitionId(Item[], int, int);
int partitionName(Item[], int, int);
int partitionPrice(Item[], int, int);

//Algorithm that swaps the elements of an Item array based on the index values passed
void swapElements(Item[], int, int);

//	------- Populate & Output Functions -------

void menu();

//Reads data from inventory text file and populates Item array using the data while returning number of Items created
int populateArray(Item[]);

//Saves current state of array to text a file, presumably after sorting it
void saveSort(Item[], std::string, int);

//Overloaded data output functions to print contents of data structure (Item array or file)
void outputInventory(Item[], int);
void outputInventory(std::string, int);

//Used to create the horizontal lines seperating a table
void tableSeperation();

#endif
