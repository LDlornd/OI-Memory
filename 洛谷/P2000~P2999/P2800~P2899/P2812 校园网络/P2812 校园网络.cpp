#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN=10001;
int n,u,visit=0,tot=0,ans=0;
int zhan[MAXN],top=0;
int dfn[MAXN],low[MAXN],belong[MAXN];
int rudu[MAXN],dp[MAXN],maxdist=0;
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
	zhan[++top]=nv;
	flag[nv]=true;
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
		++tot;
		do
		{
			place=zhan[top--];
			belong[place]=tot;
			flag[place]=false;
		}while(place!=nv);
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
	memset(flag,0,sizeof(flag));
	memset(rudu,0,sizeof(rudu));
	memset(dp,0,sizeof(dp));
	n=read();
	for(int i=1;i<=n;++i)
		while(true)
		{
			u=read();
			if(u==0) break;
			ins(i,u,con);
		}
	for(int i=1;i<=n;++i)
		if(dfn[i]==0) tarjan(i);
	for(int i=1;i<=n;++i)
		for(edge *p=con[i];p;p=p->NEXT)
		{
			int now=p->v;
			if(belong[now]!=belong[i]) {ins(belong[i],belong[now],newcon);++rudu[i];}
		}
	for(int i=1;i<=tot;++i)
		for(edge *p=newcon[i];p;p=p->NEXT)
		{
			int now=p->v;
			dp[now]=max(dp[now],dp[i]+1);
		}
	for(int i=1;i<=tot;++i)
	{
		if(rudu[i]==0) ++ans;
		maxdist=max(maxdist,dp[i]);
	}
	printf("%d\n%d",ans,tot-maxdist);
	return 0;
}
