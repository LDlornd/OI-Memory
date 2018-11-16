#include<cstdio>
#include<iostream>
using namespace std;
typedef long long int ll;
const int MAXN=3e6+5;
int n,p;
ll fac[MAXN],inv[MAXN];
ll quick_mi(ll base,ll index,ll mod){
	if(index==0) return base%mod;
	ll temp=1;
	base%=mod;
	while(index){
		if(index&1) temp=temp*base%mod;
		base=base*base%mod;
		index>>=1;
	}
	return temp;
}
int main(){
	scanf("%d%d",&n,&p);
	fac[1]=inv[1]=1;
	for(int i=2;i<=n;++i) fac[i]=fac[i-1]*i%p;
	inv[n]=quick_mi(fac[n],p-2,p);
	for(int i=n-1;i>=1;--i) inv[i]=inv[i+1]*(i+1)%p;
	for(int i=2;i<=n;++i) inv[i]=inv[i]*fac[i-1]%p;
	for(int i=1;i<=n;++i) printf("%lld\n",inv[i]);
	return 0;
}
