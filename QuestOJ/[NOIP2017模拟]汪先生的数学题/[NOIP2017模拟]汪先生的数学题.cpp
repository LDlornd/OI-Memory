#include<cstdio>
#include<iostream>
using namespace std;
typedef long long int ll;
const int MOD=1e9+7;
ll a,b;
inline ll quick_mi(ll base,ll index,int mod){
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
	scanf("%lld%lld",&a,&b);
	printf("%lld",quick_mi(a,quick_mi(a,b-1,MOD-1),MOD));
	return 0;
}
