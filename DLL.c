
// Kshitiz Kumar
//20205091


#include<stdio.h>
#include<stdlib.h>
#define max 100
struct Node
{
  int empID;
  char name[max];
  char dept[max];
  char desig[max];
  int  sal;
  char phno[max];
  struct Node *next;
  struct Node *prev;
};

//--------------------------------------
struct Node *getnode(struct Node *head)
{
struct Node *newnode;
newnode=(struct Node*)malloc(sizeof(struct Node));
newnode->next=newnode->prev=NULL;
printf("Enter Employee ID,Name,Department,Designation,Salary,Phoneno \n");
scanf("%d",&newnode->empID);
_flushall();
gets(newnode->name);
_flushall();
gets(newnode->dept);
_flushall();
gets(newnode->desig);
_flushall();
scanf("%d",&newnode->sal);
_flushall();
gets(newnode->phno);
_flushall();
head=newnode;
return head;
}
//----------------------------------------
int countnodes(struct Node *head)
{
 struct Node *p;
 int count =0; 
 p=head;
 while(p!=NULL)
 {
   p=p->next;
   count++;
 } 
 return count;
}
//--------------------------------------
struct Node *display(struct Node *head)
{
 struct Node *p;
  if(head==NULL)
printf("\n NO Employee Data\n");
else
{
  p=head;
  printf("-----------EMPLOYEE DATA--------------");
  printf("\nEmpID\tName\tDept\tDesignation\tsal\tPh no.");
  while(p!=NULL)
  {
    printf("\n%d\t%s\t%s\t%s\t\t%d\t%s",p->empID,p->name,p->dept,p->desig,p->sal,p->phno);
    p=p->next;
  }
  printf("\nThe number of nodes int the list is %d",countnodes(head));
}
return head;
}
//---------------------------------------
struct Node* del(struct Node* head)
{
  int ch;
  do
  {
    printf("\n1: delete from the Front\t2:Delete form the End\t3:Exit");
    printf("\nEnter the choice :");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:head=delete_front(head);
      break;
      case 2:head=delete_end(head);
      break;
      case 3: break;
    }
    head=display(head);
  } while (ch!=3);
  return head;
}
struct Node *delete_front(struct Node* head)
{
 struct Node *p;
 if(head==NULL)
 printf("\nList is Empty");
 else
 {
   p=head;
   head=head->next;
   head->next->prev=NULL;
   free(p);
   printf("First node is deleted");
 }
 return head;
}
//--------------------------------------------------------
struct Node * delete_end(struct Node *head)
{
  struct Node *p;
  struct Node *q;
  p=head;
  while(p->next!=NULL)
  {
    p=p->next;
  }
  q=p->prev;
  q->next=NULL;
  p->prev=NULL;
  free(p);
  printf("\nlast node is deleted");
  return head;
}
//--------------------------------------------------------
struct Node * create(struct Node *head)
{
  struct Node *p,*newnode;
  p=head;
  if(head==NULL)
  {
    newnode=getnode(head);
    head=newnode;
  }
  else
  {
    newnode=getnode(head);
    while(p->next!=NULL)
    {
      p=p->next;
    }
    p->next=newnode;
    newnode->prev=p;
  }
  return head;
}
//----------------------------------------------------------
void main()
{
  int ch,i,n;
 struct Node *head;
  head=NULL;
printf("1:Create a DLL of N employee using end insertion and display the status and cout the number of nodes in the list\n");
printf("2:Deletion\n ");
printf("3:Perform Insertion in DLL after a given Employee id Details.\n");
printf("Enter your choice:");
scanf("%d",&i);
switch(i)
{
  case 1:
  printf("Enter the value of N :");
scanf("%d",&n);
for(int i=0;i<n;i++)
{
  head=create(head);
}
head=display(head);
break;
case 2:head=del(head);
}
}































