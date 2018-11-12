#include<cstdio>
#include<iostream>
using namespace std;
typedef long long int ll;
const int MAXN=4e6+5;
int n,ans=0;
ll arr[MAXN];
int dp[2][MAXN];
template<typename T>
T read(){
	T x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read<int>();
	for(int i=1;i<=n;++i) arr[i]=read<ll>();
	for(int i=1;i<=n;++i){
		dp[0][i]=1;
		for(int j=i-1;j>=1;j-=dp[0][j])
			if(arr[j]%arr[i]==0) dp[0][i]+=dp[0][j];
			else break;
	}
	for(int i=n;i>=1;--i){
		dp[1][i]=1;
		for(int j=i+1;j<=n;j+=dp[1][j])
			if(arr[j]%arr[i]==0) dp[1][i]+=dp[1][j];
			else break;
	}
	for(int i=1;i<=n;++i)
		ans=max(ans,dp[0][i]+dp[1][i]-1);
	printf("%d",ans);
	return 0;
}
