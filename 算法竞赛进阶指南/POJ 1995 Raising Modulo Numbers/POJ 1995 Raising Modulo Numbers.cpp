#include<cstdio>
#include<iostream>
using namespace std;
typedef long long int ll;
ll T,n,mod,A,B,ans;
inline ll read(){
	ll x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
inline ll quick_mi(ll base,ll index){
	ll temp=1;
	while(index){
		if(index&1) {
			(temp*=(base))%=mod;
		}
		(base*=base)%=mod;
		index>>=1;
	}
	//(temp*=base)%=mod;
	return temp;
}
int main(){
	T=read();
	while(T--){
		ans=0;
		mod=read();n=read();
		while(n--){
			A=read()%mod;B=read();
			cout<<quick_mi(A,B)<<endl;
			(ans+=quick_mi(A,B))%=mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
