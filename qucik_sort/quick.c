#include<stdio.h>
int partition(int a[],int p,int q)
{
	int pivot;
	pivot=a[p];
	int i,j;
	i=p;
	for(j=i+1;j<=q;j++)
	{
		if(a[j]<pivot)
		{
			i=i+1;
			int tmp;
			tmp=a[j];
			a[j]=a[i];
			a[i]=tmp;
		}
	}
	int tmp;
	tmp=a[i];
	a[i]=a[p];
	a[p]=tmp;
	return i;
}
void quicksort(int a[],int p,int q)
{
	if(p<q)
	{
		int r = partition(a,p,q);
		quicksort(a,p,r-1);
		quicksort(a,r+1,q);
	}
}
int main()
{
	int n;
	printf("Enter the size of array : \n");
	scanf("%d",&n);
	int a[n];
	printf("Enter the array elements : \n");
	int i;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Before sorting...\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	printf("Running quicksort....\n");
	printf("\n");
	quicksort(a,0,n-1);
	printf("Sorted Array : \n");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}