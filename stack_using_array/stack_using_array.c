#define max 30
#include<stdio.h>
#include<stdlib.h>
int top=-1;
int stack[max];
void push(int s, int *front)
{
	if(*(front)==max-1)
		printf("\nError Stack full ");
		
	else
		top=top+1;
		stack[top]=s;
}
int pop(int *front)
{
	int x;	
	if(*(front)==-1)
	{
		printf("\nError Stack empty ");
		return 0;
		
	}
	else
	{
		x=stack[*(front)];
		top=top-1;
		return x;
	}
}
int main()
{
	while(1)
	{	
		int i,x;
		printf("\nStack Operations : ");
		printf("\n1. Show Stack ");
		printf("\n2. PUSH ");
		printf("\n3. POP ");
		printf("\n4. EXIT ");
		int ch;
		printf("\nEnter the choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
	
			if(top==-1)
				printf("Emtpy");
			else
			{
				for(i=0;i<=top;i++)
				{
					printf("%d->",stack[i]);
				}
			}
			break;
			case 2:
			printf("\nEnter element to insert : ");
			scanf("%d",&x);
			push(x,&top);
			break;
			case 3:

			x=pop(&top);
			if(x!=0)
			{
				printf("\nPopping element....");
				printf("%d",x);
			}
			break;
			case 4:
				exit(-1);
			break;
			default:printf("\nWrong Choice ");
		}
	}
	return 0;
}
		
		
