#include <iostream>

using namespace std;

void ShakerSort(int* array, int size) {
	int right = size - 1, left = 0;
	do {
		for (int i = left; i < right; i++) {
			if (array[i] > array[i + 1]) {
				swap(array[i], array[i + 1]);
			}
		}
		right--;
		for (int i = right; i > left; i--) {
			if (array[i] < array[i - 1]) {
				swap(array[i], array[i - 1]);
			}
		}
		left++;
	} while (left < right);

	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}