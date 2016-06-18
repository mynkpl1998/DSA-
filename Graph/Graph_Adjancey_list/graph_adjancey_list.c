#include<stdio.h>
#include<stdlib.h>
struct Adjlistnode {
	int dest;
	struct Adjlistnode *next;
};

struct Adjlist {
	struct Adjlist *head;
};

struct Graph {
	int V;
	struct Adjlist *array;
};

struct Adjlistnode *newnode (int dest)
{
	struct Adjlistnode *tmp = (struct Adjlistnode*)malloc(sizeof(struct Adjlistnode));
	tmp->dest=dest;
	tmp->next=NULL;
	return tmp;
}

struct Graph *createGraph(int V)
{
	struct Graph *tmp = (struct Graph*)malloc(sizeof(struct Graph));
	tmp->V=V;
	tmp->array=(struct Adjlist*)malloc(V*sizeof(struct Adjlist));
	int i;
	for(i=0;i<V;i++)
	{
		tmp->array[i].head=NULL;
	}
	return tmp;
}

void addEdge(struct Graph* graph,int src, int dest)
{
	struct Adjlistnode *tmp = newnode(dest);
	tmp->next=graph->array[src].head;
	graph->array[src].head=tmp;
	
}

void printgraph(struct Graph *graph)
{
	int v;
	for(v=0;v<graph->V;v++)
	{
		struct Adjlistnode* node = graph->array[v].head;
		printf("\nAdjancy list of vertex %d\n head ",v);
		while(node!=NULL)
		{
			printf("-> %d",node->dest);
			node=node->next;
		}
		printf("\n");
	}
}
int main()
{
	int V,E,i;
	printf("\nEnter the no of Verices : ");
	scanf("%d",&V);
	struct Graph *graph = createGraph(V);
	printf("\nEnter No of edges : ");
	scanf("%d",&E);
	for(i=0;i<E;i++)
	{
		int src, des;
		printf("\nEnter Source : ");
		scanf("%d",src);
		printf("\nEnter Destination : ");
		scanf("%d",des);
		addEdge(graph,src,des);
		printf("\nEdge Added ...");
	}
	printgraph(graph);
	return 0;
}
