#include<cstdio>
#include<iostream>
using namespace std;
typedef long long int ll;
const int mod=1e9+7;
ll a,b;
ll quick_mi(ll base,ll index){
	ll temp=1;
	while(index){
		if(index&1) temp=temp*base%mod;
		base=base*base%mod;
		index>>=1;
	}
	return  temp;
}
int main(){
	while(scanf("%lld%lld",&a,&b)!=EOF){
		printf("%lld\n",a*quick_mi(b,mod-2)%mod);
	}
	return 0;
}
