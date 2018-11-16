#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN=20005;
int n,m,u,v,visit=0,ans=0;
int dfn[MAXN],low[MAXN];
bool cut[MAXN];
struct edge{
	int v;
	edge *nex;
	edge() {v=0;nex=NULL;}
}*con[MAXN];
void ins(int Start,int End){
	edge *p=new(edge);
	p->v=End;
	p->nex=con[Start];con[Start]=p;
}
void tarjan(int nv,int father){
	dfn[nv]=low[nv]=++visit;
	int cnt=0;
	for(edge *p=con[nv];p;p=p->nex){
		if(dfn[p->v]==0){
			tarjan(p->v,nv);
			low[nv]=min(low[nv],low[p->v]);
			if(low[p->v]>=dfn[nv]&&nv!=father) cut[nv]=true;
			if(nv==father) ++cnt;
		}
		low[nv]=min(low[nv],dfn[p->v]);
	}
	if(nv==father&&cnt>=2) cut[nv]=true;
}
int main(){
	scanf("%d%d",&n,&m);
	while(m--){
		scanf("%d%d",&u,&v);
		ins(u,v);ins(v,u);
	}
	for(int i=1;i<=n;++i)
		if(dfn[i]==0) tarjan(i,i);
	for(int i=1;i<=n;++i)
		if(cut[i]) ++ans;
	printf("%d\n",ans);
	for(int i=1;i<=n;++i)
		if(cut[i]) printf("%d ",i);
}
