1. Create a Circular linked list. 
2. Insert an element at the start of the Circular linked list. 
3. Insert an element at the end of the Circular linked list.
4. Delete an element at the start of the Circular linked list
5. Delete an element at the end of the Circular linked list
6. WAP to reverse a  circular Linked List. 

//Q1
  
  #include<iostream>
using namespace std;

 class Node
  {
    public :
    int data;
    Node *next;
  };

void push(Node **head_ref,int data)
{
Node *ptr1=new Node();
Node *temp=*head_ref;
ptr1->data=data;
ptr1->next=*head_ref;

if(*head_ref!=NULL)
{
    while(temp->next!=*head_ref)
    temp=temp->next;
    temp->next=ptr1;
}
else
ptr1->next=ptr1;

*head_ref=ptr1;
}
void Display(Node *head)
{
   Node *temp=head;
 if (head != NULL)
{
  do
  {
  cout << temp->data << " ";
  temp = temp->next;
  }
 while (temp != head);
  }
}
int main()
{
    Node *head=NULL;
    push(&head,50);
    push(&head,40);
    push(&head,30);
    push(&head,20);
    push(&head,10);
cout<<"Circular link list is :"<<endl;
Display(head);
    return 0;
}
  
Q2 :

#include<bits/stdc++.h>
using namespace std;
 
struct Node
{
    int data;
    struct Node *next;
};
struct Node *addToEmpty(struct Node *last, int data)
{
    // This function is only for empty list
    if (last != NULL)
      return last;
 
    // Creating a node dynamically.
    struct Node *temp =
           (struct Node*)malloc(sizeof(struct Node));
 
    // Assigning the data.
    temp -> data = data;
    last = temp;
 
    // Creating the link.
    last -> next = last;
 
    return last;
}
 struct Node *addBegin(struct Node *last, int data)
{
    if (last == NULL)
        return addToEmpty(last, data);
 
    struct Node *temp =
            (struct Node *)malloc(sizeof(struct Node));
 
    temp -> data = data;
    temp -> next = last -> next;
    last -> next = temp;
 
    return last;
}
void traverse(struct Node *last)
{
    struct Node *p;
 
    // If list is empty, return.
    if (last == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }
 
    // Pointing to first Node of the list.
    p = last -> next;
 
    // Traversing the list.
    do
    {
        cout << p -> data << " ";
        p = p -> next;
 
    }
    while(p != last->next);
 
}
int main()
{
    struct Node *last = NULL;
 
    last = addToEmpty(last, 10);
    last = addBegin(last, 20);
    last = addBegin(last, 30);
    last = addBegin(last, 40);
    last = addBegin(last, 50);
    cout<<"Link List after inserting elemen at start :"<<endl;
    traverse(last);
 
    return 0;
}

Q3:

#include<bits/stdc++.h>
using namespace std;
 
struct Node
{
    int data;
    struct Node *next;
};
struct Node *addToEmpty(struct Node *last, int data)
{
    // This function is only for empty list
    if (last != NULL)
      return last;
 
    // Creating a node dynamically.
    struct Node *temp =
           (struct Node*)malloc(sizeof(struct Node));
 
    // Assigning the data.
    temp -> data = data;
    last = temp;
 
    // Creating the link.
    last -> next = last;
 
    return last;
}
 struct Node *addEnd(struct Node *last, int data)
{
    if (last == NULL)
        return addToEmpty(last, data);
     
    struct Node *temp =
        (struct Node *)malloc(sizeof(struct Node));
 
    temp -> data = data;
    temp -> next = last -> next;
    last -> next = temp;
    last = temp;
 
    return last;
}
void traverse(struct Node *last)
{
    struct Node *p;
 
    // If list is empty, return.
    if (last == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }
 
    // Pointing to first Node of the list.
    p = last -> next;
 
    // Traversing the list.
    do
    {
        cout << p -> data << " ";
        p = p -> next;
 
    }
    while(p != last->next);
 
}
int main()
{
    struct Node *last = NULL;
 
    last = addToEmpty(last, 10);
    last = addEnd(last, 20);
    last = addEnd(last, 30);
    last = addEnd(last, 40);
    last = addEnd(last, 50);
    cout<<"Link List after inserting elemen at end:"<<endl;
    traverse(last);
 
    return 0;
}

Q4 and Q5 :

#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* next;
};

void Insert(struct Node** head, int data)
{
	struct Node* current = *head;
	// Create a new node
	struct Node* newNode = new Node;

	// check node is created or not
	if (!newNode) {
		printf("\nMemory Error\n");
		return;
	}

	newNode->data = data;

	if (*head == NULL) {
		newNode->next = newNode;
		*head = newNode;
		return;
	}

	else {

		while (current->next != *head) {
			current = current->next;
		}

		// put first or head node address
		// in new node link
		newNode->next = *head;

		// put new node address into last
		// node link(next)
		current->next = newNode;
	}
}

// Function print data of list
void Display(struct Node* head)
{
	struct Node* current = head;

	// if list is empty, simply show message
	if (head == NULL) {
		printf("\nDisplay List is empty\n");
		return;
	}

	// traverse first to last node
	else {
		do {
			printf("%d ", current->data);
			current = current->next;
		} while (current != head);
	}
}

// Function return number of nodes present in list
int Length(struct Node* head)
{
	struct Node* current = head;
	int count = 0;

	// if list is empty simply return length zero
	if (head == NULL) {
		return 0;
	}

	// traverse first to last node
	else {
		do {
			current = current->next;
			count++;
		} while (current != head);
	}
	return count;
}

// Function delete First node of Circular Linked List
void DeleteFirst(struct Node** head)
{
	struct Node *previous = *head, *next = *head;

	// check list have any node
	// if not then return
	if (*head == NULL) {
		printf("\nList is empty\n");
		return;
	}

	// check list have single node
	// if yes then delete it and return
	if (previous->next == previous) {
		*head = NULL;
		return;
	}

	// traverse second to first
	while (previous->next != *head) {

		previous = previous->next;
		next = previous->next;
	}

	// now previous is last node and
	// next is first node of list
	// first node(next) link address
	// put in last node(previous) link
	previous->next = next->next;

	// make second node as head node
	*head = previous->next;
	free(next);

	return;
}

// Function to delete last node of
// Circular Linked List
void DeleteLast(struct Node** head)
{
	struct Node *current = *head, *temp = *head, *previous;

	// check if list doesn't have any node
	// if not then return
	if (*head == NULL) {
		printf("\nList is empty\n");
		return;
	}

	// check if list have single node
	// if yes then delete it and return
	if (current->next == current) {
		*head = NULL;
		return;
	}

	// move first node to last
	// previous
	while (current->next != *head) {
		previous = current;
		current = current->next;
	}

	previous->next = current->next;
	*head = previous->next;
	free(current);

	return;
}

int main()
{
	struct Node* head = NULL;
	Insert(&head, 10);
	Insert(&head, 20);
	Insert(&head, 30);
	Insert(&head, 40);
	Insert(&head, 50);


	// Deleting first Node
	printf("\n\nInitial List: ");
	Display(head);
	printf("\nAfter Deleting first node: ");
	DeleteFirst(&head);
	Display(head);

	// Deleting last Node
	printf("\n\nInitial List: ");
	Display(head);
	printf("\nAfter Deleting last node: ");
	DeleteLast(&head);
	Display(head);

	return 0;
}

Q6:

#include <bits/stdc++.h>

using namespace std;

struct Node {
	int data;
	Node* next;
};

Node* getNode(int data)
{
	
	Node* newNode = new Node;

	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

void reverse(Node** head_ref)
{
	
	if (*head_ref == NULL)
		return;

		Node* prev = NULL;
	Node* current = *head_ref;
	Node* next;
	do {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	} while (current != (*head_ref));

	
    	(*head_ref)->next = prev;
	*head_ref = prev;
}

void printList(Node* head)
{
	if (head == NULL)
		return;

	Node* temp = head;
	do {
		cout << temp->data << " ";
		temp = temp->next;
	} while (temp != head);
}


int main()
{
	
	Node* head = getNode(1);
	head->next = getNode(2);
	head->next->next = getNode(3);
	head->next->next->next = getNode(4);
	head->next->next->next->next = head;

	cout << "Given circular linked list: ";
	printList(head);

	reverse(&head);

	cout << "\nReversed circular linked list: ";
	printList(head);

	return 0;
}


































