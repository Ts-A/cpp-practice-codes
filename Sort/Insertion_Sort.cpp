// Insertion Sort in c++

#include <iostream>
#include "Custom_Functions.cpp"

using namespace std;

void insertion_Sort(int [], int);

int main()
{
	int *a, n;
	inputElements(a, n);
	cout << "\nBefore Sorting:";
	display(a, n);
	insertion_Sort(a, n);
	cout << "\nAfter Sorting:";
	display(a, n);
}

void insertion_Sort(int a[], int n)
{
	for(int pass = 1; pass < n; ++pass)
	{
		int index = pass - 1, temp = a[pass];
		while(index >= 0 && a[index] > temp)
		{
			a[index + 1] = a[index];
			--index;
		}
		a[index + 1] = temp;
	}
}
