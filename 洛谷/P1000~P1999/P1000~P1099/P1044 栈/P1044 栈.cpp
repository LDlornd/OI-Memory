#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=50;
long long int dp[MAXN][MAXN];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<=n;++i)
		{dp[i][0]=1;dp[0][i]=0;}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=i;++j)
			dp[i][j]=dp[i][j-1]+dp[i-1][j];
	printf("%lld",dp[n][n]);
	return 0;
}
