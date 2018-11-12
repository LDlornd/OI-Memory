#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=2e5+5;
int n,q,ql,qr,qk;
int small[MAXN],arr[MAXN];
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
		if(Start==End) {val=last->val+1;return;}
		int mid=(Start+End)>>1,flag=(key>mid);
		son[flag^1]=last->son[flag^1];
		if(flag) (son[1]=new(segtree))->build(last->son[1],mid+1,End,key);
		else (son[0]=new(segtree))->build(last->son[0],Start,mid,key);
		update();
	}
	int query(segtree *last,int nstart,int nend,int key){
		if(nstart==nend) return nstart;
		int mid=(Start+End)>>1,temp=son[0]->val-last->son[0]->val;
		if(temp>=key) return son[0]->query(last->son[0],nstart,mid,key);
		else return son[1]->query(last->son[1],mid+1,nend,key-temp);
	}
	void dfs(){
		cout<<Start<<" "<<End<<" "<<val<<" ";
		if(son[0]!=NUL) son[0]->dfs();
		if(son[1]!=NUL) son[1]->dfs();
	}
}*root[MAXN];
int low_bound(int Start,int End,int key){
	int temp=0;
	while(Start<=End){
		int mid=(Start+End)>>1;
		if(small[mid]>=key) {temp=mid;End=mid-1;}
		else Start=mid+1;
	}
	return temp;
}
bool CMP(int a,int b){
	return a<b;
}
int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read();q=read();
	for(int i=1;i<=n;++i) arr[i]=small[i]=read();
	sort(small+1,small+n+1,CMP);
	NUL=new(segtree);NUL->son[0]=NUL->son[1]=NUL;
	root[0]=new(segtree);
	for(int i=1;i<=n;++i){
		arr[i]=low_bound(1,n,arr[i]);
		(root[i]=new(segtree))->build(root[i-1],1,n,arr[i]);
	}
	 for(int i=0;i<=n;++i){
	 	root[i]->dfs();
	 	cout<<endl;
	}
	while(q--){
		ql=read();qr=read();qk=read();
		printf("%d\n",small[root[qr]->query(root[ql],1,n,qk)]);
	}
	return 0;
}
