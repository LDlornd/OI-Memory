#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
typedef long long int ll;
const int MAXN=5e4+5;
int T,n,p,l,r;
ll k,arr[MAXN];
struct segtree{
	int Start,End;
	ll val;
	segtree *son[2];
	segtree() {Start=End=val=0;son[0]=son[1]=NULL;}
	void update(){
		val=son[0]->val+son[1]->val;
	}
	void build(int nstart,int nend){
		Start=nstart;End=nend;
		if(Start==End) {val=arr[Start];return;}
		int mid=(Start+End)>>1;
		(son[0]=new(segtree))->build(Start,mid);
		(son[1]=new(segtree))->build(mid+1,End);
		update();
	}
	void modify(int place,ll key){
		if(Start==place&&End==place) {val+=key;return;}
		int mid=(Start+End)>>1;
		if(place<=mid) son[0]->modify(place,key);
		else son[1]->modify(place,key);
		update();
	}
	ll query(int nstart,int nend){
		if(Start==nstart&&End==nend) return val;
		int mid=(Start+End)>>1;
		if(nend<=mid) return son[0]->query(nstart,nend);
		else if(nstart>mid) return son[1]->query(nstart,nend);
		else return son[0]->query(nstart,mid)+son[1]->query(mid+1,nend);
	}
}*root;
template<typename T>
T read(){
	T x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
char get_opt(){
	char c=getchar();
	while(c<'A'||c>'Z') c=getchar();
	return c;
}
int main(){
	T=read<int>();
	for(int casenum=1;casenum<=T;++casenum){
		printf("Case %d:\n",casenum);
		n=read<int>();
		for(int i=1;i<=n;++i) arr[i]=read<ll>();
		(root=new(segtree))->build(1,n);
		while(true){
			char c=get_opt();
			if(c=='E') break;
			if(c=='Q'){
				l=read<int>();r=read<int>();
				printf("%lld\n",root->query(l,r));
				continue;
			}
			p=read<int>();k=read<ll>();
			if(c=='A') root->modify(p,k);
			if(c=='S') root->modify(p,-k);
		}
	}
	return 0;
}
