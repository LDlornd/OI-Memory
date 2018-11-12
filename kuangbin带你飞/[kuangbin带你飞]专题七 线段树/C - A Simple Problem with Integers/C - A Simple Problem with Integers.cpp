#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
typedef long long int ll;
const int MAXN=1e5+5;
char opt;
int n,q,ql,qr,qk;
ll arr[MAXN];
struct segtree{
	int Start,End;
	ll val,lazy;
	segtree *son[2];
	segtree(){
		Start=End=val=lazy=0;
		son[0]=son[1]=NULL;
	}
	void update(){
		val=son[0]->val+son[1]->val;
	}
	void caculate(ll key){
		val+=key*(End-Start+1);
	}
	void push_down(){
		son[0]->caculate(lazy);son[0]->lazy+=lazy;
		son[1]->caculate(lazy);son[1]->lazy+=lazy;
		lazy=0;
	}
	void build(int nstart,int nend){
		Start=nstart;End=nend;
		if(Start==End) {val=arr[Start];return;}
		int mid=(Start+End)>>1;
		(son[0]=new(segtree))->build(nstart,mid);
		(son[1]=new(segtree))->build(mid+1,nend);
		update();
	}
	void modify(int nstart,int nend,ll key){
		if(Start==nstart&&End==nend){
			caculate(key);lazy+=key;
			return;
		}
		push_down();
		int mid=(Start+End)>>1;
		if(nend<=mid) son[0]->modify(nstart,nend,key);
		else if(nstart>mid) son[1]->modify(nstart,nend,key);
		else {son[0]->modify(nstart,mid,key);son[1]->modify(mid+1,nend,key);}
		update();
	}
	ll query(int nstart,int nend){
		if(Start==nstart&&End==nend) return val;
		push_down();
		int mid=(Start+End)>>1;
		if(nend<=mid) return son[0]->query(nstart,nend);
		else if(nstart>mid) return son[1]->query(nstart,nend);
		else return son[0]->query(nstart,mid)+son[1]->query(mid+1,nend);
	}
}*root;
char get_opt(){
	char c=getchar();
	while(c<'A'||c>'Z') c=getchar();
	return c;
}
template<typename T>
T read(){
	T x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read<int>();q=read<int>();
	for(int i=1;i<=n;++i) arr[i]=read<ll>();
	(root=new(segtree))->build(1,n);
	while(q--){
		opt=get_opt();ql=read<int>();qr=read<int>();
		if(opt=='C'){
			qk=read<ll>();
			root->modify(ql,qr,qk);
		}
		if(opt=='Q') printf("%lld\n",root->query(ql,qr));
	}
	return 0;
}
