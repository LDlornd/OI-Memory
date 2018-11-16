#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN=5e5+5;
int n,q,rt,u,v;
int LG[MAXN];
int fa[MAXN][20],depth[MAXN];
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
void dfs(int nv,int father){
	depth[nv]=depth[father]+1;
	fa[nv][0]=father;
	for(edge *p=con[nv];p;p=p->nex){
		if(p->v==father) continue;
		dfs(p->v,nv);
	}
}
void init(){
	LG[1]=0;
	for(int i=2;i<=n;++i) LG[i]=LG[i>>1]+1;
	for(int w=1;w<=LG[n];++w)
		for(int i=1;i<=n;++i)
			fa[i][w]=fa[fa[i][w-1]][w-1];
}
int lca(int a,int b){
	if(depth[a]<depth[b]) swap(a,b);
	while(depth[a]>depth[b]) a=fa[a][LG[depth[a]-depth[b]]];
	if(a==b) return a;
	for(int i=LG[depth[a]];i>=0;--i)
		if(fa[a][i]!=fa[b][i]){
			a=fa[a][i];
			b=fa[b][i];
		}
	return fa[a][0];
}
int main(){
	scanf("%d%d%d",&n,&q,&rt);
	for(int i=1;i<n;++i){
		scanf("%d%d",&u,&v);
		ins(u,v);ins(v,u);
	}
	dfs(rt,0);
	init();
	while(q--){
		scanf("%d%d",&u,&v);
		printf("%d\n",lca(u,v));
	}
	return 0;
}
