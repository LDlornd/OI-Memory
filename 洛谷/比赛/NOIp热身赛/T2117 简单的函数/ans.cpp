#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
typedef long long int ll;
const int mod=1e9+7;
const ll val=6*6*6*6*6*8;
ll ans=1;
ll n;
ll quick_mi(ll base,ll index){
	ll temp=1;
	while(index){
		if(index&1) temp=temp*base%mod;
		base=base*base%mod;
		index>>=1;
	}
	return temp;
}
ll get_inv(ll key){
	return quick_mi(key,mod-2);
}
int main(){
	freopen("test.in","r",stdin);
	//freopen("ans.out","w",stdout);
	scanf("%lld",&n);
	if(n==2) ans=1;
	else if(n==3) ans=2;
	else if(n==4) ans=6;
	else if(n==5) ans=12;
	else if(n==6) ans=48;
	else{
		ans=48;
//		ll temp=n-6;
//		while(temp>0) {
//			cout<<ans<<" "<<temp<<endl;
//			ans=ans*val%mod;
//			temp-=12;
//		}
		ll temp=n-6;
		ans=ans*quick_mi(val,temp/12);
		ans=ans*get_inv(quick_mi(3,n/840))%mod*quick_mi(4,n/840)%mod;
		if(n%840>=420) ans=ans*get_inv(3)%mod*4%mod;
		temp%=12;
		if(temp==1) ans=ans*2%mod;
		if(temp==2) ans=ans*6%mod;
		if(temp==3) ans=ans*6*2%mod;
		if(temp==4) ans=ans*6*6%mod;
		if(temp==5) ans=ans*6*6*2%mod;
		if(temp==6) ans=ans*6*6*6%mod;
		if(temp==7) ans=ans*6*6*6*2%mod;
		if(temp==8) ans=ans*6*6*6*6%mod;
		if(temp==9) ans=ans*6*6*6*6*2%mod;
		if(temp==10) ans=ans*6*6*6*6*6%mod;
		if(temp==11) ans=ans*6*6*6*6*6*2%mod;
	}
	printf("%lld",ans);
	return 0;
}
