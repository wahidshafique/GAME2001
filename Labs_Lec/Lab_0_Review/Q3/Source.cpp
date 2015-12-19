//Write a function that swaps two pointers to point to each other’s values.Your
//function should work correctly for the following example invocation 
/* int x = 5, y = 6;
int ?ptr1 = &x, ?ptr2 = &y;
swap(&ptr1, &ptr2);
cout << ?ptr1 << ’ ’ << ?ptr2 << endl; Prints ”6 , 5”*/
#include <iostream>

using namespace std;

void mutualPointSwap(int **a, int **b) {
	int *temp = *b;
	*b = *a;
	*a = temp;
}

int main() {
	int a = 100;
	int b = 9;

	int *ptr1 = &a;
	int *ptr2 = &b;

	cout << "ptr1 = " << *ptr1 << ", ptr2 = " << *ptr2 << endl
		<< "swapped by using pointers that point to each others values: " << endl;
	mutualPointSwap(&ptr1, &ptr2);
	cout << "ptr1 = " << *ptr1 << ", ptr2 = " << *ptr2 << endl;
	return 0;
}