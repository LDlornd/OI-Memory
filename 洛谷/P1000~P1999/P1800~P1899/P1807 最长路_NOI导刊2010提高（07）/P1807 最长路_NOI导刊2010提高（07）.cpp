#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
const int MAXN=1501;
const int INF=1e9;
struct edge
{
	int v,length;
	edge *next;
	edge() {next=NULL;}
}*con[MAXN];
int rudu[MAXN],ans[MAXN];
int result[MAXN],head=1,tail=1;
inline void ins(int start,int end,int len)
{
	edge *p=new(edge);
	p->length=len;
	p->v=end;
	p->next=con[start];
	con[start]=p;
	++rudu[end];
}
int main()
{
	memset(ans,-1,sizeof(ans));
	memset(rudu,0,sizeof(rudu));
	int n,m,x,y,v;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;++i)
	{
		scanf("%d%d%d",&x,&y,&v);
		ins(x,y,v);
	}
	for(int i=1;i<=n;++i)
		if(rudu[i]==0) result[tail++]=i;
	while(head-1!=tail%(MAXN-1))
	{
		int nv=result[head];
		for(edge *p=con[nv];p!=NULL;p=p->next)
		{
			int now=p->v;
			--rudu[now];
			if(rudu[now]==0) result[tail++]=now;
		}
		++head;
	}
	for(int i=n;i>=1;--i)
	{
		int nv=result[i];
		for(edge *p=con[nv];p!=NULL;p=p->next)
		{
			if(p->v==n) ans[p->v]=0;
			if(ans[p->v]!=-1) ans[nv]=max(ans[nv],ans[p->v]+p->length);
		}
	}
	printf("%d",ans[1]);
	return 0;
}
