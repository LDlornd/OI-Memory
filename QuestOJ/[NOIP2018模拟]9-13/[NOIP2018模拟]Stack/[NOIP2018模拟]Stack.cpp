#include<cstdio>
#include<iostream>
using namespace std;
const int mod=7;
const int MAXN=2005;
int n,now;
int dp[2][MAXN];
int main(){
	scanf("%d",&n);n<<=1;
	dp[0][0]=1;now=1;
	for(int i=1;i<=n;++i,now^=1){
		dp[now][0]=dp[now^1][1];
		dp[now][n]=dp[now^1][n-1];
		for(int j=1;j<n;++j)
			dp[now][j]=(dp[now^1][j-1]+dp[now^1][j+1])%mod;
	}
	printf("%d",dp[now^1][0]);
	return 0;
}
