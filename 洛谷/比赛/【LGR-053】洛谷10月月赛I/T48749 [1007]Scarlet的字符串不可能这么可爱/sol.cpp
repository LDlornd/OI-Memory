#include<cstdio>
#include<iostream>
using namespace std;
typedef long long int ll;
ll k,l,p,s,w;
ll quick_mi(ll base,ll index,ll mod){
	ll temp=1;
	while(index>0){
		if(index&1) temp=temp*base%mod;
		base=base*base%mod;
		index>>=1;
	}
	return temp;
}
int main(){
	freopen("testdata.in","r",stdin);
	freopen("wa.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&k,&l,&p,&s,&w);
	if(l==1){
		if(s==0) printf("%lld",k);
		else printf("1");
	}
	else printf("%lld",k%p*(k-1)%p*quick_mi(k-2,l-2,p)%p/(s==0?1:k));
	return 0;
}
