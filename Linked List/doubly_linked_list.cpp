// Doubly Linked List

#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* previous;
	Node* next;
};

void dll_create_from_array(Node**, int[], int);
int dll_count(Node*);
void dll_display(Node*);
void dll_insert(Node**, int, int);
int dll_delete(Node**, int);
void dll_reverse(Node**);

int main()
{
	char choice;	
	int menu_choice;
	int a[] = {1, 2, 3};
	int size = 3;
	Node *head = NULL;

	dll_create_from_array(&head, a, size);

	do
	{
		cout << "\nDisplay linked list program menu";
		cout << "\n1. Display";
		cout << "\n2. Count";
		cout << "\n3. Insert";
		cout << "\n4. Delete";
		cout << "\n5. Reverse";
		cout << endl;
		cout << "\nEnter you choice: ";
		cin >> menu_choice;

		switch(menu_choice)
		{
			case 1:
			
			if(dll_count(head) == 0) 	cout << "\nEmpty linked list";
			else dll_display(head);
			
			break;

			case 2:

			cout << "\nCount: " << dll_count(head);

			break;

			case 3:
			{
				int data, position;

				cout << "\nEnter element: ";
				cin >> data;
				cout << "\nEnter position: ";
				cin >> position;

				dll_insert(&head, data, position);

				break;
			}

			case 4:
			{
				int position;

				cout << "\nEnter position: ";
				cin >> position;

				if(position < 1 || position > dll_count(head))
					cout << "\nInvalid position";
				else
					cout << "\nDeleted element: " << dll_delete(&head, position);

				break;
			}

			case 5:

				dll_reverse(&head);

				break;

			default:

				cout << "\nIncorrect choice";
		}
		cout << "\nDo you want to continue: ";
		cin >> choice;
	} while(choice == 'y' || choice == 'Y');

	return 0;
}

void dll_create_from_array(Node **head, int a[], int size)
{
	if(size == 0)
	{
		cout << "\nArray is empty";
		return;
	}

	Node* element = new Node;
	element -> data = a[0];
	element -> next = NULL;
	element -> previous = NULL;

	*head = element;
	Node *tail = *head;

	if(size > 1)
	{
		int i = 1;

		while(i < size)
		{
			Node* next_element = new Node;
			next_element -> data = a[i++];
			next_element -> next = NULL;
			next_element -> previous = tail;
			tail -> next = next_element;
			tail = next_element;
		}
	}
}

void dll_display(Node *head)
{
	Node *traverser = head;

	cout << endl;

	while(traverser)
	{
		cout << " " << traverser -> data << " ";
		traverser = traverser -> next;
	}

	cout << endl;
}

// Function to count in dll
int dll_count(Node* head)
{
	int count = 0;
	Node *traverser = head;

	while(traverser)
	{
		++count;
		traverser = traverser -> next;
	}

	return count;
}

// Function to display in dll
void dll_insert(Node **head, int data, int position)
{
	if(position < 1 || position > dll_count(*head) + 1)
	{
		cout << "\nInvalid position";
		return;
	}

	Node *element = new Node;
	element -> data = data;
	element -> next = element -> previous = NULL;

	if(dll_count(*head) == 0)
	{
		*head = element;
		return;
	}

	int position_zi = position - 1;
	Node *traverser = *head;

	if(position_zi == 0)
	{
		element -> next = traverser;
		traverser -> previous = element;
		*head = element;

		return;
	}

	int counter = 1;

	while(counter++ < position_zi)
		traverser = traverser -> next;

	element -> next = traverser -> next;
	element -> previous = traverser;
	if(traverser -> next)	traverser -> next -> previous = element;
	traverser -> next = element;
}

int dll_delete(Node **head, int position)
{
	if(position < 1 || position > dll_count(*head))
	{
		cout << "\nInvalid position";
	
		return -1;
	}

	Node *traverser = *head;

	if(dll_count(*head) == 1)
	{
		int data = traverser -> data;
		*head = NULL;
		delete traverser;

		return data;
	}

	int position_zi = position - 1;

	if(position_zi == 0)
	{
		int data = traverser -> data;
		traverser -> next -> previous = NULL;
		*head = traverser -> next;
		delete traverser;

		return data;
	}

	int counter = 0;

	while(counter++ < position_zi)
		traverser = traverser -> next;

	int data = traverser -> data;
	traverser -> previous -> next = traverser -> next;
	if(traverser -> next) traverser -> next -> previous = traverser -> previous;
	delete traverser;

	return data;
}

void dll_reverse(Node **head)
{
	Node *traverser = *head;

	while(traverser)
	{
		Node *temp = traverser -> next;
		traverser -> next = traverser -> previous;
		traverser -> previous = temp;
		*head = traverser;
		traverser = traverser -> previous;			
	}
}
