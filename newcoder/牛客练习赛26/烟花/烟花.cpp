#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=1e5+5;
int n,k;
double p[MAXN],E[MAXN],dp[MAXN][205];
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i){
		scanf("%lf",&p[i]);
		E[i]=E[i-1]*(1-p[i])+(E[i-1]+1)*p[i];
	}
	dp[0][0]=1;
	for(int i=1;i<=n;++i) dp[i][0]=dp[i-1][0]*(1-p[i]);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=k;++j)
			dp[i][j]=dp[i-1][j]*(1-p[i])+dp[i-1][j-1]*p[i];
	printf("%.4lf\n%.4lf",E[n],dp[n][k]);
	return 0;
}
