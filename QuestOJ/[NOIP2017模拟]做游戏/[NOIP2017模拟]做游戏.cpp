#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int MAXN1=151;
const int MAXN2=21;
const int mod=12345678;
int m,n,k,ans=0;
int dp[MAXN1][MAXN1][MAXN2][MAXN2];
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	dp[0][0][0][0]=1;
	for(int i=0;i<=n;++i){
		for(int j=0;j<=m;++j){
			for(int x=0;x<=k;++x){
				for(int y=0;y<=k;++y){
					if(dp[i][j][x][y]){
						if(i+1<=n&&x+1<=k) (dp[i+1][j][x+1][max(y-1,0)]+=dp[i][j][x][y])%=mod;
						if(j+1<=m&&y+1<=k) (dp[i][j+1][max(x-1,0)][y+1]+=dp[i][j][x][y])%=mod;
					}
				}
			}
		}
	}
	for(int i=0;i<=k;++i)
		for(int j=0;j<=k;++j)
			(ans+=dp[n][m][i][j])%=mod;
	cout<<ans;
	return 0;
}
