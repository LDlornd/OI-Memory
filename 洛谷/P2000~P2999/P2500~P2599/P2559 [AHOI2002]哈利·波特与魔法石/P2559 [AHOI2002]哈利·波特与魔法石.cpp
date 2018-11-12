#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN=101;
const int INF=2147483647;
int n,start,end,u,v,kind,flag;
int cost[8]={0,2,6,4,8,6,10,14};
int dist[MAXN],vis[MAXN];
int dl[MAXN],head=1,tail=1;
struct edge
{
	int v,len;
	edge *NEXT;
	edge() {v=len=0;NEXT=NULL;}
}*con[MAXN];
inline void ins(int pstart,int pend,int val)
{
	edge *p=new(edge);
	p->v=pend;p->len=val;
	p->NEXT=con[pstart];
	con[pstart]=p;
}
inline void spfa()
{
	memset(vis,0,sizeof(vis));
	for(int i=1;i<MAXN;++i) dist[i]=INF;
	vis[start]=1;dist[start]=0;
	dl[tail++]=start;
	while((head-1)!=tail%(MAXN-1))
	{
		int nv=dl[head];
		for(edge *p=con[nv];p;p=p->NEXT)
		{
			int vv=p->v,nlen=p->len;
			if(dist[vv]>dist[nv]+nlen)
			{
				dist[vv]=dist[nv]+nlen;
				if(vis[vv]==0)
				{
					vis[vv]=1;dl[tail]=vv;
					if(tail==MAXN-1) tail=1;
					else ++tail;
				}
			}
		}
		if(head==MAXN-1) head=1;
		else ++head;
		vis[nv]=0;
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
	for(int i=1;i<=7;++i)
		if((flag=read())==1) cost[i]/=2;
	start=read();end=read();n=read();
	while(n--)
	{
		u=read();v=read();kind=read();
		ins(u,v,cost[kind]);
		ins(v,u,cost[kind]);
	}
	spfa();
	printf("%d",dist[end]);
	return 0;
}
