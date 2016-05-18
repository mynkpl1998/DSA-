#define max 30
#include<stdio.h>
#include<stdlib.h>
int queue[max];
int head,tail=0;
void enqueue(int s)
{
	if((head==0 && tail==max-1) || (head==tail+1))
		printf("\nQueue Full ");
	else if(tail==max-1)
	{
		queue[tail]=s;
		tail=0;
	}
	else
	{
		queue[tail]=s;
		tail=tail+1;
	}
}
int dequeue()
{
	int x;
	if(head==tail)
		printf("\nQueue Empty ");
	else if(head==max-1)
	{
		x=queue[head];
		head=0;
		return x;
	}
	else
	{
		x=queue[head];
		head=head+1;
		return x;
	}
}
void display()
{
	if(tail>=head)
	{	
		int i;
		for(i=head;i<=tail;i++)
		{
			printf("%d->",queue[i]);
		}
	}
	else
	{
		int i;
		for(i=head;i<max;i++)
			printf("%d->",queue[i]);
		for(i=0;i<=tail;i++)
			printf("%d->",queue[i]);
	}
}	
int main()
{
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
			case 1:if(head!=tail)
				{
					display();
					break;
				}
				else
				{
					printf("\nQueue Empty ");
					break;
				}
			case 2:printf("Enter element to insert : ");
				scanf("%d",&x);
				enqueue(x);
				break;	
			case 3:dequeue();break;
			case 4:exit(-1);
			default:printf("Wrong Choice ");
		}
	}
	return 0;
}
