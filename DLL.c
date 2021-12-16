
#include<stdio.h>
#include<stdlib.h>
#define max 100
struct Node *delete_front(struct Node* head);
struct Node *delete_end(struct Node *head);
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
//-----------------------------------------------------------------
void get_node(struct Node *p)
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
newnode->next=p->next;
p->next=newnode;
newnode->prev=p;
if(newnode->next!=NULL)
newnode->next->prev=newnode;
p=newnode;
}
//-----------------------------------------------------------------
struct Node * insert_after_node(struct Node *head)
{
 int ID;
 printf("Enter the employee id after which the node is inserted");
scanf("%d",&ID);
struct Node *p;
p=head;
while(p->empID!=ID)
{
p=p->next;
}
get_node(p);
return head;
}
//----------------------------------------------------------
void delete_after(struct Node **head_ref,struct Node*p)
{
  if(*head_ref==p)
  *head_ref=(*head_ref)->next;
  if(p->next!=NULL)
  p->next->prev=p->prev;
  if(p->prev!=NULL)
  p->prev->next=p->next;
  free(p);
}
//-----------------------------------------------------------
void delete_after_node(struct Node *head)
{
struct Node *p;
p=head;
int id;
printf("enter the employee ID after which the node is deleted");
scanf("%d",id);
while(p->empID!=id)
{
  p=p->next;
}
delete_after(&head,p);
}
//------------------------------------------------------------
void salary(struct Node *head)
{
  struct Node *p;
  p=head;
  int max_sal=p->sal;
  int min_sal=p->sal;
  while(p->next!=NULL)
  {
  if(p->sal>=max_sal)
  max_sal=p->sal;
  if(p->sal<=min_sal)
  min_sal=p->sal;
   p=p->next;
  }
  p=p->next;
  if(p->sal>=max_sal)
  max_sal=p->sal;
  if(p->sal<=min_sal)
  min_sal=p->sal;
  printf("Maximum and Minimum salary are : %d %d",max_sal,min_sal);
}
//----------------------------------------------------------
void main()
{
  int ch,i,n;
 struct Node *head;
  head=NULL;
printf("---------------------------------------------------------------------------------------------------------------\n");
printf("1:Create a DLL of N employee using end insertion and display the status and cout the number of nodes in the list\n");
printf("2:Deletion\n ");
printf("3:Perform Insertion in DLL after a given Employee id Details.\n");
printf("4:Perform the deletion of particular employee after the given Employee id Details\n");
printf("5:Find the Employee Details having maximum and minimum salary\n");
printf("---------------------------------------------------------------------------------------------------------------\n");
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
break;
case 3:
head=insert_after_node(head);
break;
case 4:
delete_after_node(head);
break;
case 5:
salary(head);
break;
default:
break;
}
}
















