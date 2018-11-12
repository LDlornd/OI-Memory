#include<cstdio>
#include<iostream>
using namespace std;
typedef long long int ll;
const int MAXN=205;
int n,k;
ll dp[MAXN][MAXN];
int main(){
	freopen("testdata.in","r",stdin);
	scanf("%d%d",&n,&k);
	for(int i=0;i<=n;++i) dp[i][1]=dp[i][i]=1;
	for(int i=1;i<=n;++i)
		for(int j=2;j<i;++j)
			dp[i][j]=dp[i-1][j-1]+dp[i-j][j];
	printf("%lld",dp[n][k]);
	return 0;
}
