#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
const int MAXN=1000001;
const int INF=2147483647;
struct edge
{
	int v;
	edge *next;
	edge() {next=NULL;}
}*con[MAXN];
bool vis[MAXN];
int n,m,x,y,head=1,tail=1;
int dis[MAXN],num[MAXN],dl[MAXN];
inline void ins(int start,int end)
{
	edge *p=new(edge);
	p->v=end;
	p->next=con[start];
	con[start]=p;
}
void spfa()
{
	memset(vis,0,sizeof(vis));
	for(int i=2;i<=n;++i) dis[i]=INF;
	dis[1]=0;vis[1]=true;dl[head]=1;num[1]=1;
	while((head-1)!=tail%(MAXN-1))
	{
		int nv=dl[head];
		for(edge *p=con[nv];p!=NULL;p=p->next)
		{
			int now=p->v;
			if(dis[now]>dis[nv]+1)
			{
				num[now]=num[nv];
				dis[now]=dis[nv]+1;
				if(vis[now]==false)
				{
					if(tail==MAXN-1) tail=1;
					else ++tail;
					dl[tail]=now;
					vis[now]=true;
				}
			}
			else if(dis[now]==dis[nv]+1)
				{num[now]+=num[nv];num[now]%=100003;}
		}
		vis[nv]=false;
		if(head==MAXN-1) head=1;
		else ++head;
	}
}
int main()
{
	memset(num,0,sizeof(num));
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;++i)
	{
		scanf("%d%d",&x,&y);
		if(x==y) continue;
		else {ins(x,y);ins(y,x);}
	}
	spfa();
	for(int i=1;i<=n;++i)
		printf("%d\n",num[i]);
	return 0;
}
