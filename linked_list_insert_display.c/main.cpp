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
  tmp=(struct node *)malloc(sizeof(struct node));
  tmp->data=s;
  tmp->next=NULL;
  return tmp;
}

void insert(int s, struct node *head)
{
  struct node *tmp;
  struct node *last;
  if(head->next==NULL)
  {
     tmp=newnode(s);
     head->next=tmp;
  }
  else	
  {
    last=head->next;
    while(last->next!=NULL)
    {
      last=last->next;
    }
    tmp=newnode(s);
    last->next=tmp;
  }
}
void display(struct node *head)
{
  if(head->next==NULL)
      printf("\nList empty ");
  else
  {
   struct node *tmp=head;
    while(tmp->next!=NULL)
    {
      tmp=tmp->next;
      printf("%d->",tmp->data);
    }
  }
}
int main()
{
	struct node *head;
	head=(struct node*)malloc(sizeof(struct node));
	head->data=INT_MAX;
	head->next=NULL;
 while(1)
 {
   printf("\n1. Show Linked List ");
   printf("\n2. Insert Item ");
   printf("\n3. EXIT ");
   printf("\nEnter your choice : ");
   int ch,x;
   scanf("%d",&ch);
   switch(ch)
   {
     case 1:display(head);break;
     case 2:printf("\nEnter the element to insert : ");
	    scanf("%d",&x);
	    insert(x,head);
	    break;
     case 3:exit(-1);
     default:printf("\nWrong Choice ");
   }
 }
 return 0;
}
