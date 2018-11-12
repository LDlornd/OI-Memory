#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int MAXN=1005;
int n,m;
int arr[MAXN],sum[MAXN];
int dp[MAXN][MAXN];
template<typename T>
T read(){
	T x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	memset(dp,-1,sizeof(dp));
	n=read<int>();m=read<int>();
	for(int i=1;i<=n;++i){
		arr[i]=read<int>();
		sum[i]=sum[i-1]^arr[i];
	}
	dp[0][0]=0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=min(i,m);++j)
			for(int k=0;k<i;++k)
				if(dp[k][j-1]!=-1) dp[i][j]=max(dp[i][j],dp[k][j-1]+(sum[i]^sum[k]));
	printf("%d",dp[n][m]);
	return 0;
}
