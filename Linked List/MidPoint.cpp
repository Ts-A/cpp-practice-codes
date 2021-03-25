// Find the middle node in a linked list

#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* next;
};

void ll_create_from_array(Node**, int[], int);
int midpoint(Node*);

int main()
{
	int a[] = {1, 2, 3, 4};
	Node *head = NULL;
	ll_create_from_array(&head, a, 4);
	cout << midpoint(head) << endl;
	return 0;
}

void ll_create_from_array(Node **head, int a[], int size)
{
	if(size == 0)
	{
		cout << "\nArray is empty";
		return;
	}

	Node *tail = NULL, *element = new Node;
	element -> data = a[0];
	element -> next = NULL;

	*head = tail = element;

	if(size > 1)
	{
		int i = 1;

		while(i < size)
		{
			Node* next_element = new Node;
			next_element -> data = a[i++];
			next_element -> next = NULL;
			tail -> next = next_element;
			tail = next_element;
		}
	}
}

int midpoint(Node *head)
{
	if(!head) return -1;

	Node *v1 = head, *v2 = head;

	while(v2)
	{
		v2 = v2 -> next;
		if(v2) v2 = v2 -> next;
		else break;
		v1 = v1 -> next;
	}

	return v1 -> data;
}
