#include<cstdio>
#include<iostream>
using namespace std;
typedef long long int ll;
const int mod=998244353;
ll l1,r1,l2,r2,m,ans;
ll caculate(ll kl,ll kr){
	if(kl==0) return (kr/m+1)%mod;
	else return (kr/m-(kl-1)/m)%mod;
}
ll solve(ll k1,ll k2){
	ll temp=0;
	for(ll i=0,x=k1;x;x>>=1,++i){
		if((x&1)==0) continue;
		for(ll j=0,y=k2;y;y>>=1,++j){
			if((y&1)==0) continue;
			if(i>j){
				ll nl=((((x^1)<<i)^((y^1)<<j))>>i)<<i,nr=nl+(1ll<<i)-1;
				temp=(temp+((1ll<<j)%mod*caculate(nl,nr)%mod))%mod;
			}
			else{
				ll nl=((((x^1)<<i)^((y^1)<<j))>>j)<<j,nr=nl+(1ll<<j)-1;
				temp=(temp+((1ll<<i)%mod*caculate(nl,nr)%mod))%mod;
			}
		}
	}
	return temp;
}
int main(){
	scanf("%lld%lld%lld%lld%lld",&l1,&r1,&l2,&r2,&m);
	ans=(solve(r1+1,r2+1)+solve(l1,l2)-solve(l1,r2+1)+mod-solve(l2,r1+1)+mod)%mod;
	printf("%lld",ans);
	return 0;
}
