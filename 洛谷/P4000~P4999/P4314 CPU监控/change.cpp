#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN=100001;
const int INF=0x3f3f3f3f;
char opt;
int T,E,x,y,z;
int arr[MAXN];
struct data{
	int add,change;
	data(int aa=0,int cc=-INF) {add=aa;change=cc;}
	data operator +(const data &a) const{return data(max(-INF,add+a.add),max(a.change,change+a.add));}
	data operator *(const data &a) const{return data(max(add,a.add),max(change,a.change));}
};
struct segtree{
	int Start,End;
	int nmax,hmax;
	data nlazy,hlazy;
	segtree *son[2];
	segtree(){
		Start=End=nmax=hmax=0;
		nlazy=hlazy=data();
		son[0]=son[1]=NULL;
	}
	inline void update(){
		nmax=max(son[0]->nmax,son[1]->nmax);
		hmax=max(son[0]->hmax,son[1]->hmax);
	}
	inline void caculate(data now,data history){
		hlazy=hlazy*(nlazy+history);
		nlazy=nlazy+now;
		hmax=max(hmax,max(nmax+history.add,history.change));
		nmax=max(nmax+now.add,now.change);
	}
	inline void pushdown(){
		son[0]->caculate(nlazy,hlazy);
		son[1]->caculate(nlazy,hlazy);
		nlazy=hlazy=data();
	}
	inline void build(int nstart,int nend){
		Start=nstart;End=nend;
		if(Start==End){nmax=hmax=arr[Start];return;}
		int mid=(Start+End)>>1;
		(son[0]=new(segtree))->build(Start,mid);
		(son[1]=new(segtree))->build(mid+1,End);
		update();
	}
	inline void modify(int nstart,int nend,data key){
		if(nstart==Start&&nend==End) {caculate(key,key);return;}
		pushdown();
		int mid=(Start+End)>>1;
		if(nstart>mid) son[1]->modify(nstart,nend,key);
		else if(nend<=mid) son[0]->modify(nstart,nend,key);
		else {son[0]->modify(nstart,mid,key);son[1]->modify(mid+1,nend,key);}
		update();
	}
	inline int query(int nstart,int nend,bool flag){
		if(nstart==Start&&nend==End) return flag?hmax:nmax;
		pushdown();
		int mid=(Start+End)>>1;
		if(nstart>mid) return son[1]->query(nstart,nend,flag);
		if(nend<=mid) return son[0]->query(nstart,nend,flag);
		else return max(son[0]->query(nstart,mid,flag),son[1]->query(mid+1,nend,flag));
	}
}*root;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	T=read();
	for(int i=1;i<=T;++i) arr[i]=read();
	(root=new(segtree))->build(1,T);
	E=read();
	while(E--){
		opt=getchar();
		while(opt<'A'||opt>'Z') opt=getchar();
		x=read();y=read();
		if(opt=='Q') printf("%d\n",root->query(x,y,false));
		if(opt=='A') printf("%d\n",root->query(x,y,true));
		if(opt=='P') {z=read();root->modify(x,y,data(z,-INF));}
		if(opt=='C') {z=read();root->modify(x,y,data(-INF,z));}
	}
	return 0;
}
