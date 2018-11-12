#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN=100001;
char opt;
int n,m,u,v,k,cnt=0;
int color[MAXN],newcolor[MAXN];
int id[MAXN],depth[MAXN],fa[MAXN],Size[MAXN],heavy[MAXN],top[MAXN];
struct edge{
	int v;
	edge *nex;
	edge() {v=0;nex=NULL;}
}*con[MAXN];
struct segtree{
	int Left,Right,lc,rc,val,lazy;
	segtree *son[2];
	segtree() {Left=Right=lc=rc=val=lazy=0;son[0]=son[1]=NULL;}
	inline void update(){
		lc=son[0]->lc;rc=son[1]->rc;
		if(son[0]->rc==son[1]->lc) val=son[0]->val+son[1]->val-1;
		else val=son[0]->val+son[1]->val;
	}
	inline void caculate(int key){
		val=1;lc=rc=lazy=key;
	}
	inline void pushdown(){
		son[0]->caculate(lazy);
		son[1]->caculate(lazy);
		lazy=0;
	}
	inline void build(int Start,int End){
		Left=Start;Right=End;
		if(Start==End) {lc=rc=newcolor[Start];val=1;return;}
		int mid=(Start+End)>>1;
		(son[0]=new(segtree))->build(Start,mid);
		(son[1]=new(segtree))->build(mid+1,End);
		update();
	}
	inline void modify(int Start,int End,int key){
		if(Left==Start&&Right==End){
			caculate(key);return;
		}
		if(lazy) pushdown();
		int mid=(Left+Right)>>1;
		if(End<=mid) son[0]->modify(Start,End,key);
		else if(Start>mid) son[1]->modify(Start,End,key);
		else {son[0]->modify(Start,mid,key);son[1]->modify(mid+1,End,key);}
		update();
	}
	inline int query(int Start,int End){
		if(Start==0||End==0) return 0;
		if(Left==Start&&Right==End) return val;
		if(lazy) pushdown();
		int mid=(Left+Right)>>1;
		if(End<=mid) return son[0]->query(Start,End);
		else if(Start>mid) return son[1]->query(Start,End);
		else{
			if(son[0]->rc==son[1]->lc) return son[0]->query(Start,mid)+son[1]->query(mid+1,End)-1;
			else return son[0]->query(Start,mid)+son[1]->query(mid+1,End);
		}
	}
	inline int query_color(int place){
		if(place==0) return 0;
		if(Left==place&&Right==place) return lc;
		if(lazy) pushdown();
		int mid=(Left+Right)>>1;
		if(place<=mid) return son[0]->query_color(place);
		else return son[1]->query_color(place);
	}
}*root;
inline void ins(int Start,int End){
	edge *p=new(edge);
	p->v=End;p->nex=con[Start];con[Start]=p;
}
inline void dfs1(int nv,int father,int deep){
	depth[nv]=deep;fa[nv]=father;Size[nv]=1;
	int maxson=-1;
	for(edge *p=con[nv];p;p=p->nex){
		int vv=p->v;
		if(vv==father) continue;
		dfs1(vv,nv,deep+1);
		Size[nv]+=Size[vv];
		if(Size[vv]>maxson) {maxson=Size[vv];heavy[nv]=vv;}
	}
}
inline void dfs2(int nv,int Root){
	id[nv]=(++cnt);
	newcolor[cnt]=color[nv];
	top[nv]=Root;
	if(heavy[nv]==0) return;
	dfs2(heavy[nv],Root);
	for(edge *p=con[nv];p;p=p->nex){
		if(p->v==fa[nv]||p->v==heavy[nv]) continue;
		dfs2(p->v,p->v);
	}
}
inline void patch_modify(int a,int b,int key){
	while(top[a]!=top[b]){
		if(depth[top[a]]<depth[top[b]]) swap(a,b);
		root->modify(id[top[a]],id[a],key);
		a=fa[top[a]];
	}
	if(depth[a]>depth[b]) swap(a,b);
	root->modify(id[a],id[b],key);
}
inline int patch_query(int a,int b){
	int temp=0;
	while(top[a]!=top[b]){
		if(depth[top[a]]<depth[top[b]]) swap(a,b);
		temp+=root->query(id[top[a]],id[a]);
		if(root->query_color(id[top[a]])==root->query_color(id[fa[top[a]]])) --temp;
		a=fa[top[a]];
	}
	if(depth[a]>depth[b]) swap(a,b);
	temp+=root->query(id[a],id[b]);
	return temp;
}
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read();m=read();
	for(int i=1;i<=n;++i) color[i]=read();
	for(int i=1;i<n;++i){
		u=read();v=read();
		ins(u,v);ins(v,u);
	}
	dfs1(1,0,1);
	dfs2(1,1);
	(root=new(segtree))->build(1,n);
	while(m--){
		opt=getchar();
		while(opt!='Q'&&opt!='C') opt=getchar();
		u=read();v=read();
		if(opt=='Q') printf("%d\n",patch_query(u,v));
		if(opt=='C') {k=read();patch_modify(u,v,k);}
	}
	return 0;
}
