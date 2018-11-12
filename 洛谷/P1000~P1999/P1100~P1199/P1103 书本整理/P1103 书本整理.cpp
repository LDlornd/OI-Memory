#include<cmath>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int INF=2147483647;
const int MAXN=105;
int n,k,ans=INF;
int dp[MAXN][MAXN];
struct node{
	int high,wide;
	node() {high=wide=0;}
}arr[MAXN];
bool CMP(const node &a,const node &b){
	return a.high<b.high;
}
int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read();k=read();
	for(int i=1;i<=n;++i)
		{arr[i].high=read();arr[i].wide=read();}
	sort(arr+1,arr+n+1,CMP);
	for(int i=0;i<=n-k;++i)
		for(int j=1;j<=n;++j)
			dp[i][j]=INF;
	for(int j=1;j<=n;++j) dp[1][j]=0;
	for(int i=2;i<=n-k;++i)
		for(int j=i;j<=n;++j)
			for(int k=1;k<j;++k)
				if(dp[i-1][k]==INF) continue;
				else dp[i][j]=min(dp[i][j],dp[i-1][k]+abs(arr[k].wide-arr[j].wide));
	for(int i=1;i<=n;++i) ans=min(ans,dp[n-k][i]);
	printf("%d",ans);
	return 0;
}
