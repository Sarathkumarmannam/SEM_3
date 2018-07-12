//A program on circular linkedlist
//deleting an element from circular list
//Searching and sorting in a cirular list
#include<stdio.h>
#include<stdlib.h>
typedef struct CList{
    int data;
    struct CList *next;
}node;
node *head;
void Delete();
void createList();
void display();
void AddNode();
void Search();
int main()
{
    int ch;
    do{
        printf("PRESS \n 1->create Circular Linked list\n2->Display\n");
        printf("3->NewNode\n4->deleteNode\n5.Search\nEnter your choice\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                createList();
                break;
            case 2:
                display();
                break;
            case 3:
                AddNode();
                break;
            case 4:
                Delete();
                break;
            case 5:
                Search();
                break;
            default:
                {
                    printf("Enter choice in selected series\n");
                    printf("Do you still wanna continue(1|0)");
                    scanf("%d",&ch);
                }
                 }
    }
    while(ch>=1&&ch<=5);
}
void Search(){
    node *temp=head;
    int n;
    printf("Enter data of node to search\n");
    scanf("%d",&n);
    do
    {
        if(temp->data==n){
            n=0;break;}
        else{
            // go to next address
            temp=temp->next;
        }
    }
    while(temp!=head);
    if(n==0)
    printf("Required data is found ^_^\n");
    else
    printf("Required data is not found\n");

}
void Delete(){
    node *temp=head;
    printf("Enter node number to delete\n");
    int pos,count=1;
    scanf("%d",&pos);
    while(pos!=(count))
    {
        if(count==1)     {count++;continue;}
        temp=temp->next;
        count++;
    }
    node *ptr=temp->next->next;
    free(temp->next);
    temp->next=ptr;
    printf("Node at position %d is successfully deleted\n",pos);
}
void AddNode(){
    node* OneMore=(node*)malloc(sizeof(node));
    node *temp=head;
    while(temp->next!=head)
        temp=temp->next;
    printf("Enter Data for NewNode\t");
    scanf("%d",&OneMore->data);
    temp->next=OneMore;
    OneMore->next=head;
    temp=head;
    printf("New Node is successfully created^_^\n");
}
void createList(){
    head=(node*)malloc(sizeof(node));
    if(head==NULL){printf("Memorynotfound\n");return;}
    node* temp=head;
    //node* newnode=(node*)malloc(sizeof(node));
    int flag=0;
    do{
        printf("Enter data of the node\n");
        scanf("%d",&temp->data);
        printf("1 to Continue|0 to drop:\t");
        scanf("%d",&flag);
        temp->next=head;
        if(flag==0)
            break;
        else
        {
            //go and create new node
            node* New=(node*)malloc(sizeof(node));
            if(New==NULL)
                {printf("Memory not allocated\n");break;}
                temp->next=New;
                temp=New;

        }
    }
    while(flag!=0);
printf("\n---^_^--Circular List Successfully created----^_^----\n");
}
void display()
{
    node *temp=head;
    printf("Node 1 data is %d\n",temp->data);
    temp=temp->next;
    int i=2;
    while(temp!=head)
    {
        printf("Node %d data is %d;\n",i,temp->data);
        temp=temp->next;
    i++;
    }
}


