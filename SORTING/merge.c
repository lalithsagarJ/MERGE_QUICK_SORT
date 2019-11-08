#include<stdio.h>
#include<stdlib.h>
void merge(int n,int a[n],int b,int m,int e){
	int i=b,j=m+1,k=b,p,B[n];
	while(i<=m&&j<=e){
		if(a[i]<=a[j]){
			B[k]=a[i];
			i++;
			j++;
		}
		else{
			B[k]=a[j];
			j++;	
			k++;
		}
	}
	if(i>m){
		for(p=j;p<=e;p++){
			B[k]=a[p];
			k++;
		}
	}
	if(j>e){
		for(p=i;p<=m;p++){
			B[k]=a[p];
			k++;
		}
	}
	for(p=b;p<=e;p++)
		a[p]=B[p];
}

void mergesort(int n,int a[n],int b,int e){
	if(b<e){
		int m=(int )((b+e)/2);
		mergesort(n,a,b,m);
		mergesort(n,a,m+1,e);
		merge(n,a,b,m,e);
	}
}

int main(){
	int i,n;
	printf("\nenter how many elements:");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n ;i++)
		scanf("%d",&a[i]);
	mergesort(n,a,0,n-1);
	printf("after sorting\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}
