#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN=100001;
int n,m,u,v,visit=0,ans=0;
int root[MAXN],tot=0;
int dfn[MAXN],low[MAXN],num[MAXN];
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
	dfn[nv]=low[nv]=++visit;
	for(edge *p=con[nv];p;p=p->NEXT)
	{
		int vv=p->v;
		if(dfn[vv]==0)
		{
			tarjan(vv);
			low[nv]=min(low[nv],low[vv]);
			if(low[vv]>=dfn[nv]) ++num[nv];
		}
		else low[nv]=min(low[nv],dfn[vv]);
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
	memset(num,0,sizeof(num));
	memset(flag,0,sizeof(flag));
	n=read();m=read();
	while(m--)
	{
		u=read();v=read();
		ins(u,v);ins(v,u);
	}
	for(int i=1;i<=n;++i)
		if(dfn[i]==0) {tarjan(i);root[++tot]=i;}
	for(int i=1;i<=tot;++i)
		if(num[root[i]]!=0) --num[root[i]];
	for(int i=1;i<=n;++i)
		if(num[i]) ++ans;
	printf("%d\n",ans);
	for(int i=1;i<=n;++i)
		if(num[i]) printf("%d ",i);
	return 0;
}
