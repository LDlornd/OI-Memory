#include<cstdio>
#include<iostream>
using namespace std;
typedef long long int ll;
const int mod=1e5+3;
ll n,m;
ll quick_mi(ll base,ll index){
	base%=mod;
	ll temp=1;
	while(index){
		if(index&1) temp=temp*base%mod;
		base=base*base%mod;
		index>>=1;
	}
	return temp;
}
int main(){
	scanf("%lld%lld",&m,&n);
	printf("%lld",(quick_mi(m,n)-quick_mi(m-1,n-1)*m%mod+mod)%mod);
	return 0;
}
