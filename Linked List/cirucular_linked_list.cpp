// Circular linked list

#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* next;
};

void cll_create_from_array(Node**, int[], int);
int cll_count(Node*);
void cll_display(Node*);
void cll_insert(Node**, int, int);
int cll_delete(Node**, int);

void cll_rdisplay(Node*, Node*);

int main()
{
	char choice;	
	int menu_choice;
	int a[] = {1, 2, 3};
	int size = 3;
	Node *head = NULL;

	cll_create_from_array(&head, a, size);

	do
	{

		cout << "\nCircular linked list program menu";
		cout << "\n1. Display";
		cout << "\n2. Count";
		cout << "\n3. Insert";
		cout << "\n4. Delete";
		cout << endl;
		cout << "\nEnter you choice: ";
		cin >> menu_choice;

		switch(menu_choice)
		{
			case 1:
			
			cout << "\nIteration";
			cll_display(head);
			
			cout << "\nRecursion" << endl;
			cll_rdisplay(head, head);
			cout << endl;

			break;

			case 2:

			cout << "\nCount: " << cll_count(head);

			break;

			case 3:
			{
				int data, position;

				cout << "\nEnter element: ";
				cin >> data;
				cout << "\nEnter position: ";
				cin >> position;

				cll_insert(&head, data, position);

				break;
			}

			case 4:
			{
				int position;

				cout << "\nEnter position: ";
				cin >> position;

				if(position < 1 || position > cll_count(head))
					cout << "\nInvalid position";
				else
					cout << "\nDeleted element: " << cll_delete(&head, position);

				break;
			}
			default:

				cout << "\nIncorrect choice";
		}
		cout << "\nDo you want to continue: ";
		cin >> choice;
	} while(choice == 'y' || choice == 'Y');
}

void cll_create_from_array(Node **head, int a[], int size)
{
	if(size == 0)
	{
		cout << "\nArray is empty";
		return;
	}

	Node* element = new Node;
	element -> data = a[0];
	element -> next = element;

	*head = element;
	Node *tail = *head;

	if(size > 1)
	{
		int i = 1;

		while(i < size)
		{
			Node* next_element = new Node;
			next_element -> data = a[i++];
			next_element -> next = *head;
			tail -> next = next_element;
			tail = next_element;
		}
	}
}

// Function to display circular linked list
void cll_display(Node *head)
{
	Node *traverser = head;
	cout << endl;

	if(!head)
	{
		cout << "\nEmpty linked list";
		return;
	}

	do
	{
		cout << " " << traverser -> data << " ";
		traverser = traverser -> next;
	} while(traverser != head);

	cout << endl;
}

// Recursive function to display circular linked list
void cll_rdisplay(Node *head, Node *traverser)
{
	if(!head)
	{
		cout << "\nEmpty";
		return;
	}

	static bool first_time = true;

	if(traverser != head || first_time)
	{
		first_time = false;
		cout << " " << traverser -> data << " ";
		cll_rdisplay(head, traverser -> next);
	}

	first_time = true;
}

int cll_count(Node *head)
{

	if(!head) return 0;

	Node *traverser = head;
	int count = 0;

	do
	{
		++count;
		traverser = traverser -> next;
	} while(traverser != head);

	return count;
}

void cll_insert(Node **head, int data, int position)
{
	if(position < 1 || position > cll_count(*head) + 1)
	{
		cout << "\nInvalid position";
		return;
	}

	Node *element = new Node;
	element -> data = data;
	element -> next = NULL;

	if(cll_count(*head) == 0)
	{
		*head = element;
		element -> next = *head;
		return;
	}

	Node *traverser = *head;

	int position_zi = position - 1;
	if(position_zi == 0) position_zi = cll_count(*head);
	
	int counter = 1;	

	while(counter++ < position_zi)
		traverser = traverser -> next;

	element -> next = traverser -> next;
	traverser -> next = element;
}

// TODO: When everything is deleted
int cll_delete(Node **head, int position)
{
	if(position < 1 || position > cll_count(*head))
	{
		cout << "\nInvalid position";
		return -1;
	}

	int position_zi = position - 1;
	Node *traverser = *head;

	if(position_zi == 0)
	{
		int data = traverser -> data;

		if(cll_count(*head) == 1)
		{
			*head = NULL;
			delete traverser;

			return data;
		}

		Node *tail = *head;

		do
		{
			tail = tail -> next;
		} while(tail -> next != *head);

		*head = traverser -> next;
		tail -> next = *head;
		delete traverser;

		return data;
	}

	int counter = 1;
	Node *target = NULL;

	while(counter++ < position_zi)
		traverser = traverser -> next;

	target = traverser -> next;
	traverser -> next = target -> next;

	int data = target -> data;
	delete target;

	return data;
}
