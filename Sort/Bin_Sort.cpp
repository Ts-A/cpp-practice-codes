// Bucket Sort in C++

#include <iostream>
#include "Custom_Functions.h"

struct Node
{
	int data;
	Node *next;
};

void Insert(Node**, int);
int Delete(Node**);
void bin_sort(int[], int);

int main()
{
	int *a, n;	

	inputElements(a, n);
	
	cout << "\nBefore Sorting:";
	
	display(a, n);
	bin_sort(a, n);
	
	cout << "\nAfter Sorting:";
	
	display(a, n);

	return 0;
}

void bin_sort(int a[], int n)
{
	Node **bins;
	int max = max_element(a, n);
	int i = 0, j = 0;

	bins = new Node*[max + 1];

	for(i = 0; i <= max; ++i)
		bins[i] = NULL;

	for(i = 0; i < n; ++i)
	{
		cout << bins[a[i]];
		Insert(&bins[a[i]], a[i]);
		cout << bins[a[i]];
	}

	i = 0;

	while(i <= max)
	{
		while(bins[i] != NULL)
		{
			a[j++] = Delete(&bins[i]);
		}
		++i;
	}
}

int Delete(Node **head)
{
	Node *temp = *head;

	cout << *head;

	if(*head == NULL)
		return 0;

	while(temp -> next -> next != NULL)
		temp = temp -> next;

	int data = temp -> next -> data;

	temp -> next = NULL;

	return data;
}

void Insert(Node **head, int data)
{
	cout << *head;
	Node *temp = *head, *element;
	element = new Node;
	element -> data = data;
	element -> next = NULL;	

	if(*head == NULL)
		*head = element;
	else
	{
		while(temp != NULL)
		{	
			cout << temp -> data;
			temp = temp -> next;
		}
		temp -> next = element;
	}

}
