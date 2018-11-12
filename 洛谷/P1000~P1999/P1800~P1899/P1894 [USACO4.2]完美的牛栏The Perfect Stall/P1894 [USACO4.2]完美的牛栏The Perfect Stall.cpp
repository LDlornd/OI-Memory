#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN=201;
int n1,n2,n,v,ans=0;
int flag[MAXN];
bool vis[MAXN];
struct edge
{
	int v;
	edge *NEXT;
}*con[MAXN];
inline void ins(int start,int end)
{
	edge *p=new(edge);
	p->v=end;
	p->NEXT=con[start];
	con[start]=p;
}
inline bool Find(int place)
{
	for(edge *p=con[place];p;p=p->NEXT)
	{
		int nv=p->v;
		if(vis[nv]==false)
		{
			vis[nv]=true;
			if(flag[nv]==0||Find(flag[nv]))
			{
				flag[nv]=place;
				return true;
			}
		}
	}
	return false;
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
	n1=read();n2=read();
	for(int i=1;i<=n1;++i)
	{
		n=read();
		while(n--)
		{
			v=read();
			ins(i,v);
		}
	}
	for(int i=1;i<=n1;++i)
	{
		memset(vis,0,sizeof(vis));
		if(Find(i)) ++ans;
	}
	printf("%d",ans);
	return 0;
}
