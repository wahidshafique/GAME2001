#include <iostream>

using namespace std;

void revArr(int arr[], int size) {
	int temp;
	for (int i(0); i < size / 2; ++i) {
		temp = arr[i];
		arr[i] = arr[size - i - 1];
		arr[size - i - 1] = temp;
	}
}

void printArray(int *arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
		if (i != size - 1)
			cout << ", ";
	}
}

int main() {
	const int size(6);
	int arr[size] = { 1,2,3,4,5,6 };
	printArray(arr, size);
	revArr(arr, size);
	printArray(arr, size);
	return 0;
}