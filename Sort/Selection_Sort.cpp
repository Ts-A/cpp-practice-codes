// Selection Sort using C++

#include <iostream>
#include "Custom_Functions.cpp"

using namespace std;

void selection_sort(int[], int);

int main()
{
	int *a, n;
	inputElements(a, n);
	cout << "\nBefore Sorting:";
	display(a, n);
	selection_sort(a, n);
	cout << "\nAfter Sorting:";
	display(a, n);
}

void selection_sort(int a[], int n)
{
	for(int pass = 0; pass < n - 1; ++pass)
	{
		int min_index = pass;
		for(int index = pass + 1; index < n; ++index)
			if(a[index] < a[min_index]) min_index = index;
		swap(a[pass], a[min_index]);
	}
}
