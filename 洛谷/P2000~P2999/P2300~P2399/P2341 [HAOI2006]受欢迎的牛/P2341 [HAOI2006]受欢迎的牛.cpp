#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN=10001;
int n,m,u,v,p,visit=0,tot=0,sum=0;
int zhan[MAXN],top=0;
int dfn[MAXN],low[MAXN],belong[MAXN],num[MAXN];
int rudu[MAXN],vis[MAXN];
bool flag[MAXN];
struct edge
{
	int v;
	edge *NEXT;
	edge() {v=0;NEXT=NULL;}
}*con[MAXN];
inline void ins(int start,int end)
{
	edge *p=new(edge);
	p->v=end;
	p->NEXT=con[start];
	con[start]=p;
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
		++tot;
		do
		{
			++num[tot];
			place=zhan[top--];
			flag[place]=false;
			belong[place]=tot;
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
	memset(low,0,sizeof(low));
	memset(num,0,sizeof(num));
	memset(rudu,0,sizeof(rudu));
	memset(flag,0,sizeof(flag));
	n=read();m=read();
	while(m--)
	{
		u=read();v=read();
		ins(u,v);
	}
	for(int i=1;i<=n;++i)
		if(dfn[i]==0) tarjan(i);
	for(int i=1;i<=n;++i)
		for(edge *p=con[i];p;p=p->NEXT)
		{
			int nv=p->v;
			if(belong[i]!=belong[nv])
				++rudu[belong[i]];
		}
	for(int i=1;i<=tot;++i)
		if(rudu[i]==0) {++sum;p=i;}
	if(sum==1) printf("%d",num[p]);
	else printf("0");
	return 0;
}
