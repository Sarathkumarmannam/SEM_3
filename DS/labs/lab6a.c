//A program to implement stack using array
#include<stdio.h>
#include<stdlib.h>
void push();
int pop();
void display();
#define n 50
int a[n];
int top=0;
int main()
{
    int i=0;
    int ch;
    printf("\nEnter no of elements in the array\n");
    scanf("%d",&ch);
    for(i=0;i<ch;i++)
    {
        printf("Enter array element %d\n",i);
        scanf("%d",&a[i]);
    }
    top=i;
    printf("\n1.Push\n2.Pop\n3.Display\n");
    do
    {
        printf("\nenter your choice\n");
        scanf("%d",&ch);
        system("clear");
        switch(ch)
    {
    case 1:
        push();
    break;
    case 2:
    printf("Popped integer is %d",pop());
    break;
    case 3:
        display();
    break;
    default:
    exit(-1);
    }
    }while(ch>0&&ch<4);
    return 0;
}
void push()
{
if(top==n)
{
    printf("Stack Memory Full\n");
    return;
}
int temp;
printf("Enter new element:\t");
scanf("%d",&temp);
a[top]=temp;
top=top+1;
printf("Element successfully pushed\n");
}
int pop()
{
int i=top;
if(i==0){printf("Stack Underflow\n");return -1;}
int temp;
temp=a[i-1];
top=top-1;
return temp;
}
void display()
{
int t=0;
printf("Array elements are\t");
for(;t<top;t++)
printf("%d\t",a[t]);

}
