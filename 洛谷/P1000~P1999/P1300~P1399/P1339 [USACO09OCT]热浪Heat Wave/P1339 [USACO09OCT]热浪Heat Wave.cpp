#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;
const int MAXN=2501;
const int INF=2147483647;
struct edge
{
	int v,len;
	edge *next;
}*con[MAXN];
bool vis[MAXN];
int dist[MAXN];
int dl[MAXN],head=1,tail=1;
inline void ins(int start,int end,int pay)
{
	edge *p=new(edge);
	p->len=pay;
	p->v=end;
	p->next=con[start];
	con[start]=p;
}
int main()
{
	int n,m,x,y,z,START,END;
	scanf("%d%d%d%d",&n,&m,&START,&END);
	for(int i=1;i<=n;++i) {dist[i]=MAXN;vis[i]=false;}
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d%d",&x,&y,&z);
		ins(x,y,z);ins(y,x,z);
	}
	dl[head]=START;vis[START]=true;dist[START]=0;
	while(head-1!=(tail%(MAXN-1)))
	{
		int now=dl[head];
		for(edge *p=con[now];p!=NULL;p=p->next)
		{
			int nv=p->v,nlen=p->len;
			if(dist[nv]>dist[now]+nlen)
			{
				dist[nv]=dist[now]+nlen;
				if(vis[nv]==false)
				{
					if(tail==MAXN-1) tail=1;
					else ++tail;
					dl[tail]=nv;
					vis[nv]=true;
				}
			}
		}
		if(head==MAXN-1) head=1;
		else ++head;
		vis[now]=false;
	}
	printf("%d",dist[END]);
	return 0;
}
