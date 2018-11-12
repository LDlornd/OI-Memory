#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=1e4+5;
int dp[MAXN][MAXN];
int main(){
	int n;
	scanf("%d",&n);
	dp[0][0]=1;
	for(int i=1;i<=n;++i)
		for(int j=0;j<=n;++j)
			if(j==0) dp[i][j]=dp[i-1][j+1];
			else dp[i][j]=dp[i-1][j-1]+dp[i-1][j+1];
	for(int i=0;i<=n;++i){
		for(int j=0;j<=n;++j)
			printf("%3d",dp[i][j]);
		printf("\n");
	}
	return 0;
}
