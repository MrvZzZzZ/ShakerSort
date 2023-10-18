#include "Sort.h"

void ShakerSort(int* array, int size)
{
	bool isSwap = false;
	int rightBoarder = size - 1, leftBoarder = 0;
	
	do 
	{
		for (int i = leftBoarder; i < rightBoarder; i++)
		{
			if (array[i] > array[i + 1]) 
			{
				swap(array[i], array[i + 1]);
				isSwap = true;
			}
		}

		rightBoarder--;

		if (isSwap == true)
		{
			continue;
		}

		for (int i = rightBoarder; i > leftBoarder; i--) 
		{
			if (array[i] < array[i - 1]) 
			{
				swap(array[i], array[i - 1]);
			}
		}
		
		leftBoarder++;
	}
	while (leftBoarder < rightBoarder);

	for (int i = 0; i < size; i++) 
	{
		cout << array[i] << " ";
	}

	cout << endl;
}