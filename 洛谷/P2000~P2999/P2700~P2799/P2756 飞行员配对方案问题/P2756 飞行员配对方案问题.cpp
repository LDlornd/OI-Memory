#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=250;
int n1,n2,u,v,ans=0,tot=1;
int flag[MAXN];
bool vis[MAXN];
struct num
{
	int p,data;
	num() {p=0;data=0;}
}NUM[MAXN];
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
inline bool CMP(const num &a,const num &b)
{
	return a.data<b.data;
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
	n1=read();n2=read();
	while(true)
	{
		u=read();v=read();
		if(u==-1&&v==-1) break;
		else ins(u,v);
	}
	for(int i=1;i<=n1;++i)
	{
		memset(vis,0,sizeof(vis));
		if(Find(i)) ++ans;
	}
	if(ans==0) printf("No Solution!");
	else
	{
		printf("%d\n",ans);
		for(int i=n1+1;i<=n2;++i)
			if(flag[i])
				{NUM[tot].data=flag[i];NUM[tot++].p=i;}
		sort(NUM+1,NUM+tot,CMP);
		for(int i=1;i<tot;++i)
			printf("%d %d\n",NUM[i].data,NUM[i].p);
	}
	return 0;
}
