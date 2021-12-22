
  1.Write a program to add 1 in first node, 2 in 2ndnode and so on till nth Write node ina doubly linked list (with n nodes).
  2.Write a program to swapi-thnodefrombeginningwithi-thnodefromendinaDoublyLinkedList.
  3.Write a C program to counttripletsinasorteddoublylinkedlistand store each tripletin another list.
  4.Write a program to rotate aDoublyLinkedListbyNplacesin both clockwise and anticlockwise direction.
  5.Write a program to traverselinkedlistfrommiddletoleft-rightorderusingrecursion.

//Q1

#include<bits/stdc++.h>
using namespace std;
class Node
{
  public :
int data;
Node *next;
Node *prev;
};

Node *push(Node **head_ref,int d)
{
  Node *new_node=new Node();
  new_node->data=d;
  new_node->next=*head_ref;
  new_node->prev=NULL;
  if(*head_ref!=NULL)
  {
    (*head_ref)->prev=new_node;
  }
  *head_ref=new_node;
  return *head_ref;
}
void Display(Node *node)
{
  while(node!=NULL)
  {
    cout<<node->data<<"->";
    node=node->next;
  }
  cout<<"END"<<endl;
}
void add(Node ** head_ref)
{
  Node *p=*head_ref;
  int i=1;
while(p->next!=NULL)
{
  p->data=(p->data)+i;
  p=p->next;
  i++;
}

p->data=(p->data)+(i);

}

int main()
  {
  int n,i;
  Node *head;
    head=NULL;
  cout<<"Enter the value of N:";
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    int data;
    cout<<"Enter the data of "<<(n-i+1)<<" node :";
    cin>>data;
    head=push(&head,data);
  }
  Display(head);
  cout<<"list after adding:\n";
  add(&head);
  Display(head);
  }
  
Q2:

#include<bits/stdc++.h>
using namespace std;
class Node
{
  public :
int data;
Node *next;
Node *prev;
};

Node *push(Node **head_ref,int d)
{
  Node *new_node=new Node();
  new_node->data=d;
  new_node->next=*head_ref;
  new_node->prev=NULL;
  if(*head_ref!=NULL)
  {
    (*head_ref)->prev=new_node;
  }
  *head_ref=new_node;
  return *head_ref;
}
void Display(Node *node)
{
  while(node!=NULL)
  {
    cout<<node->data<<"->";
    node=node->next;
  }
  cout<<"END"<<endl;
}
void swap(Node **head_ref,int i)
{
  Node *p=*head_ref;
Node *q=*head_ref;
while(q->next!=NULL)
{
  q=q->next;
}
for(int j=0;j<(i-1);j++)
{
p=p->next;
q=q->prev;
}
Node * node1=new Node();
Node* node2=new Node();
node1->data=q->data;
node2->data=p->data;
node1->next=p->next;
p->prev->next=node1;
p->next->prev=node1;
node1->prev=p->prev;
free(p);
node2->next=q->next;
q->prev->next=node2;
q->next->prev=node2;
node2->prev=q->prev;
free(q);
}

int main()
  {
  int n,i;
  Node *head;
    head=NULL;
  cout<<"Enter the value of N:";
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    int data;
    cout<<"Enter the data of "<<(n-i+1)<<" node :";
    cin>>data;
    head=push(&head,data);
  }
  cout<<"link list is :"<<endl;
  Display(head);
  cout<<"Enter the i-th node to be swapped:";
  cin>>i;
  cout<<"link list after swapping is :"<<endl;
 swap(&head,i);  
 Display(head);
  }

Q3:

#include <bits/stdc++.h>
using namespace std;

// structure of node of doubly linked list
struct Node {
	int data;
	struct Node* next, *prev;
};

int countTriplets(struct Node* head)
{
	struct Node* ptr1, *ptr2, *ptr3;
	int count = 0;
int a,b,c;
	// generate all possible triplets
	for (ptr1 = head; ptr1 != NULL; ptr1 = ptr1->next)
		for (ptr2 = ptr1->next; ptr2 != NULL; ptr2 = ptr2->next)
			for (ptr3 = ptr2->next; ptr3 != NULL; ptr3 = ptr3->next)
      {
				// if elements in the current triplet sum up to 'x'
         a=ptr1->data;
         b=ptr2->data;
         c=ptr3->data;
				if ((a==sqrt(b*b+c*c)) || (b==sqrt(a*a+c*c)) ||(c==sqrt(a*a+b*b)))

					// increment count
					count++;
      }
	// required count of triplets
	return count;
}

// A utility function to insert a new node at the
// beginning of doubly linked list
void insert(struct Node** head, int data)
{
	// allocate node
	struct Node* temp = new Node();

	// put in the data
	temp->data = data;
	temp->next = temp->prev = NULL;

	if ((*head) == NULL)
		(*head) = temp;
	else {
		temp->next = *head;
		(*head)->prev = temp;
		(*head) = temp;
	}
}

// Driver program to test above
int main()
{
	// start with an empty doubly linked list
	struct Node* head = NULL;

	// insert values in sorted order
	insert(&head, 5);
	insert(&head, 4);
	insert(&head, 3);
	insert(&head, 12);
	insert(&head, 13);
	insert(&head, 24);
	insert(&head, 25);

	cout << "Count = "
		<< countTriplets(head);
	return 0;
}


Q4:
// for clockwise

#include<iostream>
using namespace std;
class Node
{
  public :
int data;
Node *next;
Node *prev;
};

Node *push(Node **head_ref,int d)
{
  Node *new_node=new Node();
  new_node->data=d;
  new_node->next=*head_ref;
  new_node->prev=NULL;
  if(*head_ref!=NULL)
  {
    (*head_ref)->prev=new_node;
  }
  *head_ref=new_node;
  return *head_ref;
}
void Display(Node *node)
{
  while(node!=NULL)
  {
    cout<<node->data<<"->";
    node=node->next;
  }
  cout<<"END"<<endl;
}
void clockwise(Node **head_ref,int N)
{
    Node *p=*head_ref;
    int count =1;
    while(count<N && p!=NULL){
        p=p->next;
        count++;
    }
    if(p==NULL)
    return ;
    Node* q=p;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=*head_ref;
    (*head_ref)->prev=p;
    (*head_ref)=q->next;
    (*head_ref)->prev=NULL;
    q->next=NULL;
}

int main()
  {
  int n,N;
  Node *head;
    head=NULL;
  cout<<"Enter the value of N:";
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    int data;
    cout<<"Enter the data of "<<(n-i+1)<<" node :";
    cin>>data;
    head=push(&head,data);
  }
  cout<<"Link list is :"<<endl;
  Display(head);
  Node *Head=head;
  cout<<"Enter the value of N to shift the link list :";
 cin>>N;
 cout<<"After clockwise rotation of link list by "<<N<<" position:"<<endl;
 clockwise(&Head,N); 
 Display(Head);
}

//for anticlockwise

#include<iostream>
using namespace std;
class Node
{
  public :
int data;
Node *next;
Node *prev;
};

Node *push(Node **head_ref,int d)
{
  Node *new_node=new Node();
  new_node->data=d;
  new_node->next=*head_ref;
  new_node->prev=NULL;
  if(*head_ref!=NULL)
  {
    (*head_ref)->prev=new_node;
  }
  *head_ref=new_node;
  return *head_ref;
}
void Display(Node *node)
{
  while(node!=NULL)
  {
    cout<<node->data<<"->";
    node=node->next;
  }
  cout<<"END"<<endl;
}

void anticlockwise(Node **head_ref,int N,int n)
{ 
   
    Node *p=*head_ref;
    int count =1;
    while(count<(n-N) && p!=NULL){
        p=p->next;
        count++;
    }
    if(p==NULL)
    return ;
    Node* q=p;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=*head_ref;
    (*head_ref)->prev=p;
    (*head_ref)=q->next;
    (*head_ref)->prev=NULL;
    q->next=NULL;
    }

int main()
  {
  int n,N;
  Node *head;
    head=NULL;
  cout<<"Enter the value of N:";
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    int data;
    cout<<"Enter the data of "<<(n-i+1)<<" node :";
    cin>>data;
    head=push(&head,data);
  }
  cout<<"Link list is :"<<endl;
  Display(head);
  Node *HEAD=head;
  cout<<"Enter the value of N to shift the link list :";
 cin>>N;
 cout<<"After anticlockwise rotation of link list by "<<N<<" position:"<<endl;
 anticlockwise(&HEAD,N,n); 
  Display(HEAD);
}


Q5:

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* next;
  Node* prev;
};

Node *push(Node **head_ref,int d)
{
  Node *new_node=new Node();
  new_node->data=d;
  new_node->next=*head_ref;
  new_node->prev=NULL;
  if(*head_ref!=NULL)
  {
    (*head_ref)->prev=new_node;
  }
  *head_ref=new_node;
  return *head_ref;
}
void Display(Node *node)
{
  while(node!=NULL)
  {
    cout<<node->data<<"->";
    node=node->next;
  }
  cout<<"END"<<endl;
}

int getSize(Node* head)
{
	if (head == NULL)
		return 0;
	return 1 + getSize(head->next);
}

Node* printMiddleToLeftRightUtil(Node* head,
								int counter, int lSize)
{
	// Base Condition
	// When size of list is odd
	if (counter == 1 && lSize % 2 != 0) {

		// Print node value
		cout << head->data;

		// Returns address of next node
		return head->next;
	}

	// Base Condition
	// When size of list is even
	else if (counter == 1) {

		// Print node value
		// and next node value
		cout << head->data;
		cout << " , " << head->next->data;

		// Returns address of next to next node
		return head->next->next;
	}
	else {

		// Recursive function call and
		// store return address
		Node* ptr = printMiddleToLeftRightUtil(
			head->next,
			counter - 1,
			lSize);

		// Print head data
		cout << " , " << head->data;

		// Print ptr data
		cout << " , " << ptr->data;

		// Returns address of next node
		return ptr->next;
	}
}

// Function to print Middle to
// Left-right order
void printMiddleToLeftRight(Node* head)
{
	// Function call to get the size
	// Of Linked List
	int listSize = getSize(head);

	int middle = 0;

	// Store middle when Linked
	// List size is odd
	if (listSize % 2 != 0) {
		middle = (listSize + 1) / 2;
	}

	// Store middle when Linked
	// List size is even

	else {
		middle = listSize / 2;
	}

	// Utility function call print
	// Linked List from Middle
	// to left right order
	cout << "Output : ";

	printMiddleToLeftRightUtil(head,
							middle,
							listSize);
}

// Driver code
int main()
{
int n,N;
  Node *head;
    head=NULL;
  cout<<"Enter the value of N:";
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    int data;
    cout<<"Enter the data of "<<(n-i+1)<<" node :";
    cin>>data;
    head=push(&head,data);
  }
  cout<<"Link list is :"<<endl;
  Display(head);
	// Function call print Linked List from
	// Middle to left right order
	printMiddleToLeftRight(head);
	return 0;
}



  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
