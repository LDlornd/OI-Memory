#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int MAXN=31;
int n,m;
int dp[MAXN][MAXN];
int main()
{
	memset(dp,0,sizeof(dp));
	scanf("%d%d",&n,&m);
	dp[0][1]=1;
	for(int i=1;i<=m;++i)
	{
		dp[i][n]+=(dp[i-1][n-1]+dp[i-1][1]);
		dp[i][1]+=(dp[i-1][n]+dp[i-1][2]);
		for(int j=2;j<n;++j)
			dp[i][j]+=(dp[i-1][j-1]+dp[i-1][j+1]);
	}
	printf("%d",dp[m][1]);
	return 0;
}
