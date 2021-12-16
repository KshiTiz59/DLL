
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
  cout<<"END";
}


int main()
  {
  int n;
  Node *head;
    head=NULL;
  cout<<"Enter the value of N:";
  cin>>n;
  for(int i=n;i>=1;i--)
  {
    head=push(&head,i);
  }
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
void swap(**head_ref)
{
  int count =1;
  Node *p=*head_ref;
  Node *q=*head_ref;
  
  while((q->next)!=NULL)
  {
    q=q->next;
  }
  while(count!=i)
  {
    count++;
    p=p->next;
    q=q->prev;
  }
  Node *node1=new
}

int main()
  {
  int n,i;
  Node *head;
    head=NULL;
  cout<<"Enter the value of N:";
  cin>>n;
  for(int i=n;i>=1;i--)
  {
    head=push(&head,i);
  }
  Display(head);
  cout<<"Enter the i-th Node to Swap:";
  cin>>i;
  swap(&head,i);
}


  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
