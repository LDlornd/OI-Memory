#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib> 
using namespace std;
const int MAXN1=10001;
const int MAXN2=100001;
struct edge
{
	int v,color;
	edge *next;
	edge() {next=NULL;color=0;}
}*con[MAXN1];
bool flag=false;
int vis[MAXN1];
int n,m,x,y;
int color1=0,color2=0,ans;
inline void ins(int start,int end)
{
	edge *p=new(edge);
	p->v=end;
	p->next=con[start];
	con[start]=p;
}
inline void dfs(int now)
{
	for(edge *p=con[now];p!=NULL;p=p->next)
	{
		int nv=p->v;
		if(con[nv]->color==con[now]->color&&con[now]->color!=0) {flag=true;return;}
		if(vis[nv]==false)
		{
			if(con[now]->color==1) {con[nv]->color=2;++color2;}
			else {con[nv]->color=1;++color1;}
			vis[nv]=true;
			dfs(nv);
			if(flag) return;
		}
	}
}
int main()
{
	memset(vis,0,sizeof(vis));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d",&x,&y);
		ins(x,y);ins(y,x);
	}
	for(int i=1;i<=n;++i)
		if(vis[i]==false)
		{
			color1=color2=0;
			dfs(i);
			if(color1<color2) ans+=color1;
			else ans+=color2;
		}
	if(flag) printf("Impossible");
	else printf("%d",ans);
	return 0;
}
