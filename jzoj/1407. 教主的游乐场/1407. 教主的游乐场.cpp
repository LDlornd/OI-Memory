#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int MAXN=100005;
int n,m,k,mindp;
int jump[MAXN],dp[MAXN];
struct segtree{
	int Start,End,val;
	segtree *son[2];
	segtree() {Start=End=val=0;son[0]=son[1]=NULL;}
	void update(){
		val=min(son[0]->val,son[1]->val);
	}
	void build(int nstart,int nend){
		Start=nstart;End=nend;
		if(Start==End) {val=0;return;}
		int mid=(Start+End)>>1;
		(son[0]=new(segtree))->build(Start,mid);
		(son[1]=new(segtree))->build(mid+1,End);
		update();
	}
	void modify(int place,int key){
		if(Start==place&&End==place) {val=key;return;}
		int mid=(Start+End)>>1;
		if(place<=mid) son[0]->modify(place,key);
		else son[1]->modify(place,key);
		update();
	}
	int query(int nstart,int nend){
		if(Start==nstart&&End==nend) return val;
		int mid=(Start+End)>>1;
		if(nend<=mid) return son[0]->query(nstart,nend);
		else if(nstart>mid) return son[1]->query(nstart,nend);
		else return min(son[0]->query(nstart,mid),son[1]->query(mid+1,nend));
	}
}*root;
int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read();m=read();
	for(int i=1;i<=n;++i) jump[i]=read();
	(root=new(segtree))->build(1,n);
	for(int i=n;i>=1;--i){
		if(i+jump[i]>n) dp[i]=1;
		else dp[i]=root->query(i+1,i+jump[i])+1;
		root->modify(i,dp[i]);
	}
	mindp=n;
	for(int i=1;i<=n;++i){
		dp[i]=min(dp[i],mindp+1);
		mindp=min(mindp,dp[i]);
	}
	while(m--){
		k=read();
		printf("%d ",dp[k]);
	}
	return 0;
}
