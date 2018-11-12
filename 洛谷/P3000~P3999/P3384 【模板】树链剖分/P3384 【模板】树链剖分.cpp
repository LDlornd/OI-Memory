#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN=1e5+1;
int n,m,r,mod,opt,x,y,z,cnt=0;
int arr[MAXN];
int id[MAXN],newarr[MAXN],top[MAXN];
int depth[MAXN],fa[MAXN],Size[MAXN],heavy[MAXN];
struct edge{
	int v;
	edge *Next;
}*con[MAXN];
struct segtree{
	int Start,End,val,lazy;
	segtree *leftson,*rightson;
	segtree(){
		Start=End=val=lazy=0;
		leftson=rightson=NULL;
	}
	inline void update() {val=(leftson->val+rightson->val)%mod;}
	inline void caculate(int key) {val+=(End-Start+1)*key;}
	inline void push_down(){
		leftson->caculate(lazy);rightson->caculate(lazy);
		leftson->lazy+=lazy;rightson->lazy+=lazy;
		lazy=0;
	}
	inline void build(int nstart,int nend){
		Start=nstart;End=nend;
		if(nstart==nend){val=newarr[nstart]%mod;return;}
		int mid=(nstart+nend)>>1;
		(leftson=new(segtree))->build(nstart,mid);
		(rightson=new(segtree))->build(mid+1,nend);
		update();
	}
	inline void modify(int nstart,int nend,int key){
		if(Start==nstart&&End==nend){
			caculate(key);lazy+=key;
			return;
		}
		push_down();
		int mid=(Start+End)>>1;
		if(nend<=mid) leftson->modify(nstart,nend,key);
		else if(nstart>mid) rightson->modify(nstart,nend,key);
		else {leftson->modify(nstart,mid,key);rightson->modify(mid+1,nend,key);}
		update();
	}
	inline int query(int nstart,int nend){
		if(Start==nstart&&End==nend) return val%mod;
		push_down();
		int mid=(Start+End)>>1;
		if(nend<=mid) return leftson->query(nstart,nend)%mod;
		else if(nstart>mid) return rightson->query(nstart,nend)%mod;
		else return (leftson->query(nstart,mid)+rightson->query(mid+1,nend))%mod;
	}
}*root;
inline void ins(int nstart,int nend){
	edge *p=new(edge);
	p->v=nend;
	p->Next=con[nstart];
	con[nstart]=p;
}
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
inline void dfs_1(int nv,int father,int deep){
	depth[nv]=deep;fa[nv]=father;Size[nv]=1;
	int maxson=-1;
	for(edge *p=con[nv];p;p=p->Next){
		int vv=p->v;
		if(vv==father) continue;
		dfs_1(vv,nv,deep+1);
		Size[nv]+=Size[vv];
		if(Size[vv]>maxson) {heavy[nv]=vv;maxson=Size[vv];}
	}
}
inline void dfs_2(int nv,int Root){
	id[nv]=++cnt;
	newarr[cnt]=arr[nv];
	top[nv]=Root;
	if(heavy[nv]==0) return;
	dfs_2(heavy[nv],Root);
	for(edge *p=con[nv];p;p=p->Next){
		int vv=p->v;
		if(fa[nv]==vv||heavy[nv]==vv) continue;
		dfs_2(vv,vv);
	}
}
inline void patch_add(){
	x=read();y=read();z=read();
	while(top[x]!=top[y]){
		if(depth[top[x]]<depth[top[y]]) swap(x,y);
		root->modify(id[top[x]],id[x],z);
		x=fa[top[x]];
	}
	if(depth[x]<depth[y]) swap(x,y);
	root->modify(id[y],id[x],z);
}
inline void patch_query(){
	int temp=0;
	x=read();y=read();
	while(top[x]!=top[y]){
		if(depth[top[x]]<depth[top[y]]) swap(x,y);
		(temp+=root->query(id[top[x]],id[x]))%=mod;
		x=fa[top[x]];
	}
	if(depth[x]<depth[y]) swap(x,y);
	(temp+=root->query(id[y],id[x]))%=mod;
	printf("%d\n",temp);
}
inline void tree_add(){
	x=read();z=read();
	root->modify(id[x],id[x]+Size[x]-1,z);
}
inline void tree_query(){
	x=read();
	printf("%d\n",root->query(id[x],id[x]+Size[x]-1));
}
int main(){
	n=read();m=read();r=read();mod=read();
	for(int i=1;i<=n;++i) arr[i]=read();
	for(int i=1;i<n;++i){
		x=read();y=read();
		ins(x,y);ins(y,x);
	}
	dfs_1(r,0,1);
	dfs_2(r,r);
	(root=new(segtree))->build(1,n);
	while(m--){
		opt=read();
		if(opt==1) patch_add();
		if(opt==2) patch_query();
		if(opt==3) tree_add();
		if(opt==4) tree_query();
	}
	return 0;
}
