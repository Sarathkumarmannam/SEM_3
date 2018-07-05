    // A program to print linked list
#include<stdio.h>
#include<stdlib.h>
struct Node
{
int data;
struct  Node *ptr;
};
void PrintList(struct Node *n)
{
    while(n!=NULL)
    {
        printf("%d\n",n->data);
        n=n->ptr;
    }
}
int main()
{
    struct Node *first=NULL;
    struct Node *second=NULL;
    struct Node *third= NULL;
    first=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));
    first->data=15;
    first->ptr=second;
    second->data=205;
    second->ptr=third;
    third->data=224;
    third->ptr=NULL;
    PrintList(first);
}
