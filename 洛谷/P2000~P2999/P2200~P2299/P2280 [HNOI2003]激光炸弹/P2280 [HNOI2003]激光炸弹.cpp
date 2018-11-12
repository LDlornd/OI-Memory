#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=5001;
int n,R,x,y,w;
int maxx=0,maxy=0,ans=0;
int dp[MAXN][MAXN];
inline int getsum(int zsx,int zsy,int yxx,int yxy){
	if(zsx==0&&zsy==0) return dp[yxx][yxy];
	if(zsx==0&&zsy!=0) return dp[yxx][yxy]-dp[yxx][zsy-1];
	if(zsx!=0&&zsy==0) return dp[yxx][yxy]-dp[zsx-1][yxy];
	return dp[yxx][yxy]-dp[yxx][zsy-1]-dp[zsx-1][yxy]+dp[zsx-1][zsy-1];
}
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';
	return x*f;
}
int main(){
	n=read();R=read();
	while(n--){
		x=read();y=read();w=read();
		dp[x][y]=w;
		maxx=max(maxx,x);
		maxy=max(maxy,y);
	}
	for(int i=1;i<=maxx;++i) dp[i][0]+=dp[i-1][0];
	for(int i=1;i<=maxy;++i) dp[0][i]+=dp[0][i-1];
	for(int i=1;i<=maxx;++i)
		for(int j=1;j<=maxy;++j)
			dp[i][j]+=(dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]);
	for(int i=0;i<=maxx;++i)
		for(int j=0;j<=maxy;++j)
			ans=max(ans,getsum(max(0,i-R+1),max(0,j-R+1),i,j));
	printf("%d",ans);
	return 0;
}
