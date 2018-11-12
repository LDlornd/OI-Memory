#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN=2e5+5;
int n,m,u,v,q,qp,qk,visit=0,maxdeep=0;
int in[MAXN],out[MAXN],id[MAXN];
int lg[MAXN],depth[MAXN],fa[20][MAXN];
struct edge{
	int v;
	edge *nex;
	edge() {v=0;nex=NULL;}
}*con[MAXN];
struct segtree *NUL;
struct segtree{
	int Start,End,val;
	segtree *son[2];
	segtree(){
		Start=End=val=0;
		son[0]=son[1]=NUL;
	}
	void update(){
		val=son[0]->val+son[1]->val;
	}
	void build(segtree *last,int nstart,int nend,int key){
		Start=nstart;End=nend;
		if(nstart==nend) {val=last->val+1;return;}
		int mid=(Start+End)>>1,flag=(key>mid);
		son[flag^1]=last->son[flag^1];
		if(flag) (son[1]=new(segtree))->build(last->son[1],mid+1,nend,key);
		else (son[0]=new(segtree))->build(last->son[0],nstart,mid,key);
		update();
	}
	int query(segtree *last,int nstart,int nend,int key){
		if(nstart==nend) return nstart;
		int mid=(Start+End)>>1,flag=son[0]->val-last->son[0]->val;
		if(key<=flag) return son[0]->query(last->son[0],nstart,mid,key);
		else return son[1]->query(last->son[1],mid+1,nend,key-flag);
	}
}*root[MAXN],*rt;
void ins(int Start,int End){
	edge *p=new(edge);
	p->v=End;
	p->nex=con[Start];con[Start]=p;
}
void get_tree(int nv,int father){
	in[nv]=++visit;id[visit]=nv;
	maxdeep=max(maxdeep,(depth[nv]=depth[father]+1));
	fa[0][nv]=father;
	for(edge *p=con[nv];p;p=p->nex){
		if(p->v==father) continue;
		get_tree(p->v,nv);
	}
	out[nv]=visit;
}
int lca(int a,int b){
	if(depth[a]<depth[b]) swap(a,b);
	while(depth[a]>depth[b]) a=fa[lg[depth[a]-depth[b]]][a];
	if(a==b) return a;
	for(int i=lg[depth[a]];i>=0;--i)
		if(fa[i][a]!=fa[i][b]) {a=fa[i][a];b=fa[i][b];}
	return fa[0][a];
}
void get_ready(){
	lg[0]=-1;for(int i=1;i<MAXN;++i) lg[i]=lg[i>>1]+1;
	get_tree(1,0);
	for(int i=1;i<=lg[n];++i)
		for(int j=1;j<=n;++j)
			fa[i][j]=fa[i-1][fa[i-1][j]];
}
int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	freopen("testdata.in","r",stdin);
	n=read();m=read();
	for(int i=1;i<n;++i){
		u=read();v=read();
		ins(u,v);ins(v,u);
	}
	get_ready();
	memset(con,0,sizeof(con));
	while(m--){
		u=read();v=read();
		int temp=lca(u,v);
		ins(u,temp);ins(v,temp);
	}
	NUL=new(segtree);NUL->son[0]=NUL->son[1]=NUL;
	root[0]=new(segtree);
	for(int i=1;i<=n;++i){
		root[i]=root[i-1];
		for(edge *p=con[id[i]];p;p=p->nex){
			(rt=new(segtree))->build(root[i],1,maxdeep,depth[p->v]);
			root[i]=rt;
		}
	}
	q=read();
	while(q--){
		qp=read();qk=read();
		int ans=root[out[qp]]->query(root[in[qp]-1],1,maxdeep,qk);
		if(ans!=0) ans=max(0,depth[qp]-ans);
		printf("%d\n",ans);
	}
	return 0;
}
