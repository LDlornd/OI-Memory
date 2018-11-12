#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;
int a[100000],cha[100000];
void Merge(int array[],int head,int mid,int tail)
{
	int *tmp=(int *)malloc((tail-head+1)*sizeof(int));
	int x=head,y=mid+1,k=0;
	while(x<=mid&&y<=tail)
	{
		if(array[x]<array[y]) tmp[k++]=array[x++];
		else tmp[k++]=array[y++];
	}
	while(x<=mid)
		tmp[k++]=array[x++];
	while(y<=tail)
		tmp[k++]=array[y++];
	for(int i=0;i<k;++i)
		array[head+i]=tmp[i];
	free(tmp);
}
void Merge_sort(int array[],int head,int tail)
{
	if(array==NULL||head>=tail) return;
	int mid=(head+tail)/2;
	Merge_sort(array,head,mid);
	Merge_sort(array,mid+1,tail);
	Merge(array,head,mid,tail);
}
int main()
{
	int n,k,sum=0;
	cin>>n>>k;
	for(int i=0;i<n;++i)
		cin>>a[i];
	Merge_sort(a,0,n-1);
	for(int i=0;i<n-1;++i)
		cha[i]=a[i+1]-a[i];
	Merge_sort(cha,0,n-2);
	for(int i=0;i<k;++i)
		sum+=cha[i];
	cout<<sum; 
}
