#include "item.h"
#include "localfunctions.h"
//Returns index of item with Id identical to search key
int binarySearch(Item arrInventory[], int key, int SIZE)
{
	int start = 0;		//Will store starting index of array partitions
	int end = SIZE - 1;	//Will store ending index of array partitions
	int mid;			//Will store middle index of array partitions
	int midValue;		//Will store ID of middle index

	//While starting index is less than or equal to ending boundary
	while (start <= end)
	{
		//Calculates middle index and its value
		mid = (start + end) / 2;
		midValue = arrInventory[mid].get_id();

		if (key < midValue)
		{
			end = mid - 1;
		}

		else if (key > midValue)
		{
			start = mid + 1;
		}

		else //Only executes if item with identical key is found
		{
			return mid;
		}
	}

	return -1;	//Signifies that no results were found
}

//Returns index of item with name identical to search key
int binarySearch(Item arrInventory[], std::string key, int SIZE)
{
	int start = 0;			//Will store starting index of array partitions
	int end = SIZE - 1;		//Will store ending index of array partitions
	int mid;				//Will store middle index of array partitions
	std::string midValue;	//Will store name of middle index

	//While starting index is less than or equal to ending boundary
	while (start <= end)
	{
		//Calculates middle index of current partition and its value
		mid = (start + end) / 2;
		midValue = arrInventory[mid].get_name();

		if (key < midValue)
		{
			end = mid - 1;
		}

		else if (key > midValue)
		{
			start = mid + 1;
		}

		else //Only executes if item with identical Id is found
		{
			return mid;
		}
	}

	return -1;	//Signifies that no results were found
}