// Custom functions in C++

#include <iostream>

using namespace std;

void display(int *a, int n)
{
	cout << endl;
	for(int i = 0; i < n; ++i)
	{
		cout << " " << a[i] << " ";
	}
	cout << endl;
}

void inputElements(int *a, int &size)
{
	cout << "Number of elements:";
	cin >> size;
	cout << "Elements:" << endl;
	for(int i = 0; i < size; ++i)
		cin >> a[i];
}


int max_element(int a[], int n)
{
	int max = a[0];

	for(int i = 1; i < n; ++i)
		if(a[i] > max)
			max = a[i];

	return max;
}	

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
