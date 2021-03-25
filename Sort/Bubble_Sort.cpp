// Bubble sort in c++

#include <iostream>
#include "Custom_Functions.cpp"

using namespace std;

void bubble_sort(int*, int);

int main() {
	int *a, n;
	inputElements(a, n);
	cout << "\nBefore Sorting:";
	display(a, n);
	bubble_sort(a, n);
	cout << "\nAfter Sorting:";
	display(a, n);
}

void bubble_sort(int *a, int n)
{
	for(int pass = 0; pass < n - 1; ++pass)
	{
		int flag = 0;
		for(int index = 0; index < n - 1 - pass; ++index)
		{
			if(a[index] > a[index + 1])
			{
				swap(a[index], a[index + 1]);
				++flag;
			}
		}
		if(!flag) return;
	}
}
