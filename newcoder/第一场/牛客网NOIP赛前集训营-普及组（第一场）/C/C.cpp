#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int mod=1e9+7;
const int MAXN=1e4+5;
char s[MAXN];
int n,now=1;
int dp[2][MAXN];
int main(){
	scanf("%d%s",&n,s+1);
	dp[0][0]=1;
	for(int i=1;i<=n;++i,now^=1){
		memset(dp[now],0,sizeof(dp[now]));
		for(int j=0;j<=i;++j){
			dp[now][j]=(dp[now][j]+dp[now^1][j])%mod;
			if(s[i]=='('&&j) dp[now][j]=(dp[now][j]+dp[now^1][j-1])%mod;
			if(s[i]==')') dp[now][j]=(dp[now][j]+dp[now^1][j+1])%mod;
		}
	}
	printf("%d",(dp[now^1][0]-1)%mod);
	return 0;
}
