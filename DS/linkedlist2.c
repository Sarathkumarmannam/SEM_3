//reference is codeforwin.org
//creating and traversing a singly linked list
//insertAtBegin()
//deleting at Begin()
//sorting the linkedlist
void CreateList(int n);
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head,*temp,*newnode;
void sort(struct node*);
void DeleteAtBegin(struct node *);
void insertAtBegin(struct node *);
void Display(struct node *);
void insertAtMiddle(struct node *);
int main()
{
int n;
printf("Enter number of elements in a linked list\t");
scanf("%d",&n);
CreateList(n);
int ch;
do{
    printf("Enter your choice..\n1.Insert At Begin\n2.Insert at desired position\n3.Delete at front\n4.Display List\n");
    scanf("%d",&ch);
    switch(ch){
        case 1:
        insertAtBegin(head);
        break;
        case 2:
        insertAtMiddle(head);
        break;
        case 3:
        DeleteAtBegin(head);
        break;
        case 4:
        Display(head);
        break;
        default:
        printf("Enter correct Choice\n");
    }
    }
    while(ch<=4);
return(0);
}
void sort(struct node* first){
    printf("Enter data to be checked:\t");
    scanf("%d",&i);
    temp=head;
    while(temp!=head){
    if(temp->data=i)
    {
        printf("Required number is found\n");
        break;
    }
    else
        temp=temp->next;
    printf("Data not found\n");
    }
}
void DeleteAtBegin(struct node *first){
    temp=first->next->next;
    free (first->next);
    first->next=temp;
    printf("Node at beginning is deleted\n--------\n");
}


void insertAtMiddle(struct node *first)
{
    temp=first;
    int i=1,pos;
    printf("Enter the pos of newnode to insert at Middle\t");
    scanf("%d",&pos);
    while(i!=pos)
    {
        temp=temp->next;
        i++;
    }
    i--;
    struct node* middlenode=(struct node*) malloc(sizeof(struct node));
    printf("Enter data for new node\n");
    scanf("%d",&(middlenode->data));
    middlenode->next=temp->next;
    temp->next=middlenode;
    temp=middlenode;
    //temp=temp->next;
    printf("NODE successfully inserted at required position\n--------\n");
}
void insertAtBegin(struct node *first)
{
temp=first;
struct node *front= (struct node*)malloc(sizeof(struct node));
printf("Enter data for new node to insert at beginning\n");
scanf("%d",&(front->data));
front->next=first->next;
temp->next=front;
printf("New Node inserted");
}
void CreateList(int n)
{
    int i;
    head=(struct node *)malloc(sizeof(struct node));
    if(head==NULL)
    {
        printf("Memory not allocated");
        exit(-1);
    }
    head->next=NULL;
    temp=head;
    for(i=1;i<=n;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        if(newnode==NULL)
        {
            printf("Memory is not found");
            break;
        }
        else
        {
            printf("Enter data of node %d:\t",i);
            scanf("%d",&newnode->data);
            newnode->next=NULL;//make newnode next pointer to null
            temp->next=newnode;//store address of new node in previous node
            temp=temp->next;//move to newnode so to make newnode as previous node
        }
    }
    printf("List successfully created\n");
    printf("---------------------\n");
}
void Display(struct node *start)
{
    temp=start;
    temp=temp->next;
    int i=1;
    while(temp!=NULL)
    {
        printf("List %d data is %d;\n",i,temp->data);
        temp=temp->next;
    i++;
    }
}
