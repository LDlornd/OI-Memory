#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
const int INF=2147483647;
const int MAXN=200005;
int n,l,r,ans=-INF;
int arr[MAXN],dp[MAXN];
struct segtree{
	int Left,Right,val;
	segtree *son[2];
	segtree(){
		Left=Right=val=0;
		son[0]=son[1]=NULL;
	}
	void update(){
		val=max(son[0]->val,son[1]->val);
	}
	void build(int Start,int End){
		Left=Start;Right=End;
		if(Start==End) {val=-INF;return;}
		int mid=(Start+End)>>1;
		(son[0]=new(segtree))->build(Start,mid);
		(son[1]=new(segtree))->build(mid+1,End);
	}
	void modify(int place,int key){
		if(Left==Right&&Left==place) {val=key;return;}
		int mid=(Left+Right)>>1;
		if(place<=mid) son[0]->modify(place,key);
		else son[1]->modify(place,key);
		update();
	}
	int query(int Start,int End){
		if(Left==Start&&Right==End) return val;
		int mid=(Left+Right)>>1;
		if(End<=mid) return son[0]->query(Start,End);
		else if(Start>mid) return son[1]->query(Start,End);
		else return max(son[0]->query(Start,mid),son[1]->query(mid+1,End));
	}
}*root;
int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read();l=read();r=read();
	for(int i=0;i<=n;++i) arr[i]=read();
	(root=new(segtree))->build(0,n);
	root->modify(0,0);
	for(int i=l;i<=n;++i){
		dp[i]=root->query(max(0,i-r),i-l)+arr[i];
		root->modify(i,dp[i]);
	}
	for(int i=n;i+r>n;--i) ans=max(ans,dp[i]);
	printf("%d",ans);
	return 0;
}
