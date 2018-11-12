#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int a[200000],ans=-999999999;
int find_lmax(int head,int tail)
{
	int sum=0,lmax=-999999999;
	for(int i=head;i<=tail;++i)
	{
		sum+=a[i];
		lmax=max(sum,lmax);
	}
	return lmax;
}
int find_rmax(int head,int tail)
{
	int sum=0,rmax=-999999999;
	for(int i=tail;i>=head;--i)
	{
		sum+=a[i];
		rmax=max(sum,rmax);
	}
	return rmax;
}
int search(int head,int tail)
{
	if(head==tail) return a[head];
	int mid=(head+tail)/2,sum=0;
	int lmax=find_lmax(head,tail),rmax=find_rmax(head,tail);
	int midmax=find_rmax(head,mid)+find_lmax(mid+1,tail);
	int Lmax=search(head,mid);
	int Rmax=search(mid+1,tail);
	return max(midmax,max(max(lmax,rmax),max(Lmax,Rmax)));
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;++i)
		cin>>a[i];
	ans=search(0,n-1);
	cout<<ans;
	return 0;
}
