#include<stdio.h>
#include<stdlib.h>
struct node
{
	int num;
	struct node *next;
};
struct node *head=NULL;
void addat_begin(int);
void addat_end(int);
void addat_mid(int,int);
void traversal();
void count();
void delatat_begin();
void delatat_end(int);
void delatat_mid(int);
int main()
{ int ch,temp=1,data;
	printf("enter the 1:addat_begin\n2:addat_end\n3:addat_mid");
	while(temp)
	{
		printf("enter the choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				{
					printf("enter the data");
					scanf("%d",&data);
					addat_begin(data);
					break;
				}
			case 2:
			    {
			    	printf("enter the data");
					scanf("%d",&data);
					addat_end(data);
					break;
				}
			case 3:
				{
					int position;
					printf("enter the data and position");
					scanf("%d %d",&data,&position);
					addat_mid(data,position);
					break;
				}	
			case 4:
				{
					traversal();
				break;
				}
			case 5:
			     {
			      count();	
				 }
			case 6:
			     {
			     delatat_begin();	
				 }	
			case 7:
			     {
			     	int position;
			     	printf("enter the position");
			      	delatat_end(position);	
			     }	
				case 8:
			     {
			     	int position;
			     	printf("enter the position");
			      	delatat_mid(position);	
			     }	  
		}
	}
}

void addat_begin(int data)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		puts("no node created");
 		return;
	}
	else
	{
		temp->num=data;
		temp->next=NULL;
	}
	if(head==NULL)
	{
		head=temp;

	}
	else
	{
	temp->next=head;
	head=temp;	
	}
}

void addat_end(int data)
{
	struct node *temp,*current;
	temp=(struct node*)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		puts("no node created");
		return;
	}
	else
	{
		temp->num=data;
		temp->next=NULL;
	}
	if(head==NULL)
	{
		head=temp;
	}
	else
	{
		current=head;
		while(current->next!=NULL)
		{
			current=current->next;
		}
		current->next=temp;
	}
}

void addat_mid(int data,int position)
{
	struct node *temp,*current;
	temp=(struct node*)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		puts("no node created");
		return;
	}
	else
	{
		temp->num=data;
		temp->next=NULL;
	}
	if(head==NULL)
	{
		head=temp;
	}
	else
	{
		current=head;
		int i;
		for(i=0;i<position-1;i++)
		{
		if(current->next==NULL)
		{
			puts("insufficient nodes");
			}	
			else
			{
				current=current->next;
			}
		}
		temp->next=current->next;
		current->next=temp;
	}
}

void traversal()
{
	struct node *current;
	if(head==NULL)
	{
		puts("\n List is empty");
	return;
	}
	else
	{
		current=head;
		while(current!=NULL)
		{
			printf("%d\t",current->num);
			current=current->next;
		}
	}
	
	
}

void delatat_begin()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("list is empty");
		return;
	}
	else
	{
		temp=head;
		head=temp->next;
		free(temp);
	}
}

void delatat_end(int position)
{
	struct node *previous,*current;
	if(head==NULL)
	{
		puts("list is empty");
		return;
	}
	else
	{
		current=head;
		while(current->next!=NULL)
		{
			previous=current;
			current=current->next;
		}
	}
	previous->next=NULL;
	free(current);
}

void delatat_mid(int position)
{ int i;
	struct node *previous,*current;
	if(head==NULL)
	{
		puts("list is empty");
	}
	else
	{
		current=head;
		for(i=0;i<position-2;i++)
		{
		  if(current->next==NULL)
		  {
		  	puts("insuffient nodes");
		  }
		  else
		  {
		  	previous=current;
		  	current=current->next;
		  }
		}
		previous->next=current->next;
		free(current);
		
	}
}
