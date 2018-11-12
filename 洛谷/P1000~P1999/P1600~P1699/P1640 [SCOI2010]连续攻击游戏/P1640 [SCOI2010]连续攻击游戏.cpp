#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN=1000001;
int n,u,v;
int flag[MAXN];
bool vis[MAXN];
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
	memset(flag,0,sizeof(flag));
	memset(vis,0,sizeof(vis));
	n=read();
	for(int i=1;i<=n;++i)
	{
		u=read();v=read();
		ins(u,i);ins(v,i);
	}
	int ans=1;
	while(Find(ans)&&ans<=n)
	{
		memset(vis,0,sizeof(vis));
		++ans;
	}
	printf("%d",ans-1);
	return 0;
}
