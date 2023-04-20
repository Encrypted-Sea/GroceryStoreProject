#include "item.h"
#include "localfunctions.h"

//Sorts Item array in ascending order of Id number
void quickSortId(Item arrInventory[], int start, int end, bool& isSorted)
{
	//Will keep on executing as long as the 'subarray' contains more than 1 element thanks to recursion
	if (start < end)
	{
		int pIndex;										//Stores where the break point is in a partition during a pass
		pIndex = partitionId(arrInventory, start, end);	//Partitions array and returns where the break point occurs

		//Constantly breaks array into 'subarrays' defined by the boundaries of new partitions

		quickSortId(arrInventory, start, (pIndex - 1), isSorted);	//Recursive call to sort low partition
		quickSortId(arrInventory, (pIndex + 1), end, isSorted);		//Recursive call to sort high partition
	}

	isSorted = true;
}

//Sorts Item array in ascending order of name 
void quickSortName(Item arrInventory[], int start, int end, bool& isSorted)
{
	//Will keep on executing as long as the 'subarray' contains more than 1 element thanks to recursion
	if (start < end)
	{
		int pIndex;											//Stores where the break point is in a partition during a pass
		pIndex = partitionName(arrInventory, start, end);	//Partitions array and returns where the break point occurs


		//Constantly breaks array into 'subarrays' defined by the boundaries of new partitions

		quickSortName(arrInventory, start, (pIndex - 1), isSorted);	//Recursive call to sort low partition
		quickSortName(arrInventory, (pIndex + 1), end, isSorted);	//Recursive call to sort high partition
	}

	isSorted = true;
}

//Sorts Item array in ascending order of price 
void quickSortPrice(Item arrInventory[], int start, int end, bool& isSorted)
{
	//Will keep on executing as long as the 'subarray' contains more than 1 element thanks to recursion
	if (start < end)
	{
		int pIndex;											//Stores where the break point is in a partition during a pass
		pIndex = partitionPrice(arrInventory, start, end);	//Partitions array and returns where the break point occurs


		//Constantly breaks array into 'subarrays' defined by the boundaries of new partitions

		quickSortPrice(arrInventory, start, (pIndex - 1), isSorted);	//Recursive call to sort low partition
		quickSortPrice(arrInventory, (pIndex + 1), end, isSorted);		//Recursive call to sort high partition
	}

	isSorted = true;
}

//Partitions the array by Item Id
int partitionId(Item arrInventory[], int start, int end)
{
	int pivot = arrInventory[end].get_id();	//Sets the value of pivot to the value of the ending index of the partition
	int pIndex = start;						//Used to mark where the break between the high and low partitions is

	//Loops through the current partition of the array
	for (int i = start; i < end; i++)
	{
		//Part of the low partition
		//If the element at pIndex is less than the pivot, swap values of element at index i with index pIndex
		if (arrInventory[i].get_id() < pivot)
		{
			swapElements(arrInventory, i, pIndex);
			pIndex++;
		}
	}

	swapElements(arrInventory, pIndex, end); //Swaps pivit with pIndex after a pass has be done
	return pIndex;                           //Returns where the break between the high and low partitions is
}

//Partitions the array by Item name
int partitionName(Item arrInventory[], int start, int end)
{
	std::string pivot = arrInventory[end].get_name();	//Sets the value of pivot to the value of the ending index of the partition
	int pIndex = start;									//Used to mark where the break between the high and low partitions is

	//Loops through the current iteration of the current partition
	for (int i = start; i < end; i++)
	{
		//Part of the low partition
		//If the element at pIndex is less than the pivot, swap values of element at index i with index pIndex
		if (arrInventory[i].get_name() < pivot)
		{
			swapElements(arrInventory, i, pIndex);
			pIndex++;
		}
	}
	swapElements(arrInventory, pIndex, end); //Swaps pivit with pIndex after a pass has be done
	return pIndex;                           //Returns where the break between the high and low partitions is
}

//Partitions the array by Item price
int partitionPrice(Item arrInventory[], int start, int end)
{
	double pivot = arrInventory[end].get_price();	//Sets the value of pivot to the value of the ending index of the partition
	int pIndex = start;								//Used to mark where the break between the high and low partitions is

	//Loops through the current iteration of the current partition
	for (int i = start; i < end; i++)
	{
		//Part of the low partition
		//If the element at pIndex is less than the pivot, swap values of element at index i with index pIndex
		if (arrInventory[i].get_price() < pivot)
		{
			swapElements(arrInventory, i, pIndex);
			pIndex++;
		}
	}
	swapElements(arrInventory, pIndex, end); //Swaps pivit with pIndex after a pass has be done
	return pIndex;                           //Returns where the break between the high and low partitions is
}

//Swaps positions of two elements of type Item given their indexes
void swapElements(Item arrInvetory[], int a, int b)
{
	Item temp;

	temp = arrInvetory[a];
	arrInvetory[a] = arrInvetory[b];
	arrInvetory[b] = temp;

}