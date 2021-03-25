// Function to merge sort in c++

#include <iostream>
#include "Custom_Functions.cpp"

void copy(int[], int[], int, int);
void merge(int[], int, int, int);
void merge_sort(int[], int);
// void merge_sort(int[], int, int);

int main()
{
	int *a, n;	
	inputElements(a, n);
	cout << "\nBefore Sorting:";
	display(a, n);
	merge_sort(a, n);
	cout << "\nAfter Sorting:";
	display(a, n);
	return 0;
}

void copy(int a[], int b[], int low, int high)
{
	while(low <= high)
	{
		a[low] = b[low];
		++low;
	}
}

void merge(int a[], int low, int mid, int high)
{
	int i = low, j = mid + 1, k = low, b[high + 1];

	while(i <= mid && j <= high)
	{
		if(a[i] < a[j])
			b[k++] = a[i++];
		else
			b[k++] = a[j++];
	}

	while(i <= mid)	b[k++] = a[i++];

	while(j <= high) b[k++] = a[j++];

	copy(a, b, low, high);
}

// Function to merge sort
void merge_sort(int a[], int n)
{
	int pass;

	for(pass = 2; pass <= n; pass *= 2) // pass taken as 1-index
	{
		for(int i = 0; i + pass - 1 < n; i += pass) // since pass as 1-index: pass - 1 
		{
			int low = i, high = i + pass - 1, mid = (low + high) / 2;
			merge(a, low, mid, high);
		}
	}

	if(pass / 2 < n) merge(a, 0, pass / 2 - 1, n - 1); // if n not in the power of 2 
}

// Recursive function to merge sort
// void merge_sort(int a[], int low, int high)
// {
// 	if(low < high)
// 	{
// 		int mid = (low + high) / 2;
// 		merge_sort(a, low, mid);
// 		merge_sort(a, mid + 1, high);
// 		merge(a, low, mid, high);
// 	}
// }