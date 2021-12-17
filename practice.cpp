
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



  


  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
