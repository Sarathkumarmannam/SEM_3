//A program of application of Linkedlist
//Creating a polynomial
//Displaying a Polynomial
//Adding Polynomial
#include<stdio.h>
#include<stdlib.h>
typedef struct Polynomial
{
    int coeff;
    int degree;
    struct Polynomial* next;
}Pnode;
Pnode *head,*head2;
Pnode* create(Pnode* );
void display(Pnode* hello);
int main()
{
    head=(Pnode*)malloc(sizeof(Pnode));
    head2=(Pnode*)malloc(sizeof(Pnode));
    printf("Start typing first Polynomial term wise");
    head=create(head);
    display(head);
    head2=create(head2);
    display(head2);
    return 0;
}
void display(Pnode* hello)
{
    printf("\n");
    Pnode* temp=hello;
    int flag=0;
    do
    {
        if(flag==1)
            temp=temp->next;
        if(temp->coeff>0)
        printf("+");
        printf("%dy%d",temp->coeff,temp->degree);
        flag=1;
    }
    while(temp->next!=NULL);
    printf("\n");
}
Pnode* create(Pnode* hello)
{
    int flag=1;
    Pnode* temp;
    temp=hello;
    do{
        printf("\nEnter coeffecient:Degree  ");
        scanf("%d%d",&temp->coeff,&temp->degree);
        printf("1 to Continue|0 to drop:\t");
        scanf("%d",&flag);
        temp->next=NULL;
        if(flag==0)
            break;
        else
        {
            //go and create new node
            Pnode* New=(Pnode*)malloc(sizeof(Pnode));
            if(New==NULL)
                {printf("Memory not allocated\n");break;}
                temp->next=New;
                temp=New;

        }
    }
    while(flag!=0);
    printf("\n-----------------Polynomial Successfully created---------\n");
    return hello;
}