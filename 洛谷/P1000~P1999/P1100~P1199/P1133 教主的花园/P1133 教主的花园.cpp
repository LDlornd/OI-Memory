#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=100005;
int n,ans=0,arr[3];
int dp[3][MAXN][3],pre[3][MAXN][3];
bool judge(int a,int b,int c){
	if(b>a&&b>c) return true;
	if(b<a&&b<c) return true;
	return false;
}
int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read();
	dp[0][1][0]=read();dp[1][1][1]=read();dp[2][1][2]=read();
	for(int w=2;w<=n;++w){
		arr[0]=read();arr[1]=read();arr[2]=read();
		if(w==2){
			for(int i=0;i<3;++i)
				for(int j=0;j<3;++j){
					dp[i][2][j]=dp[i][1][i]+arr[j];
					pre[i][2][j]=i;
				}
		}
		if(w==n){
			for(int i=0;i<3;++i)
				for(int j=0;j<3;++j){
					for(int k=0;k<3;++k){
						if(judge(pre[i][n-1][j],j,k)&&judge(j,k,i)){
							dp[i][n][k]=dp[i][n-1][j]+arr[k];
								ans=max(ans,dp[i][n][k]);
							}
					}
				}
		}
		if(w>2&&w<n){
			for(int i=0;i<3;++i){
				for(int j=0;j<3;++j){
					for(int k=0;k<3;++k)
						if(judge(pre[i][w-1][j],j,k)&&dp[i][w-1][j]+arr[k]>dp[i][w][k]){
							dp[i][w][k]=dp[i][w-1][j]+arr[k];
							pre[i][w][k]=j;
						}
				}
			}
		}
	}
	printf("%d",ans);
	return 0;
}
