#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=200001;
int n,m,l,r,k;
int arr[MAXN],small[MAXN];
struct tree;
tree *NUL;
struct tree{
	int Start,End,val;
	tree *son[2];
	tree() {Start=End=val=0;son[0]=son[1]=NUL;}
	inline void update() {val=son[0]->val+son[1]->val;}
	inline void build(tree *last,int nstart,int nend,int key){
		Start=nstart;End=nend;
		if(nstart==nend) {val=last->val+1;return;}
		int mid=(nstart+nend)>>1;
		bool flag=(key>mid);
		son[flag^1]=last->son[flag^1];
		if(flag) (son[1]=new(tree))->build(last->son[1],mid+1,nend,key);
		else (son[0]=new(tree))->build(last->son[0],nstart,mid,key);
		update();
	}
	inline int query(tree *last,int nstart,int nend,int key){
		if(nstart==nend) return nstart;
		int mid=(nstart+nend)>>1,temp=son[0]->val-last->son[0]->val;
		if(key<=temp) return son[0]->query(last->son[0],nstart,mid,key);
		else return son[1]->query(last->son[1],mid+1,nend,key-temp);	
	}
}*root[MAXN];
inline bool CMP(int a,int b){
	return a<b;
}
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read();m=read();
	for(int i=1;i<=n;++i) small[i]=arr[i]=read();
	sort(small+1,small+n+1,CMP);
	for(int i=1;i<=n;++i)
		arr[i]=lower_bound(small+1,small+n+1,arr[i])-small;
	NUL=new(tree);NUL->son[0]=NUL->son[1]=NUL;
	root[0]=new(tree);
	for(int i=1;i<=n;++i)
		(root[i]=new(tree))->build(root[i-1],1,n,arr[i]);
	while(m--){
		l=read();r=read();k=read();
		printf("%d\n",small[root[r]->query(root[l-1],1,n,k)]);
	}
	return 0;
}
