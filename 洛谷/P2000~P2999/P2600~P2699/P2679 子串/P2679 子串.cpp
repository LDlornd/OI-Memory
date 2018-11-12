#include<cstdio>
#include<iostream>
using namespace std;
const int mod=1e9+7;
int n,m,k,ans=0,now=1;
char A[1005],B[1005];
int dp[2][205][205][2];
int main(){
	scanf("%d%d%d%s%s",&n,&m,&k,A+1,B+1);
	dp[1][0][0][0]=dp[0][0][0][0]=1;
	for(int i=1;i<=n;++i,now^=1)
		for(int j=1;j<=m;++j)
			for(int p=1;p<=k;++p){
				if(A[i]==B[j]){
					dp[now][j][p][0]=(dp[now^1][j][p][0]+dp[now^1][j][p][1])%mod;
					dp[now][j][p][1]=((dp[now^1][j-1][p-1][0]+dp[now^1][j-1][p][1])%mod+dp[now^1][j-1][p-1][1])%mod;
				}
				else{
					dp[now][j][p][0]=(dp[now^1][j][p][0]+dp[now^1][j][p][1])%mod;
					dp[now][j][p][1]=0;
				}
			}
	printf("%d",(dp[n&1][m][k][0]+dp[n&1][m][k][1])%mod);
	return 0;
}
