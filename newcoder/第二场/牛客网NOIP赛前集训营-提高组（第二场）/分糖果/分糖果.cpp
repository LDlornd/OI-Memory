#include<cstdio>
#include<iostream>
using namespace std;
typedef long long int ll;
const int mod=1e9+7;
const int MAXN=1e6+1;
ll ans=0,sum[MAXN],dp[105][105];
int n;
int arr[MAXN];
bool flag=true;
ll quick_mi(ll base,ll index){
	ll temp=1;
	while(index){
		if(index&1) temp=temp*base%mod;
		base=base*base%mod;
		index>>=1;
	}
	return temp;
}
void get_10_pts(){
	for(int i=1;i<n;++i){
		if(i&1) ans=ans+(ll)n*quick_mi((ll)n-1,(ll)n-i);
		else ans=ans-(ll)n*quick_mi((ll)n-1,(ll)n-i);
		while(ans<0) ans+=mod;
		ans%=mod;
	}
}
void get_40_pts(){
	for(int i=1;i<=arr[1];++i) dp[1][i]=1;
	for(int i=2;i<=n;++i){
		for(int j=1;j<=arr[i];++j){
			for(int k=1;k<=arr[i-1];++k)
				if(j==k) continue;
				else dp[i][j]=(dp[i][j]+dp[i-1][k])%mod;
			sum[i]=(sum[i]+dp[i][j])%mod;
		}
	}
	for(int i=n;i>1;--i){
		if((n-i)&1) ans=ans-sum[i];
		else ans=ans+sum[i];
		while(ans<0) ans+=mod;
		ans%=mod;
	}
}
int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		arr[i]=read();
		flag=(flag&(arr[i]==arr[1]));
	}
	if(flag) get_10_pts();
	else get_40_pts();
	printf("%lld",ans);
	return 0;
}
