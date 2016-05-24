#include<stdio.h>
void merge(int a[],int first,int mid,int last)
{
	int index;
	int n1,n2;
	n1=(mid-first)+1;
	n2=last-mid;
	
	int L[n1],R[n2];
	
	int i,j;
	for(i=0;i<n1;i++)
		L[i]=a[i+first];
	for(j=0;j<n2;j++)
		R[j]=a[mid+j+1];

	i=0;
	j=0;
	index=first;
	while(i<n1 && j<n2)
	{
		if(L[i]<=R[j])
		{
			a[index]=L[i];
			i=i+1;
			
		}
		else
		{
			a[index]=R[j];
			j=j+1;
			
		}
	index=index+1;
	}
	while(i<n1)
	{
		a[index]=L[i];
		i=i+1;
		index=index+1;
	}
	while(j<n2)
	{
		a[index]=R[j];
		j=j+1;
		index=index+1;
	}
}
void merge_sort(int a[],int first,int last)
{
	if(first<last)
	{
		int mid;
		mid=(first+last)/2;
		merge_sort(a,first,mid);
		merge_sort(a,mid+1,last);
		merge(a,first,mid,last);
	}
}
int main()
{
	int a[10]={8,9,3,2,1,5,7,11,12,1};
	int i;
	printf("\nArray before sorting : ");
	for(i=0;i<10;i++)
		printf("%d ",a[i]);
	merge_sort(a,0,9);
	printf("\nArray after sorting : ");	
	for(i=0;i<10;i++)
		printf("%d ",a[i]);
}
