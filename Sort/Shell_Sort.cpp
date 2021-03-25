// Shell Sort in C++

#include <iostream>
#include "Custom_Functions.h"

void shell_sort(int[], int);

int main()
{
	int *a, n;	

	inputElements(a, n);
	
	cout << "\nBefore Sorting:";
	
	display(a, n);
	shell_sort(a, n);
	
	cout << "\nAfter Sorting:";
	
	display(a, n);

	return 0;
}

void shell_sort(int a[], int n)
{
	int gap = n / 2;

	while(gap >= 1)
	{
		int j = gap;

		while(j <= n - 1)
		{
			int i = j - gap, k = j;

			while(i >= 0)
			{
				if(a[k] < a[i])
					swap(a[k], a[i]);
				k = i;
				i -= gap;
			}

			j += gap;
		}

		gap /= 2;
	}
}
