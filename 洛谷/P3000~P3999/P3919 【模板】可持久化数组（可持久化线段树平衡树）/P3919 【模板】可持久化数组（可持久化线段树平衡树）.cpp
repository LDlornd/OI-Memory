#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN=1e6+10;
int n,m,v,opt,p,k,edtion=0;
int arr[MAXN];
struct segtree{
	int Start,End,val;
	segtree *son[2];
	segtree() {Start=End=val=0;son[0]=son[1]=NULL;}
	inline void build(int nstart,int nend){
		Start=nstart;End=nend;
		if(Start==End) {val=arr[nstart];return;}
		int mid=(Start+End)>>1;
		(son[0]=new(segtree))->build(nstart,mid);
		(son[1]=new(segtree))->build(mid+1,nend);
	}
	inline void modify(segtree *last,int place,int key){
		Start=last->Start;End=last->End;
		if(Start==End&&Start==place) {val=key;return;}
		int flag=(Start+End)<(2*place);
		son[flag^1]=last->son[flag^1];
		(son[flag]=new(segtree))->modify(last->son[flag],place,key);
	}
	inline int query(int place){
		if(Start==End&&Start==place) return val;
		int flag=(Start+End)<(2*place);
		return son[flag]->query(place);
	}
}*root[MAXN];
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read();m=read();
	for(int i=1;i<=n;++i){
		arr[i]=read();
	}
	(root[0]=new(segtree))->build(1,n);
	while(m--){
		v=read();opt=read();p=read();
		if(opt==1){
			k=read();
			(root[++edtion]=new(segtree))->modify(root[v],p,k);
		}
		else{
			root[++edtion]=root[v];
			printf("%d\n",root[v]->query(p));
		}
	}
	return 0;
}
