#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
struct node* insert_end(struct node *head,int data)
{
   struct node *new=(struct node*)malloc(sizeof(struct node));
   new->data=data;
   new->link=NULL;

   new->link=head->link;
   head->link=new;
   head=head->link;
   return head;
}

void traverse(struct node *head)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	if(temp!=NULL)
	{
		printf("linked list is empty");
	}
	else
	{
		do
		{
			temp=temp->link;
		}
		while(temp!=NULL);
		{
			printf("after inseration new_cll: %d\n",head->data);
			head=head->link;
		}
	}
}
int main()
{
	struct node *head=(struct node*)malloc(sizeof(struct node));
	head->data=10;
	head->link=head;
	
	/*new->data=20;
	new->link=head;
	head->link=new;*/
//	int insertend=struct node *insert_end()

	printf("circular linked list: %d\n",head->data,head->link->data);

}
