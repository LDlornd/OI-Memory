#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int D,n,now=10,ans=10;
int dp[105][3005];
struct node{
	int T,life,height;
	node() {T=life=height=0;}
}arr[105];
bool CMP(const node &a,const node &b){
	return a.T<b.T;
}
int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	memset(dp,-1,sizeof(dp));
	dp[0][10]=0;
	D=read();n=read();
	for(int i=1;i<=n;++i) {arr[i].T=read();arr[i].life=read();arr[i].height=read();}
	sort(arr+1,arr+n+1,CMP);
	for(int i=1;i<=n;++i){
		for(int j=3000;j>=0;--j){
			if(dp[i-1][j]!=-1){
				int nlife=j-arr[i].T+arr[i-1].T;
				if(nlife<0) break;
				dp[i][nlife]=max(dp[i][nlife],dp[i-1][j]+arr[i].height);
				dp[i][nlife+arr[i].life]=max(dp[i][nlife+arr[i].life],dp[i-1][j]);
				if(dp[i][nlife]>=D) {printf("%d",arr[i].T);return 0;}
			}
		}
	}
	for(int i=1;i<=n;++i){
		if(now<arr[i].T-arr[i-1].T) break;
		now=now-arr[i].T+arr[i-1].T+arr[i].life;
		ans+=arr[i].life;
	}
	printf("%d",ans);
	return 0;
}
/*
20 4
5 4 9
9 3 2
12 6 10
14 1 1
*/
