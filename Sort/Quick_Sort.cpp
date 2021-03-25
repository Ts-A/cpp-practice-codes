// Function to quick sort in c++

#include <iostream>
#include "Custom_Functions.cpp"

using namespace std;

int partitioner(int*, int, int);
void quick_sort(int*, int, int); 

int main()
{
	int *a, n;
	inputElements(a, n);
	cout << "\nBefore Sorting:";
	display(a, n);
	quick_sort(a, 0, n);
	cout << "\nAfter Sorting:";
	display(a, n);	
}

int partitioner(int *a, int low, int high)
{
	int pivot = a[low], i = low, j = high;

	do
	{
		do{++i;} while(a[i] <= pivot); // i >= n ?
		
		do{--j;} while(a[j] > pivot); // j <= -1 ? Not possible since j -> 0 => a[j] = pivot

		if(j > i) swap(a[i], a[j]); 
	
	}
	while(j > i);

	swap(a[j], a[low]);

	return j;
}

void quick_sort(int *a, int low, int high)
{
	if(low < high)
	{
		int j = partitioner(a, low, high);
		quick_sort(a, low, j);
		quick_sort(a, j + 1, high);	
	}
}
