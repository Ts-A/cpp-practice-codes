// Function to radix sort in c++

#include <iostream>
#include "Custom_Functions.h"

void radix_sort(int[], int);

int main()
{
	int *a, n;	

	inputElements(a, n);
	
	cout << "\nBefore Sorting:";
	
	display(a, n);
	radix_sort(a, n);
	
	cout << "\nAfter Sorting:";
	
	display(a, n);

	return 0;
}

void radix_sort(int a[], int n)
{

}
