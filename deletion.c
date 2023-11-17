#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int data;                   
    struct node *p;
};
void traverse_print(struct node *head);
struct node* deleting(struct node *head);

int main()
{
 
	struct node *head=(struct node*)malloc(sizeof(struct node));
	head->data=10;
	head->p=NULL;
	struct node *current=(struct node*)malloc(sizeof(struct node));
	current->data=20;
	current->p=NULL;
	head->p=current;

	current=(struct node*)malloc(sizeof(struct node));
	current->data=30;
	current->p=NULL;

}
void traverse_print(struct node* head)
{  
	if(head==NULL)
	{
		printf("empty");
	}
	struct node *temp=NULL;
	temp=head;
	while(temp!=NULL)
	{
		printf("%d->%d->%d",temp->data);
		temp=temp->p;
	}
	printf("NULL");
}


struct node* deleting(struct node* head)
{ 
	if (head==NULL)
	{
		printf("empty");
	}
	struct node *temp=head;
	head=temp->p;
	free(temp);
	temp=NULL;
	return head;
};
