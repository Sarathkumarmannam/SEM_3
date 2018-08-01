//A program to implement stack using linked list
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
int data;
struct node *next;
}stack;
stack *h=NULL;
stack *lt=NULL;
stack* getnode()
{
stack *newnode=(stack*)malloc(sizeof(stack));
printf("Enter data of newnode\n");
scanf("%d",&newnode->data);
newnode->next=NULL;
return newnode;
}
void push()
{
stack *newnode=getnode();
newnode->next=h;
h=newnode;
}
int pop()
{
if(h==NULL)
{ printf("Stack Underflow\n");
	return -1;
}
int t=h->data;
stack* temp=h;
h=h->next;
free(temp);
return t;
}
void display()
{
stack* temp=h;
while(temp!=NULL)
{
	printf("%d ",temp->data);
	temp=temp->next;
}
printf("\n------\n");
}
void create(stack *input)

{
stack *list=input;
//creates a list and counts the number of nodes in the list

//*count=1;

 int ch;

 printf("Enter data of first node\n");

 scanf("%d",&list->data);

 list->next=NULL;

 printf("Do you want another node(1|0)\n");

 scanf("%d",&ch);

 while(ch!=0)

    {
   	//EXTENDS LIST UNTIL USER DOESN'T WANT ANOTHER NODE

	// CREATES A SINGLY LINKED LIST

        stack* newnode=getnode();

 	list->next=newnode;

  	list=newnode;


        printf("Do you want another node(1|0)\n");

        scanf("%d",&ch);

    }

  printf("A singly linked list is successfully created\n");

}

int main()
{
lt=(stack*)malloc(sizeof(stack));
h=lt;
int ch;
do{
//***
printf("Enter your choice\n1.Create\n2.Push\n3.Pop\n4.Display\n");
scanf("%d",&ch);
system("clear");
switch(ch)
{
case 1: create(lt);
	break;
case 2: push();
	break;
case 3:	printf("Popped integer is %d\n",pop());
	break;
	case 4:
 display();
 break;
default:
	printf("Enter correct choice\n");
}
}
while(ch>0&&ch<5);
}