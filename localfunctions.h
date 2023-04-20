#include "item.h"

#ifndef SEARCH_H
#define SEARCH_H

//Overloaded Binary Searches Algorithms to find index of Item with identical key
int binarySearch(Item[], int, int);
int binarySearch(Item[], std::string, int);
#endif

#ifndef SORT_H
#define SORT_H

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
#endif

#ifndef POPULATE_H
#define POPULATE_H

//Displays menu options and performs selected operation from menu
void menuChoice(Item[], int);

//Overloaded, populates array with data read from a text file; one also returns amount of items in inventory
int populateArray(Item[]);
void populateArray(Item[], std::string, int);

//Saves current state of array to text a file, presumably after sorting it
void saveSort(Item[], std::string, int);
#endif

#ifndef OUTPUT_H
#define OUTPUT_H

void outputSearchResults(Item[], int);

//Overloaded data output functions to print contents of data structure (Item array or file)
void outputInventory(Item[], int);
void outputInventory(std::string, int);

//Makes it so that you need to press enter to continue; used so that user has time to process outputted data
void pressEnter(bool = false);

//Used to create the header of the table for Items; displays column names based on Item attributes
void tableHeader();

//Used to create the horizontal lines seperating of the table of Items
void tableSeperation();
#endif

#ifndef VALIDATION_H
#define	VALIDATION_H

//Overloaded, displays error message and what the user tried to search for if search is not valid
bool searchValid(int, int);
bool searchValid(int, std::string);

//Used to check if user inputted integer is valid
void numValid(int&);
#endif