#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN=1e5+5;
int n,q,cnt,k,u,v;
int lg[MAXN];
int depth[MAXN],fa[17][MAXN];
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
void add_edge(int Start,int End){
	ins(Start,End);ins(End,Start);
}
void get_tree(int nv,int father,int deep){
	depth[nv]=deep;
	fa[0][nv]=father;
	for(edge *p=con[nv];p;p=p->nex){
		if(p->v==father) continue;
		get_tree(p->v,nv,deep+1);
	}
}
void init(){
	lg[1]=0;
	for(int i=2;i<=n;++i) lg[i]=lg[i>>1]+1;
	for(int i=1;i<=lg[n];++i)
		for(int j=1;j<=n;++j)
			fa[i][j]=fa[i-1][fa[i-1][j]];	
}
int get_lca(int a,int b){
	if(depth[a]<depth[b]) swap(a,b);
	while(depth[a]>depth[b])
		a=fa[lg[depth[a]-depth[b]]][a];
	if(a==b) return a;
	for(int i=lg[depth[a]];i>=0;i--){
		if(fa[i][a]==fa[i][b]) continue;
		a=fa[i][a];b=fa[i][b];
	}
	return fa[0][a];
}
int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read();q=read();
	for(int i=1;i<=n;++i){
		cnt=read();
		while(cnt--){
			k=read();
			add_edge(i,k);	
		}
	}
	get_tree(1,0,1);
	init();
	while(q--){
		u=read();v=read();
		int tmp=get_lca(u,v);
		if(tmp==u) printf("1.000\n");
		else if(tmp==v) printf("0.000\n");
		else printf("0.500\n");
	}
	return 0;
}
