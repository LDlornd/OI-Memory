#include<cstdio>
#include<iostream>
using namespace std;
typedef long long int ll;
const int MAXN=500005;
const int mod=1e9+7;
int n,m,k,q;
ll ans=0;
ll arr[MAXN];
ll fac[MAXN],inv[MAXN];
ll quick_mi(ll base,ll index){
	ll temp=1;
	while(index){
		if(index&1) temp=temp*base%mod;
		base=base*base%mod;
		index>>=1;
	}
	return temp;
}
void init(){
	fac[0]=inv[0]=1;
	for(int i=1;i<=n;++i) fac[i]=fac[i-1]*i%mod;
	inv[n]=quick_mi(fac[n],mod-2);
	for(int i=n-1;i>=1;--i) inv[i]=inv[i+1]*(i+1)%mod;
}
template<typename T>
T read(){
	T x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read<int>();m=read<int>();k=read<int>();q=read<ll>()%mod;
	init();
	for(int i=0;i<=m;++i){
		arr[i]=read<ll>();
		ans=(ans+arr[i]*quick_mi(q,i)%mod)%mod;
	}
	ans=ans*fac[n]%mod*inv[k]%mod*inv[n-k]%mod;
	printf("%lld",ans);
	return 0;
}
