#include<stdio.h>
#define max 100
void addEdge(int a[max][max],int i,int j)
{
	a[i][j]=1;
}
void printgraph(int a[max][max],int v)
{
	int i,j;
	for(i=0;i<v;i++)
	{
		printf("\nThe nodes at vertex %d are : ",i);
		printf("\nHead");
		for(j=0;j<v;j++)
		{
			if(a[i][j]==1)
				printf(" ->%d",a[i][j]);
		}
	}
}
void createGraph(int a[max][max],int v)
{
	int i, j;
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		{
			if(a[i][j]!=1)
			{
				a[i][j]=0;
			}
		}
	}
}
int main()
{
	int v,e;
	printf("\nEnter the no of vertices : ");
	scanf("%d",&v);
	int a[v][v];
	printf("\nEnter no of edges : ");
	scanf("%d",&e);
	int i;
	for(i=0;i<e;i++)
	{
		int src, des;
		printf("\nEnter Source : ");
		scanf("%d",&src);
		printf("\nEnter Destination  : ");
		scanf("%d",&des);
		addEdge(a,src,des);
	}
	createGraph(a,v);
	printf("\n");
	printgraph(a,v);
	return 0;
}
