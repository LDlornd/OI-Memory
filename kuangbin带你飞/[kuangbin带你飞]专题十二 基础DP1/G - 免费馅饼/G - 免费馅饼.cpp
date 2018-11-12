#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN=1e5+1; 
int n,T,place,maxtime,ans;
int arr[MAXN][11];
int dp[MAXN][11];
bool vis[MAXN][11];
void getready(){
	T=0;ans=0;
	memset(arr,0,sizeof(arr));
	memset(dp,0,sizeof(dp));
	memset(vis,0,sizeof(vis));
	memset(vis,0,sizeof(vis));
}
int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	while(true){
		n=read();
		if(n==0) break;
		getready();
		while(n--){
			place=read();T=read();
			maxtime=max(maxtime,T);
			++arr[T][place];
		}
		vis[0][5]=true;
		for(int i=0;i<maxtime;++i){
			for(int j=0;j<11;++j){
				if(vis[i][j]){
					if(j!=0) {
						dp[i+1][j-1]=max(dp[i+1][j-1],dp[i][j]+arr[i+1][j-1]);
						vis[i+1][j-1]=true;
					}
					if(j!=10){
						dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+arr[i+1][j+1]);
						vis[i+1][j+1]=true;
					}
					dp[i+1][j]=max(dp[i+1][j],dp[i][j]+arr[i+1][j]);
					vis[i+1][j]=true;
				}
			}
		}
		for(int i=0;i<11;++i)
			ans=max(ans,dp[maxtime][i]);
		printf("%d\n",ans);
	}
	return 0;
}
