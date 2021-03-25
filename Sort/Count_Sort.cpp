// Function to count sort in c++

#include <iostream>
#include "Custom_Functions.h"

void count_sort(int[], int);

int main()
{
	int *a, n;	

	inputElements(a, n);
	
	cout << "\nBefore Sorting:";
	
	display(a, n);
	count_sort(a, n);
	
	cout << "\nAfter Sorting:";
	
	display(a, n);

	return 0;
}

void count_sort(int a[], int n)
{
	int i = 0, j = 0;
	int max = max_element(a, n);
	int *count = new int[max + 1];

	for(i = 0; i <= max; ++i)
		count[i] = 0;

	for(i = 0; i < n; ++i)
		++count[a[i]];

	i = 1;

	while(i <= max)
	{
		if(count[i] > 0)
		{
			a[j++] = i;
			--count[i];
		}
		else ++i;
	}
}
