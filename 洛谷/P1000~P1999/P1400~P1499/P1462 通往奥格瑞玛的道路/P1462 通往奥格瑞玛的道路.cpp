#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
const int MAXN=10001;
const int INF=2147483647;
struct edge
{
	int v,bleed;
	edge *next;
	edge() {next=NULL;}
}*con[MAXN];
bool vis[MAXN];
long long int cost[MAXN],dist[MAXN];
int n,m,x,y,z,blood_max,cost_max=0;
inline void ins(int start,int end,int length)
{
	edge *p=new(edge);
	p->bleed=length;
	p->v=end;
	p->next=con[start];
	con[start]=p;
}
inline void spfa(int a)
{
	memset(vis,0,sizeof(vis));
	for(int i=2;i<=n;++i) dist[i]=INF;
	int dl[MAXN],head=1,tail=1;
	dl[tail]=1;vis[1]=true;dist[1]=0;
	while(head-1!=tail%(MAXN-1))
	{
		int now=dl[head];
		for(edge *p=con[now];p!=NULL;p=p->next)
		{
			int nv=p->v,ncost=p->bleed;
			if(cost[nv]>a) continue;
			if(dist[nv]>dist[now]+ncost)
			{
				dist[nv]=dist[now]+ncost;
				if(vis[nv]==false)
				{
					if(tail==MAXN-1) tail=1;
					else ++tail;
					dl[tail]=nv;vis[nv]=true;
				}
			}
		}
		if(head==MAXN-1) head=1;
		else ++head;
		vis[now]=false;
	}
}
inline bool judge(int a)
{
	spfa(a);
	if(dist[n]>blood_max) return false;
	else return true;
}
int main()
{
	scanf("%d%d%d",&n,&m,&blood_max);
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",&cost[i]);
		if(cost_max<cost[i]) cost_max=cost[i];
	}
	for(int i=0;i<m;++i)
	{
		scanf("%d%d%d",&x,&y,&z);
		ins(x,y,z);ins(y,x,z);
	}
	int l=0,r=cost_max,ans=-1;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(judge(mid))
		{
			ans=mid;
			r=mid;
		}
		else l=mid+1;
	}
	if(judge(l)) ans=l;
	if(ans==-1) printf("AFK");
	else printf("%d",ans);
	return 0;
}
