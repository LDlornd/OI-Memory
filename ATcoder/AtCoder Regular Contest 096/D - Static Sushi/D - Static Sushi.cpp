#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long int ll;
const int MAXN=100005;
ll n,C,ans=0;
ll dist[MAXN],val[MAXN];
ll l[MAXN],r[MAXN];
ll lmax[MAXN],rmax[MAXN],lb[MAXN],rb[MAXN];
ll rplace,lplace;
inline ll read(){
	ll x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read();C=read();
	for(ll i=1;i<=n;++i) {dist[i]=read();val[i]=read();}
	dist[n+1]=C;
	for(int i=1;i<=n;++i){
		r[i]=r[i-1]+val[i]-(dist[i]-dist[i-1]);
		rb[i]=r[i]-dist[i];
	}
	for(int i=n;i>=1;--i) {
		l[i]=l[i+1]+val[i]-(dist[i+1]-dist[i]);
		lb[i]=l[i]-(C-dist[i]);
	}
	rplace=0;lplace=n+1;
	for(int i=1;i<=n;++i)
		if(r[i]>r[rplace]) rmax[i]=r[rplace=i];
		else rmax[i]=r[rplace];
	for(int i=n;i>=1;--i)
		if(l[i]>l[lplace]) lmax[i]=l[lplace=i];
		else lmax[i]=l[lplace];
	for(int i=1;i<=n;++i) ans=max(ans,rb[i]+lmax[i+1]);
	for(int i=n;i>=1;--i) ans=max(ans,lb[i]+rmax[i-1]);
	for(int i=1;i<=n;++i) ans=max(ans,max(l[i],r[i]));
	printf("%lld",ans);
	return 0;
}
