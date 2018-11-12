#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1005;
const int mod=2015;
int n,k;
int dp[MAXN][MAXN];
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)
		for(int j=0;j<i;++j)
			if(j==0||j==i-1) dp[i][j]=1;
			else dp[i][j]=(dp[i-1][j-1]*(i-j)+dp[i-1][j]*(j+1))%mod;
	printf("%d",dp[n][k]);
}
