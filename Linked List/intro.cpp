// Linked List functions
// Maintain head and tail but use head mostly

#include <iostream>
#include <limits>

using namespace std;

struct Node
{
	int data;
	Node* next;
};

void ll_append(Node**, Node**, int);
void ll_create_from_array(Node**, Node**, int[], int);
int ll_count(Node*);
void ll_concatenate(Node **, Node **, Node **, Node**);
int ll_delete(Node**, Node**, int);
void ll_delete_duplicates(Node**, Node**);
void ll_display(Node*);
Node* ll_improved_linear_search(Node**, Node**, int);
bool ll_is_loop(Node *head);
bool ll_is_sorted(Node *head);
void ll_insert(Node **head, Node **tail, int, int);
Node* ll_linear_search(Node*, int);
int ll_max(Node*);
void ll_merge(Node**, Node**, Node**, Node**);
int ll_min(Node*);
void ll_sorted_insert(Node **head, Node **tail, int);
int ll_sum(Node*);
void ll_reverse(Node**, Node**);

int ll_rcount(Node*);
void ll_rdisplay(Node*);
Node* ll_rlinear_search(Node *head, int key);
int ll_rmax(Node*);
int ll_rmin(Node*);
int ll_rsum(Node*);
void ll_rreverse(Node**, Node**, Node*, Node*);

int main()
{
	char choice;
	int menu_choice;
	int array[] = {1, 2, 3, 4};
	Node* head = NULL, *tail = NULL;

	ll_create_from_array(&head, &tail, array, 4);

	cout << "\nLinked List";	

	do
	{
		cout << "\nMENU:";
		cout << "\n1. Display linked list";
		cout << "\n2. Count nodes in linked list";
		cout << "\n3. Sum of nodes in linked list";
		cout << "\n4. Maximum node in linked list";	
		cout << "\n5. Minimum node in linked list";
		cout << "\n6. Linear search in linked list";
		cout << "\n7. Improved linear search in linked list";
		cout << "\n8. Insert an element in linked list";
		cout << "\n9. Append an element in linked list";
		cout << "\n10. Insert an element in sorted linked list";
		cout << "\n11. Delete a node in linked list";
		cout << "\n12. Check if the linked list is sorted in increasing order";
		cout << "\n13. Delete duplicates in sorted linked list";
		cout << "\n14. Reverse the linked list";
		cout << "\n15. Concatenate two linked lists";
		cout << "\n16. Merge two linked lists";
		cout << "\n17. Check if LOOP";
		cout << endl;
		cout << "\nChoice: ";
		cin >> menu_choice;

		switch(menu_choice)
		{
			int data, key, position;

			case 1: 

				if(!head) cout << "\nEmpty linked list";
				cout << "\nIteration:";
				ll_display(head);
				cout << "\nRecursion:" << endl;
				ll_rdisplay(head);

				break;

			case 2: 

				cout << "\nIteration Count: " << ll_count(head) << "\nRecusrion Count: " << ll_rcount(head);

				break;
			case 3: 

				cout << "\nIteration Sum: " << ll_sum(head) << "\nRecusrion Sum: " << ll_rsum(head);

				break;
			case 4:

				if(!ll_count(head))	cout << "\nEmpty linked list";
				else	cout << "\nIteration Max: " << ll_max(head) << "\nRecusrion Max: " << ll_rmax(head);

				break;
			case 5:

				if(!ll_count(head))	cout << "\nEmpty linked list";
				else	cout << "\nIteration Min: " << ll_min(head) << "\nRecusrion Min: " << ll_rmin(head);

				break;

			case 6:

				if(!ll_count(head))
					cout << "\nEmpty linked list";
				else
				{
				cout << "\nEnter the key to search: ";
				cin >> key;

				Node* node_ptr = ll_rlinear_search(head, key);

				if(!node_ptr) cout << "\nNot found";
				else cout << "\nFound at " << node_ptr;
				}
				break;

			case 7:

				if(!ll_count(head))
					cout << "\nEmpty linked list";
				else
				{
					cout << "\nEnter the key to search: ";
					cin >> key;

					Node* node_ptr = ll_improved_linear_search(&head, &tail, key);

					if(!node_ptr) cout << "\nNot found";
					else cout << "\nFound at " << node_ptr;
				}
				break;

			case 8:

				cout << "\nEnter integer data: ";
				cin >> data;
				cout << "\nEnter 1-index position: ";
				cin >> position;

				ll_insert(&head, &tail, data, position);

				break;

			case 9:

				cout << "\nEnter integer data:";
				cin >> data;

				ll_append(&head, &tail, data);

				break;

			case 10:
			
				cout << "\nEnter integer data:";
				cin >> data;

				ll_sorted_insert(&head, &tail, data);

				break;	

			case 11:
		
				cout << "\nEnter the position:";
				cin >> position;

				if(position < 1 && position > ll_count(head)) cout << "\nInvalid Position";

				cout << "\nDeleted node: " << ll_delete(&head, &tail, position);

				break;

			case 12:

				cout << "\nThe linked list is ";
				ll_is_sorted(head) ? cout << "sorted" : cout << "not sorted";

				break;

			case 13:

				ll_delete_duplicates(&head, &tail);

				cout << "\nDuplicates are removed.";

				break;

			case 14:

				ll_rreverse(&head, &tail, head, NULL);

				break;

			case 15:
			{
				Node *front = NULL, *rear = NULL;
				int size;

				cout << "\nEnter the size of the second linked list: ";
				cin >> size;

				int a[size];

				cout << "\nEnter the elements of the linked list" << endl;

				for(int i = 0; i < size; ++i)
					cin >> a[i];

				ll_create_from_array(&front, &rear, a, size);
				ll_concatenate(&head, &tail, &front, &rear);

				break;
			}

			case 16:
			{
				Node *front = NULL, *rear = NULL;
				int size;

				cout << "\nEnter the size of the second linked list: ";
				cin >> size;

				int a[size];

				cout << "\nEnter the elements of the linked list" << endl;

				for(int i = 0; i < size; ++i)
					cin >> a[i];

				ll_create_from_array(&front, &rear, a, size);
				ll_merge(&head, &tail, &front, &rear);

				break;
			}

			case 17:

				cout << "\nThe given linked list is ";
				ll_is_loop(head) ? cout << "in LOOP" : cout << "not in LOOP"; 

			break;

			default: cout << "\nIncorrect choice.";
		}

		cout << "\nTo use menu enter \'y\': ";
		cin >> choice;
	} while(choice == 'y' || choice == 'Y');
}

void ll_create_from_array(Node **head, Node **tail, int a[], int size)
{
	if(size == 0)
	{
		cout << "\nArray is empty";
		return;
	}

	Node* element = new Node;
	element -> data = a[0];
	element -> next = NULL;

	*head = *tail = element;

	if(size > 1)
	{
		int i = 1;

		while(i < size)
		{
			Node* next_element = new Node;
			next_element -> data = a[i++];
			next_element -> next = NULL;
			(*tail) -> next = next_element;
			*tail = next_element;
		}
	}
}

// Function to count in ll
int ll_count(Node* head)
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

// Recursive function to count in ll
int ll_rcount(Node* head)
{
	Node *traverser = head;

	if(traverser) return 1 + ll_rcount(traverser -> next);
	else return 0;
}

int ll_sum(Node *head)
{
	Node *traverser = head;
	int sum = 0;

	while(traverser)
	{
		sum += traverser -> data;
		traverser = traverser -> next;
	}

	return sum;
}

int ll_rsum(Node *head)
{
	Node *traverser = head;

	if(traverser) return traverser -> data + ll_rsum(traverser -> next);
	else return 0;
}

// Function to display ll
void ll_display(Node* head)
{
	Node* traverser = head;

	cout << endl;
	while(traverser)
	{
		cout << " " << traverser -> data << " ";
		traverser = traverser -> next;
	}
	cout << endl;
}

// Recursive function to display ll
void ll_rdisplay(Node* head)
{
	Node* traverser = head;

	if(traverser)
	{
		cout << " "  << traverser -> data << " ";
		ll_rdisplay(traverser -> next);
	}
}

int ll_max(Node *head)
{
	if(!head) return INT32_MIN;

	int max = head -> data;

	Node *traverser = head;

	while(traverser)
	{
		if(traverser -> data > max)
			max = traverser -> data;
		traverser = traverser -> next;
	}

	return max;
}

int ll_rmax(Node *head)
{
	Node *traverser = head;

	if(traverser)
	{
		int current_max = ll_rmax(traverser -> next);
		if(current_max > traverser -> data) return current_max;
		else return traverser -> data;
	}

	return INT32_MIN;
}

int ll_min(Node *head)
{
	if(!head) return INT32_MAX;

	int min = head -> data;

	Node *traverser = head;

	while(traverser)
	{
		if(traverser -> data < min)
			min = traverser -> data;
		traverser = traverser -> next;
	}

	return min;
}

int ll_rmin(Node *head)
{
	Node *traverser = head;

	if(traverser)
	{
		int current_min = ll_rmin(traverser -> next);
		if(current_min < traverser -> data) return current_min;
		else return traverser -> data;
	}

	return INT32_MAX;
}

Node* ll_linear_search(Node *head, int key)
{
	Node *traverser = head;

	while(traverser)
	{
		if(key == traverser -> data) return traverser; 
		traverser = traverser -> next;
	}

	return NULL;
}

Node* ll_rlinear_search(Node *head, int key)
{
	Node *traverser = head;

	if(traverser)
	{
		if(key == traverser -> data)
			return traverser;
		return ll_rlinear_search(traverser -> next, key);
	}

	return NULL;	
}

Node* ll_improved_linear_search(Node **head, Node **tail, int key)
{
	Node *traverser = *head, *penultimate_traverser = NULL;
	bool first_position = true;

	while(traverser)
	{
		if(key == traverser -> data)
		{
			if(first_position) return traverser;
			penultimate_traverser -> next = traverser -> next;
			traverser -> next = *head;
			*head = traverser;
			if(!penultimate_traverser -> next) *tail = penultimate_traverser; 
			return traverser;
		}
		first_position = false;
		penultimate_traverser = traverser;
		traverser = traverser -> next;
	}

	return NULL;	
}

void ll_insert(Node **head, Node **tail, int data, int position)
{
	int position_zi = position - 1; // From 1-index to 0-index
	if(position_zi < 0 || position_zi > ll_count(*head)) 
	{
		cout << "\nPosition out of bounds.";
		return;
	}

	Node *element = new Node;
	element -> data = data;
	element -> next = NULL;

	if(position_zi == 0)
	{
		element -> next = *head;
		*head = element;
		return;
	}

	Node *traverser = *head;

	int counter = 0;

	while(traverser && ++counter < position_zi)
		traverser = traverser -> next;

	element -> next = traverser -> next;
	traverser -> next = element;

	if(counter == ll_count(*head) + 1) *tail = element;
}

void ll_append(Node **head, Node **tail, int data)
{
	Node *element = new Node;
	element -> data = data;
	element -> next = NULL;

	if(*head == NULL)
		*head = *tail = element;
	else
	{
		(*tail)->next = element;
		*tail = element;
	}
}

void ll_sorted_insert(Node **head, Node **tail, int data)
{
	Node *traverser = *head, *penultimate_traverser = NULL, *element = new Node;
	element -> data = data;
	element -> next = NULL;

	while(traverser && traverser -> data < data)
	{
		penultimate_traverser = traverser;
		traverser = traverser -> next;
	}

	traverser == *head ? *head = element : penultimate_traverser -> next = element;
	element -> next = traverser;
	if(!traverser) *tail = element;
}

int ll_delete(Node **head, Node **tail, int position)
{
	int position_zi = position - 1;
	if(position_zi < 0 && position_zi >= ll_count(*head))
	{
		cout << "\nInvalid Position";
		return -1;
	}

	Node *traverser = *head;
	int data;

	if(position_zi == 0)
	{
		*head = traverser -> next;
		data = traverser -> data;
		delete traverser;
		return data;
	}

	int counter = 0;

	Node *penultimate_traverser = traverser;
	traverser = traverser -> next;

	while(traverser && ++counter < position_zi)
	{
		penultimate_traverser = traverser;
		traverser = traverser -> next;
	}

	penultimate_traverser -> next = traverser -> next;
	if(!penultimate_traverser -> next) *tail = penultimate_traverser;
	data = traverser -> data;
	delete traverser;

	return data;
}

bool ll_is_sorted(Node *head)
{
	Node *traverser = head;
	int data = INT32_MIN;

	while(traverser)
	{
		if(traverser -> data < data)
			return false;
		
		data = traverser -> data;
		traverser = traverser -> next;
	}

	return true;
}

void ll_delete_duplicates(Node **head, Node **tail)
{
	Node *traverser = *head, *penultimate_traverser = NULL;

	if(!traverser || !traverser -> next) return;

	penultimate_traverser = traverser;
	traverser = traverser -> next;

	while(traverser)
	{
		if(traverser -> data == penultimate_traverser -> data)
		{
			penultimate_traverser -> next = traverser -> next;
			delete traverser;
			traverser = penultimate_traverser -> next;
		}
		else
		{
			penultimate_traverser = traverser;
			traverser = traverser -> next;
		}
	}
}

/* Reverse the elements (Poor choice)
void ll_reverse(Node *head)
{
	Node *traverser = head;
	int a[ll_count(head)], i = 0;
	while(traverser)
	{
		a[i++] = traverser -> data;
		traverser = traverser -> next;
	}
	traverser = head;
	while(traverser)
	{
		traverser -> data = a[--i];
		traverser = traverser -> next;
	}
}
*/

// Reverse the links using sliding pointers
void ll_reverse(Node **head, Node **tail)
{
	if(ll_count(*head) == 1) return;

	Node *traverser = *head, *penultimate_traverser = NULL, *pre_penultimate_traverser = NULL;

	while(traverser)
	{
		pre_penultimate_traverser = penultimate_traverser;
		penultimate_traverser = traverser;
		traverser = traverser -> next;
		penultimate_traverser -> next = pre_penultimate_traverser;		
	}

	traverser = *head;
	*head = *tail;
	*tail = traverser;
}

// Reverse linked list using recursion
void ll_rreverse(Node **head, Node **tail, Node *p, Node *q)
{
	if(p)
	{
		ll_rreverse(head, tail, p -> next, p);
		p -> next = q;
	}
	
	if(!p)	*head = q;

	if(!q)	*tail = p;
}	

void ll_concatenate(Node **head1, Node **tail1, Node **head2, Node **tail2)
{
	//Without considering tail
	Node *traverser = *head1;

	while(traverser -> next)
		traverser = traverser -> next;

	traverser -> next = *head2;

	while(traverser -> next)
		traverser = traverser -> next;

	*tail1 = traverser;
	*head2 = NULL;

	// Considering head, tail
	// *tail1 -> next = *head1;
	// *tail1 = *tail2;
	// *head2 = *tail2 = NULL;
}

void ll_merge(Node **head1, Node **tail1, Node **head2, Node **tail2)
{
	Node *traverser1 = *head1, *traverser2 = *head2, *penultimate_traverser = NULL, *head = NULL;

	if(traverser1 -> data < traverser2 -> data)
	{
		penultimate_traverser = traverser1;
		traverser1 = traverser1 -> next;
	}
	else
	{
		*head1 = traverser2;
		penultimate_traverser = traverser2;
		traverser2 = traverser2 -> next;
	}

	while(traverser1 && traverser2)
	{
		if(traverser1 -> data < traverser2 -> data)
		{
			penultimate_traverser -> next = traverser1;
			penultimate_traverser = traverser1;
			traverser1 = traverser1 -> next;
			penultimate_traverser -> next = NULL;	 	
		}
		else
		{
			penultimate_traverser -> next = traverser2;
			penultimate_traverser = traverser2;
			traverser2 = traverser2 -> next;
			penultimate_traverser -> next = NULL;	 	
		}
	}

	if(!traverser1)
	{
		penultimate_traverser -> next = traverser2;
		*tail1 = *tail2;
	}
	else
		penultimate_traverser -> next = traverser1;

	*head2 = *tail2 = NULL;
}

bool ll_is_loop(Node *head)
{
	Node *traverser_v1 = head, *traverser_v2 = head;

	while(traverser_v2)
	{
		traverser_v1 = traverser_v1 -> next;
		traverser_v2 = traverser_v2 -> next;
		traverser_v2 = traverser_v2 ? traverser_v2 -> next : NULL;

		if(traverser_v1 == traverser_v2) return true;		
	}

	return false;
}