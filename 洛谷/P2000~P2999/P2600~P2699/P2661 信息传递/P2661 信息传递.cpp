#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
const int MAXN=200001;
struct edge
{
	int v;
	edge *next;
}*con[MAXN];
bool vis[MAXN];
int depth[MAXN],ans=2147483647;
inline void ins(int start,int end)
{
	edge *p=new(edge);
	p->v=end;
	p->next=con[start];
	con[start]=p;
}
inline void dfs(int x,int deep)
{
	for(edge *p=con[x];p!=UNLL;p->next)
	{
		int nv=p->v;
		if(vis[nv]==false)
		{
			vis[nv]=true;
			depth[nv]=deep;
			dfs(nv,deep+1);
		}
		else
		{
			if(deep-depth[nv]<ans) ans=deep-depth[nv];
			return;
		}
	}
}
int main()
{
	int n,x;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&x);
		ins(i,x);
	}
	for(int i=1;i<=n;++i)
	{
		if(vis[i]==false)
		{
			dfs(i,1);
		}
	}
}
