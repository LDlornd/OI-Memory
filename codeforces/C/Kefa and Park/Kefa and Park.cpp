#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int MAXN=100001;
bool flag[MAXN],vis[MAXN];
int n,m,x,y,ans=0,tot=0;
int chudu[MAXN];
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
inline void dfs(int np)
{
	if(tot>m) return;
	if(chudu[np]==1)
		if(!(np==1&&n!=1)) {++ans;return;}
	for(edge *p=con[np];p!=NULL;p=p->NEXT)
	{
		int nv=p->v,temp=tot;
		if(vis[nv]==false)
		{
			vis[nv]=true;
			if(flag[nv]) ++tot;
			else tot=0;
			dfs(nv);
			vis[nv]=false;
			if(flag[nv]) --tot;
			else tot=temp;
		}
	}
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
	memset(vis,0,sizeof(vis));
	memset(chudu,0,sizeof(chudu));
	n=read();m=read();
	for(int i=1;i<=n;++i)
		flag[i]=read();
	for(int i=1;i<n;++i)
	{
		x=read();y=read();
		ins(x,y);ins(y,x);
		++chudu[y];++chudu[x];
	}
	if(flag[1]) tot=1;
	vis[1]=true;
	dfs(1);
	printf("%d",ans);
	return 0;
}
