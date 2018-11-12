#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=10005;
int n,m;
int dist[MAXN],dp[MAXN][MAXN];
int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read();m=read();
	for(int i=1;i<=n;++i) dist[i]=read();
	for(int i=1;i<=n;++i){
		for(int j=0;j<=m;++j){
			if(i+j<=n) dp[i+j][0]=max(dp[i+j][0],dp[i-1][j+1]);
			if(j==0) dp[i][j]=max(dp[i][j],max(dp[i-1][j],dp[i-1][j+1]));
			else dp[i][j]=max(dp[i][j],dp[i-1][j-1]+dist[i]);
		}
	}
	printf("%d",dp[n][0]);
	return 0;
}
