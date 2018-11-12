#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
typedef long long int ll;
const int MAXN=100005;
int n;
ll ans=0;
ll val[MAXN][4],dp[MAXN][4][2];
void get_dp(){
	for(int i=2;i<=n;++i){
		dp[i][1][0]=max(dp[i-1][2][1],dp[i-1][3][1])+val[i][1];
		dp[i][3][1]=max(dp[i-1][2][0],dp[i-1][1][0])+val[i][3];
		dp[i][2][0]=dp[i-1][3][1]+val[i][2];
		dp[i][2][1]=dp[i-1][1][0]+val[i][2];
	}
}
template<typename T>
T read(){
	T x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read<int>();
	for(int i=1;i<=n;++i){
		val[i][1]=read<ll>();val[i][2]=read<ll>();val[i][3]=read<ll>();
	}
	memset(dp,0,sizeof(dp));
	dp[1][1][0]=dp[1][1][1]=val[1][1];
	get_dp();
	ans=max(ans,max(dp[n][2][1],dp[n][3][1]));
	memset(dp,0,sizeof(dp));
	dp[1][2][0]=dp[1][2][1]=val[1][2];
	get_dp();
	ans=max(ans,max(dp[n][1][0],dp[n][3][1]));
	memset(dp,0,sizeof(dp));
	dp[1][3][0]=dp[1][3][1]=val[1][3];
	get_dp();
	ans=max(ans,max(dp[n][1][0],dp[n][2][0]));
	printf("%lld",ans);
	return 0;
	
}
