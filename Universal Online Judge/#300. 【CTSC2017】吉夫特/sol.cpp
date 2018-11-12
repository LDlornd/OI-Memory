#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=250000;
const int mod=1e9+7;
int n,ans=0;
int arr[MAXN],place[MAXN],dp[MAXN];
int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read();
	for(int i=1;i<=n;++i) place[arr[i]=read()]=i;
	for(int i=n;i>=1;--i){
		int now=arr[i];
		dp[now]=1;
		for(int j=(now-1)&arr[i];j>0;j=(j-1)&now)
			dp[now]=(dp[now]+dp[j])%mod;
		ans=(ans+dp[now]-1)%mod;
	}
	printf("%d",ans);
	return 0;
}
