#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=1005;
int n,mod,ans;
int num[MAXN][MAXN],dp[MAXN][MAXN];
int main(){
	scanf("%d%d",&n,&mod);
	num[0][0]=1;dp[0][0]=1;
	for(int i=1;i<=n;++i)
		for(int j=0;j<=n;++j)
			if(j==0) num[i][j]=(num[i][j]+num[i-1][j+1])%mod;
			else num[i][j]=(num[i][j]+num[i-1][j-1]+num[i-1][j+1])%mod;
	for(int i=1;i<=n;++i)
		for(int j=0;j<=n;++j)
			dp[i][j]=(dp[i-1][max(j-1,0)]+(dp[i-1][j+1]<<1))%mod;
	for(int i=0;i<=n;i+=2)
		ans=(ans+num[i][0]*dp[n][i])%mod;
	printf("%d",ans);
	return 0;
}
