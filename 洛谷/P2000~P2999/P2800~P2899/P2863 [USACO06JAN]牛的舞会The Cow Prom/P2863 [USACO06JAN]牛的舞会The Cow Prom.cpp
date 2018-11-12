#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN=10001;
int n,m,u,v,sum=0,tot=0,ans=0;
int dfn[MAXN],low[MAXN],belong[MAXN],num[MAXN];
int zhan[MAXN],top=0;
bool vis[MAXN],flag[MAXN];
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
	dfn[nv]=low[nv]=++sum;
	zhan[++top]=nv;
	flag[nv]=true;
	for(edge *p=con[nv];p;p=p->NEXT)
	{
		int vv=p->v;
		if(vis[vv]==false)
		{
			vis[vv]=true;
			tarjan(vv);
			low[nv]=min(low[nv],low[vv]);
		}
		else if(flag[vv]) low[nv]=min(low[nv],dfn[vv]);
	}
	if(dfn[nv]==low[nv])
	{
		++tot;
		int place;
		do
		{
			++num[tot];
			place=zhan[top--];
			flag[place]=false;
			belong[place]=tot;
		}while(nv!=place);
	}
}
inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
	return x*f;
}
int main()
{
	memset(num,0,sizeof(num));
	memset(vis,0,sizeof(vis));
	memset(flag,0,sizeof(flag));
	n=read();m=read();
	while(m--)
	{
		u=read();v=read();
		ins(u,v);
	}
	for(int i=1;i<=n;++i)
		if(vis[i]==false)
			tarjan(i);
	for(int i=1;i<=n;++i)
		if(num[i]>1) ++ans;
	for(int i=1;i<=n;++i)
		printf("%d ",belong[i]);
	printf("\n");
	cout<<tot<<endl;
	printf("%d",ans);
	return 0;
}
