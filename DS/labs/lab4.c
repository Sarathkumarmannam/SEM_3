/*Making a Program on Polynomial ADT*/
#include<stdio.h>
#include<stdlib.h>
struct poly
{
	int coeff;
	int expo;
	struct poly *next;
};
struct poly *create(struct poly*);
void add(struct poly*,struct poly*);
void subract(struct poly*,struct poly*);
void multiply(struct poly*,struct poly*);
void display(struct poly*);
struct poly *addnode(struct poly*,struct poly*);
int main()
{

	int ch;
	struct poly *head1=NULL,*head2=NULL;
	printf("<<Enter the Polynomial 1>>\n");
	head1=create(head1);
	printf("<<Enter polynomial 2>>\n");
	head2=create(head2);
	display(head1);
    display(head2);
	do{
	printf("\nEnter Ur choice to-\n1.Addition\n2.Subtraction\n3.Multiplication\n4.ReEnter the polynomial\n5.Exit-");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
		add(head1,head2);
		break;
		case 2:
		subract(head1,head2);
		break;
		case 3:
		multiply(head1,head2);
		break;
		case 4:
		head1=NULL;head2=NULL;
		goto k;
		break;
	    case 5:
	    exit(0);
	    default :
	    printf("Invalid choice");
	}
}while(ch>=1 && ch<=5);
}
struct poly *create(struct poly *head)
{
	struct poly *new1=NULL,*temp=NULL;
	int ch;
	do{
	new1=(struct poly*)malloc(sizeof(struct poly));
	printf("\nEnter Co-efficent of the term:: ");
	scanf("%d",&new1->coeff);
	printf("\nEnter Exponent::");
	scanf("%d",&new1->expo);
	new1->next=NULL;
	if(head==NULL)
	{
		head=new1;
	}
	else
	{
		temp=head;
																																																																																																																																															while(temp->next!=NULL)
		{
			temp=temp->next;

		}
		temp->next=new1;
	}
	  printf("\nIs there any next term-(1/0)?-");
	  scanf("%d",&ch);
}while(ch==1);
	return head;
}
void display(struct poly *head)
{
	struct poly *temp;
	temp=head;
	int co=0;
	printf("\n");
	while(temp!=NULL)
	{
		if(temp->coeff!=0)
		{
			if(temp->coeff>0 || temp==head)
			     printf("%dx^%d ",temp->coeff,temp->expo);
			     else
			     {
			     	co=-temp->coeff;
			     	printf("%dx^%d",co,temp->expo);
			     }
		}
		      temp=temp->next;
		    	if(temp!=NULL && temp->coeff!=0)
		    	{
		    	   if(temp->coeff>0)
        	printf("+ ");
        	else{
		    	      printf("- ");
		        }
		   }
	}
}
void add(struct poly *head1,struct poly *head2)
{
	struct poly *temp1=NULL,*temp2=NULL,*head3=NULL,*temp3=NULL;
	temp1=head1;
	temp2=head2;
	temp3=(struct poly*)malloc(sizeof(struct poly));
	temp3->next=NULL;
	head3=temp3;
	while(temp1!=NULL || temp2!=NULL)
	{
		if((temp1->expo)>(temp2->expo))
		{
			temp3->expo=temp1->expo;
			temp3->coeff=temp1->coeff;
			temp1=temp1->next;
		}--------------------------------
		else if((temp1->expo)<(temp2->expo))
		{
			temp3->expo=temp2->expo;
			temp3->coeff=temp2->coeff;
			temp2=temp2->next;
		}
		else
		{
			temp3->expo=temp1->expo;
			temp3->coeff=(temp1->coeff)+(temp2->coeff);
			temp1=temp1->next;
			temp2=temp2->next;
		}
		if(temp3->expo!=0)
		{
		temp3->next=(struct poly*)malloc(sizeof(struct poly));
		temp3=temp3->next;
		temp3->next=NULL;
		}
	}
	display(head3);
}
void subract(struct poly *head1,struct poly *head2)
{
	struct poly *temp1=NULL,*temp2=NULL,*head3=NULL,*temp3=NULL;
	temp1=head1;
	temp2=head2;
	temp3=(struct poly*)malloc(sizeof(struct poly));
	temp3->next=NULL;
	head3=temp3;
	while(temp1!=NULL || temp2!=NULL)
	{
		if((temp1->expo)>(temp2->expo))
		{
			temp3->expo=temp1->expo;
			temp3->coeff=temp1->coeff;
			temp1=temp1->next;
		}
		else if((temp1->expo)<(temp2->expo))
		{
			temp3->expo=temp2->expo;
			temp3->coeff=-(temp2->coeff);
			temp2=temp2->next;
		}
		else
		{
			temp3->expo=temp1->expo;
			temp3->coeff=(temp1->coeff)-(temp2->coeff);
			temp1=temp1->next;
			temp2=temp2->next;
		}
		if(temp3->expo!=0)
		{
		temp3->next=(struct poly*)malloc(sizeof(struct poly));
		temp3=temp3->next;
		temp3->next=NULL;
		}
	}
	display(head3);
}
void multiply(struct poly *head1,struct poly *head2)
{
   struct poly*head3=NULL,*temp1=NULL,*temp2=NULL,*temp3=NULL;
   temp1=head1;
   while(temp1!=NULL)
   {
   	temp2=head2;
   	   while(temp2!=NULL)
   	     {
   	        temp3=(struct poly*)malloc(sizeof(struct poly));
   	     	temp3->coeff=(temp1->coeff)*(temp2->coeff);
   	        temp3->expo=temp1->expo+temp2->expo;
   	        head3=addnode(head3,temp3);
   	        temp2=temp2->next;
   	     }
   	  temp1=temp1->next;
   }
   display(head3);
}
struct poly *addnode(struct poly *head3,struct poly *t)
{
	struct poly *temp=NULL;
	int flag=-1;
	if(head3==NULL)
	{
		head3=t;
		head3->next=NULL;
	}
	else
	{
		for(temp=head3;temp!=NULL;temp=temp->next)
		{

			if(temp->expo==t->expo)
			{
				temp->coeff=temp->coeff+t->coeff;
				return head3;
			}
		}
		      	for(temp=head3;temp->next!=NULL;temp=temp->next)
			{
				if((temp->expo>t->expo)&&(temp->next->expo < t->expo))
				{
					t->next=temp->next;
					temp->next=t;
					flag=1;
				}
			}
			if(flag!=1)
			{
			for(temp=head3;temp->next!=NULL;temp=temp->next);
			temp->next=t;
			t->next=NULL;
			}
		}
		return head3;
}