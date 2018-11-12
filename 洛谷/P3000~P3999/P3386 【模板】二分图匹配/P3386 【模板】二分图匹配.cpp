#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
const int MAXN=1001;
struct edge
{
	int v;
	edge *NEXT;
	edge() {v=0;NEXT=NULL;}
}*con[MAXN];
bool Search[MAXN];
int flag[MAXN];
int n1,n2,e,u,v,ans=0;
inline void ins(int start,int end)
{
	if(start>n1||end>n2) return;
	edge *p=new(edge);
	p->v=end;
	p->NEXT=con[start];
	con[start]=p;
}
inline bool Find(int nv)
{
	for(edge *p=con[nv];p;p=p->NEXT)
	{
		int vv=p->v;
		if(Search[vv]==false)
		{
			Search[vv]=true;
			if(flag[vv]==0||Find(flag[vv]))
			{
				flag[vv]=nv;
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
	n1=read(),n2=read(),e=read();
	while(e--) ins(u=read(),v=read());
	for(int i=1;i<=n1;++i)
	{
		memset(Search,0,sizeof(Search));
		if(Find(i)) ++ans;
	}
	printf("%d",ans);
	return 0;
}
