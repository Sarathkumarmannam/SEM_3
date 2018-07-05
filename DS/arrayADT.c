#include<stdio.h>
void insertFront(int []);
void insertEnd(int []);
void insert(int []);
void deleteIt(int []);
void display(int []);
void searchElement(int []);
void sortList(int []);
void reverseList(int []);
int n;
int main()
{
int a[50],ch;
printf("Enter length of list:\n");
scanf("%d",&n);
int i;
printf("Enter elements\n");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
printf("1.Insert at begin\n 2. Insert at end \n 3. Insert at Specific index \n 4. Delete element in array\n");
printf("5. Display element\n 6. Search an element \n 7. Sorting the list \n 8. Reversing the list\n 0. exit\n");
do
{
printf("enter your choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
insertFront(a);
break;
case 2:
insertEnd(a);
break;
case 3:
insert(a);
break;
case 4:
deleteIt(a);
break;
case 5:
display(a);
break;
case 6:
searchElement(a);
break;
case 7:
sortList(a);
break;
case 8:
reverseList(a);
break;
default:
exit(-1);
}
}while(ch>0&&ch<=8);
return 0;
}
void insertFront(int a[])
{
int temp;
printf("Enter new element:\t");
scanf("%d",&temp);
int i=0;
for(i=n;i>0;i--)
{
a[i]=a[i-1];
}
a[i]=temp;
n++;
}
void insertEnd(int a[])
{
int temp;
printf("Enter new element");
scanf("%d",&temp);
a[n]=temp;
n++;
}
void display(int a[])
{
int i=0;
for(i;i<n;i++)
printf("%d\t",a[i]);
};
void insert(int a[])
{
int i,temp,index;
printf("Enter the number and index to be inserted\t");
scanf("%d%d",&temp,&index);
for(i=n;i>index;i--)

void deleteIt(int a[])
{
int i,ele;
printf("Enter index to delete");
scanf("%d",&ele);
for(i=ele;i<n-1;i++)
{
a[i]=a[i+1];
}
n--;
}
void sortList(int a[])
{
int i=0;
int temp;
for(i=0;i<n-1;i++)
{
if (a[i]>a[i+1])
{
temp=a[i];
a[i]=a[i+1];
a[i+1]=temp;
}
void reverseList(int a[])
{
int rev[n],i;
for(i=0;i<n;i++)
{
rev[i]=a[n-i-1];
}
for(i=0;i<n+1;i++)
a[i]=rev[i];
}
void searchElement(int a[])
{
int i,ele;
printf("Enter the element to search:\t");
scanf("%d",&ele);
for(i=0;i<n;i++)
{
if(a[i]==ele)
printf("Found at index:%d",i);
}
}