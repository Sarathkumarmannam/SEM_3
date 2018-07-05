//A program on circular linkedlist
#include<stdio.h>
#include<stdlib.h>
typedef struct CList{
    int data;
    struct CList *next;
}node;
node *head;
void createList();
void display();
int main()
{
    int ch;
    printf("PRESS \n 1->create Circular Linked list\n2->Display\n");
    do{
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                createList();
                break;
            case 2:
                display();
                break;
            /*case 3:
                AddNode();
                break;
            case 4:
                DeleteNode();
                break;*/
            default:
                {
                    printf("Enter choice in selected series\n");
                    printf("Do you still wanna continue(1|0)");
                    scanf("%d",&ch);
                }
    }
    while(ch>=1&&ch<=4);


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
    printf("Node 1 data is %d",temp->data);
    temp=temp->next;
    int i=2;
    while(temp!=head)
    {
        printf("Node %d data is %d;\n",i,temp->data);
        temp=temp->next;
    i++;
    }
}


