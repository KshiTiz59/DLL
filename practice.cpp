
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



  


  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
