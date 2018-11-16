#include<cstdio>
#include<iostream>
using namespace std;
typedef long long int ll;
ll b,p,k;
ll quick_mi(ll base,ll index,ll mod){
	ll temp=1;
	base%=mod;
	if(index==0) return temp*base%mod;
	while(index){
		if(index&1) temp=temp*base%mod;
		base=base*base%mod;
		index>>=1;
	}
	return temp;
}
int main(){
	scanf("%lld%lld%lld",&b,&p,&k);
	printf("%lld^%lld mod %lld=%lld",b,p,k,quick_mi(b,p,k));
	return 0;
}
