#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
typedef long long int ll;
const int MAXN=100005;
const int mod=1e9+7;
int n,m,opt,x,y;
ll arr[MAXN];
struct segtree{
	int Start,End;
	ll val;
	segtree *son[2];
	segtree() {Start=End=val=0;son[0]=son[1]=NULL;}
	void update(){
		val=(son[0]->val+son[1]->val)%mod;
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
		if(Start==place&&End==place) {val=key;return;}
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
		else return (son[0]->query(nstart,mid)+son[1]->query(mid+1,nend))%mod;
	}
}*add,*square;
ll get_inv(ll key){
	ll base=key,index=mod-2,temp=1;
	while(index){
		if(index&1) temp=temp*base%mod;
		base=base*base%mod;
		index>>=1;
	}
	return temp;
}
template<typename T>
T read(){
	T x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read<int>();m=read<int>();
	for(int i=1;i<=n;++i) arr[i]=read<ll>();
	(add=new(segtree))->build(1,n);
	for(int i=1;i<=n;++i) arr[i]=arr[i]*arr[i]%mod;
	(square=new(segtree))->build(1,n);
	while(m--){
		opt=read<int>();x=read<int>();y=read<int>();
		if(opt==1){
			add->modify(x,y);
			square->modify(x,1ll*y*y);
		}
		else{
			ll tmp=add->query(x,y);
			ll temp=((y-x+1)*square->query(x,y)%mod-tmp*tmp%mod+mod)%mod;
			ll inv=get_inv(y-x+1);
			printf("%lld\n",temp*inv%mod*inv%mod);
		}
	}
	return 0;
}
