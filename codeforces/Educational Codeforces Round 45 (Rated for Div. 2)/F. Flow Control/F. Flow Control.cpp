#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN=2e5+5;
int n,m,sum=0,u,v;
int need[MAXN],ans[MAXN];
int fa[MAXN],siz[MAXN];
struct edge{
	int v,id,k;
	edge *nex;
}*con[MAXN];
void ins(int Start,int End,int ID,int key){
	edge *p=new(edge);
	p->v=End;p->id=ID;p->k=key;
	p->nex=con[Start];con[Start]=p;
}
int getfa(int a){
	if(fa[a]==a) return a;
	else return fa[a]=getfa(fa[a]);
}
void Merge(int a,int b){
	a=getfa(a);b=getfa(b);
	if(siz[a]<siz[b]) swap(a,b);
	fa[b]=a;siz[a]+=siz[b];
}
void init(){
	for(int i=1;i<=n;++i){
		fa[i]=i;siz[i]=1;
	}
}
void dfs(int nv,int father){
	for(edge *p=con[nv];p;p=p->nex){
		if(p->v==father) continue;
		dfs(p->v,nv);
		ans[p->id]=p->k*need[p->v];
		need[nv]+=need[p->v];
	}
}
int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		need[i]=read();
		sum+=need[i];
	}
	if(sum!=0){
		printf("Impossible");
		return 0;
	}
	init();
	m=read();
	for(int i=1;i<=m;++i){
		u=read();v=read();
		if(getfa(u)==getfa(v)) continue;
		Merge(u,v);
		ins(u,v,i,1);ins(v,u,i,-1);
	}
	dfs(1,0);
	printf("Possible\n");
	for(int i=1;i<=m;++i) printf("%d\n",ans[i]);
	return 0;
}
