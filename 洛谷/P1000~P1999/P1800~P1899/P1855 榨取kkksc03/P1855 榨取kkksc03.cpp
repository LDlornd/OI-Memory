#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=105;
int n,M,T,now=1;
int dp[2][205][205];
struct node{
	int money,Time;
	node() {money=Time=0;}
}arr[MAXN];
int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read();M=read();T=read();
	for(int i=1;i<=n;++i) {arr[i].money=read();arr[i].Time=read();}
	for(int w=1;w<=n;++w,now^=1){
		for(int i=0;i<=M;++i)
			for(int j=0;j<=T;++j)
				if(i<arr[w].money||j<arr[w].Time) dp[now][i][j]=max(dp[now][i][j],dp[now^1][i][j]);
				else dp[now][i][j]=max(max(dp[now][i][j],dp[now^1][i][j]),dp[now^1][i-arr[w].money][j-arr[w].Time]+1);
	}
	printf("%d",dp[now^1][M][T]);
	return 0;
}
