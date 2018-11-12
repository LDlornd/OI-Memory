#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN=100001;
int n,m,x,y,visit=0,num=0,tot=0;
int zhan[MAXN],top=0;
int dl[MAXN],head,tail;
int dfn[MAXN],low[MAXN],belong[MAXN];
int rudu[MAXN],res[MAXN];
int arr[MAXN],dp[MAXN];
bool flag[MAXN];
struct edge
{
	int v;
	edge *NEXT;
	edge() {v=0;NEXT=NULL;}
}*con[MAXN],*newcon[MAXN];
inline void ins(int start,int end,edge *a[])
{
	edge *p=new(edge);
	p->v=end;
	p->NEXT=a[start];
	a[start]=p;
}
inline void tarjan(int nv)
{
	int place;
	dfn[nv]=low[nv]=++visit;
	zhan[++top]=nv;flag[nv]=true;
	for(edge *p=con[nv];p;p=p->NEXT)
	{
		int vv=p->v;
		if(dfn[vv]==0)
		{
			tarjan(vv);
			low[nv]=min(low[nv],low[vv]);
		}
		else if(flag[vv]) low[nv]=min(low[nv],dfn[vv]);
	}
	if(dfn[nv]==low[nv])
	{
		++num;
		do
		{
			place=zhan[top--];
			flag[place]=false;
			belong[place]=num;
		}while(place!=nv);
	}
}
inline void rebuild()
{
	for(int i=1;i<=n;++i)
	{
		dp[belong[i]]=max(dp[belong[i]],i);
		for(edge *p=con[i];p;p=p->NEXT)
		{
			int nv=p->v;
			if(belong[i]!=belong[nv])
			{
				ins(belong[i],belong[nv],newcon);
				++rudu[belong[nv]];
			}
		}
	}
}
inline void top_sort()
{
	head=1;tail=0;
	for(int i=1;i<=num;++i)
		if(rudu[i]==0) dl[++tail]=i;
	while(head<=tail)
	{
		int nv=dl[head++];
		res[++tot]=nv;
		for(edge *p=newcon[nv];p;p=p->NEXT)
		{
			int vv=p->v;--rudu[vv];
			if(rudu[vv]==0) dl[++tail]=vv;
		}
	}
}
inline int read()
{
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
	return x*f;
}
int main()
{
	memset(dfn,0,sizeof(dfn));
	memset(rudu,0,sizeof(rudu));
	memset(arr,0,sizeof(arr));
	memset(dp,0,sizeof(dp));
	n=read();m=read();
	while(m--)
		{x=read();y=read();ins(x,y,con);}
	for(int i=1;i<=n;++i)
		if(dfn[i]==0) tarjan(i);
	rebuild();
	top_sort();
	for(int i=tot;i>=1;--i)
	{
		int nv=res[i];
		for(edge *p=newcon[nv];p;p=p->NEXT)
		{
			int vv=p->v;
			dp[nv]=max(dp[nv],dp[vv]);
		}
	}
	for(int i=1;i<=n;++i) printf("%d ",dp[belong[i]]);
	return 0;
}
