#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int queue[2000],*k=&queue[0],*head=&queue[0],*tail;
int p[1000000],flag[2001];
int n,m,l,r;
void getready()
{
	head=&queue[0];
	for(int i=0;i<m;++i)
		queue[i]=i+1;
}
void Search(int x)
{
	for(int j=0;j<=(tail-head);++j)
	{
		if(head[j]==x)
		{
			swap(*head,head[j]);
			++head;
			break;
		}
	}
}
void Back(int x)
{
	for(int j=0;j>=(k-head);j--)
	{
		if(head[j]==x)
		{
			--head;
			swap(*head,head[j+1]);
			break;
		}
	}
}
bool judge(int x)
{
	memset(flag,0,sizeof(flag));
	for(int i=0;i<x;++i)
	{
		if(flag[p[i]]==0) Search(p[i]);
		++flag[p[i]];
	}
	for(int i=x;i<=n;++i)
	{
		if(head==tail)
		{
			l=i-x;
			r=i-1;
			break;
		}
		--flag[p[i-x]];
		if(flag[p[i-x]]==0) Back(p[i-x]);
		if(flag[p[i]]==0) Search(p[i]);
		++flag[p[i]];
	}
	if(head==tail) return true;
	else return false;
}
int main()
{
	memset(flag,0,sizeof(flag));
	cin>>n>>m;
	for(int i=0;i<n;++i)
		cin>>p[i];
	tail=&queue[m];
	int Left=1,Right=n;
	while(Left<Right)
	{
		getready();
		int mid=(Left+Right)>>1;
		if(judge(mid))
		{
			Right=mid;
		}
		else Left=mid+1;
	}
	if(Left==Right) {getready();judge(Left);}
	cout<<l+1<<" "<<r+1;
	return 0;
}
