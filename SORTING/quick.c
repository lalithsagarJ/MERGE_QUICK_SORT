#include<stdio.h>
#include<stdlib.h>
void quick_sort(int n,int a[n],int l,int r){
	int pivot,i,j,temp;
	if(l<r){
		i=l;	
		j=r;
		pivot=l;
		while(i<j){
			while(a[i]<=a[pivot]&&i<=r)
				i++;
			while(a[j]>a[pivot])
				j--;
			if(i<j){
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
		temp=a[pivot];
		a[pivot]=a[j];
		a[j]=temp;
		quicksort(n,a,l,j-1);
		quicksort(n,a,j+1,r);
	}
}

int main(){
	int i,n;
	printf("\nenter how many elements:");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n ;i++)
		scanf("%d",&a[i]);
	quick_sort(n,a,0,n-1);
	printf("after sorting\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}
