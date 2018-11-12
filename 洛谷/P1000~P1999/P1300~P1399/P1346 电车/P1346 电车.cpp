#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
const int MAXN=101;
const int INF=2147483647;
struct edge
{
	int v,worth;
	edge *next;
	edge() {next=NULL;}
}*con[MAXN];
bool vis[MAXN];
int dist[MAXN];
inline void ins(int start,int end,int length)
{
	edge *p=new(edge);
	p->v=end;
	p->worth=length;
	p->next=con[start];
	con[start]=p;
}
void spfa(int start)
{
	for(int i=1;i<MAXN;++i) dist[i]=INF;
	int dl[MAXN],head=1,tail=1;
	dist[start]=0;vis[start]=true;
	dl[tail]=start;
	while(head-1!=tail%(MAXN-1))
	{
		int k=dl[head];
		for(edge *p=con[k];p!=NULL;p=p->next)
		{
			int nv=p->v,nlen=p->worth;
			if(dist[nv]>dist[k]+nlen)
			{
				dist[nv]=dist[k]+nlen;
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
		vis[k]=false;
	}
}
int main()
{
	memset(vis,0,sizeof(vis));
	int n,num,dest,from,to;
	scanf("%d%d%d",&n,&from,&to);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&num);
		for(int j=0;j<num;++j)
		{
			scanf("%d",&dest);
			if(j==0) ins(i,dest,0);
			else ins(i,dest,1);
		}
	}
	//if(dist[to])
	spfa(from);
	if(dist[to]==2147483647) printf("-1");
	else printf("%d",dist[to]);
	return 0;
}
