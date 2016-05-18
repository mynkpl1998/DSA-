#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct node {
	int data;
	struct node *next;
};
struct node *newnode(int s)
{
	struct node *tmp;
	tmp=(struct node*)malloc(sizeof(struct node));
	tmp->data=s;
	tmp->next=NULL;
	return tmp;
}
void enqueue(int s,struct node *head,struct node *tail)
{
	if(head->next==NULL)
	{
		tail->data=s;
		head->next=tail;
	}
	else
	{
		struct node *tmp;
		tmp=newnode(s);
		tail->next=tmp;
		tail=tmp;
	}
}
int dequeue(struct node *head, struct node *tail)
{
	int x;
	if(head->next==NULL)
		printf("\nQueue Empty ");
	else if(head->next==tail)
	{
		struct node *tmp;
		tmp=head->next;
		x=tmp->data;
		head->next=NULL;
		return x;
	}
	else
	{
		struct node *tmp;
		tmp=head->next;
		x=tmp->data;
		head->next=head->next->next;
		return x;
	}
}
int display(struct node *head)
{
	if(head->next==NULL)
		printf("\nQueue Empty ");
	else
	{
		struct node *tmp;
		tmp=head;
		while(tmp->next!=NULL)
		{
			tmp=tmp->next;			
			printf("%d->",tmp->data);
		}
	}
}
int main()
{
	struct node *head, *tail;
	head=(struct node *)malloc(sizeof(struct node));
	tail=(struct node *)malloc(sizeof(struct node));
	head->data=INT_MAX;
	head->next=NULL;
	tail->data=INT_MAX;	
	tail->next=NULL;
	while(1)
	{
		printf("\n1. View Queue ");
		printf("\n2. Enqueue ");
		printf("\n3. Dequeue ");
		printf("\n4. EXIT ");
		printf("\nEnter your choice ");
		int ch,x;
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:display(head);break;
			case 2:printf("\nEnter element to insert : ");
				scanf("%d",&x);
				enqueue(x,head,tail);
				break;
			case 3:x=dequeue(head,tail);
				printf("Removing element...%d",x);break;
			case 4:exit(-1);break;	
			default:printf("Wrong Choice ");
		}
	}
	return 0;
}
