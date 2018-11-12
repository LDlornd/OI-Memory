#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN=10005;
int n,m,u,v,visit=0,tot=0,maxans=0;
int Q[MAXN],newQ[MAXN];
int rudu[MAXN],res[MAXN],num=0;
int dfn[MAXN],low[MAXN],belong[MAXN];
int zhan[MAXN],top=0;
int dl[MAXN],head,tail;
int dp[MAXN];
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
		++tot;zhan[top+1]=0;
		while(zhan[top+1]!=nv){
			int place=zhan[top--];
			belong[place]=tot;
			flag[place]=false;
		}
	}
}
inline void top_sort(edge *a[])
{
	head=1;tail=0;
	for(int i=1;i<=tot;++i)
		if(rudu[i]==0) dl[++tail]=i;
	while(head<=tail)
	{
		int nv=dl[head];
		res[++num]=nv;
		for(edge *p=a[nv];p;p=p->NEXT)
		{
			int vv=p->v;--rudu[vv];
			if(rudu[vv]==0) dl[++tail]=vv;
		}
		++head;
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
	memset(newQ,0,sizeof(newQ));
	memset(rudu,0,sizeof(rudu));
	memset(dfn,0,sizeof(dfn));
	memset(flag,0,sizeof(flag));
	n=read();m=read();
	for(int i=1;i<=n;++i) Q[i]=read();
	while(m--)
	{
		u=read();v=read();
		ins(u,v,con);
	}
	for(int i=1;i<=n;++i)
		if(dfn[i]==0) tarjan(i);
	for(int i=1;i<=n;++i)
	{
		newQ[belong[i]]+=Q[i];
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
	top_sort(newcon);
	for(int i=1;i<=tot;++i) dp[i]=newQ[i];
	for(int i=1;i<=tot;++i)
		for(edge *p=newcon[res[i]];p;p=p->NEXT)
		{
			int now=p->v;
			dp[now]=max(dp[now],dp[res[i]]+newQ[now]);
		}
	for(int i=1;i<=tot;++i) maxans=max(maxans,dp[i]);
	printf("%d",maxans);
	return 0;
}
