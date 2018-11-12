#include<cstdio>
#include<iostream>
using namespace std;
typedef long long int ll;
const int mod=666623333;
ll T,n,ans;
inline int quick_mi(ll base,ll index){
	base%=mod;
	ll temp=1; 
	while(index){
		if(index&1) temp=temp*base%mod;
		base=base*base%mod;
		index>>=1;
	}
	return temp%mod;
}
int main(){
	ios::sync_with_stdio(false);
	//freopen("RP10.in","r",stdin);
	//freopen("RP10.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		ans=(quick_mi(2,n+1)-(2*n+2)%mod+mod)%mod;
		cout<<ans<<endl;
	}
	return 0;
}
