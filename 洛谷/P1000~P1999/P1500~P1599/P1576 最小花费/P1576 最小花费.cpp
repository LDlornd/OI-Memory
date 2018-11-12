#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;
const int MAXN=2001;
const int INF=2147483647;
struct edge
{
	int v,cost;
	edge *next;
}*con[MAXN];
inline void ins(int start,int end,int pay)
{
	edge *p=new(edge);
	p->cost=pay;
	p->v=end;
	p->next=con[start];
	con[start]=p;
}
bool vis[MAXN];
double dist[MAXN];
int dl[MAXN],head=1,tail=1;
int main()
{
	int n,m,x,y,z,a,b;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) {dist[i]=INF;vis[i]=true;}
	for(int i=0;i<m;++i)
	{
		scanf("%d%d%d",&x,&y,&z);
		ins(x,y,z);ins(y,x,z);
	}
	scanf("%d%d",&a,&b);
	dl[tail]=b;dist[b]=100;
	while(head-1!=(tail%(MAXN-1)))
	{
		int now=dl[head];
		for(edge *p=con[now];p!=NULL;p=p->next)
		{
			int nv=p->v,nc=p->cost;
			if(dist[nv]>dist[now]*100.0/(100-nc))
			{
				dist[nv]=dist[now]*100.0/(100-nc);
				if(vis[nv])
				{
					if(tail==MAXN-1) tail=1;
					else ++tail;
					dl[tail]=nv;
					vis[nv]=false;
				}
			}
		}
		if(head==MAXN-1) head=1;
		else ++head;
		vis[now]=true;
	}
	printf("%.8lf",dist[a]);
	return 0;
}
