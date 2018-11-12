#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=105;
int T,M,now=1,tt;
int cost[MAXN],val[MAXN];
int dp[2][1005];
int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	T=read();M=read();
	for(int i=1;i<=M;++i) {cost[i]=read();val[i]=read();}
	for(int w=1;w<=M;++w,now^=1){
		for(int i=0;i<min(T,cost[w]);++i)
			dp[now][i]=max(dp[now][i],dp[now^1][i]);
		for(int i=cost[w];i<=T;++i)
			dp[now][i]=max(max(dp[now][i],dp[now^1][i]),dp[now^1][i-cost[w]]+val[w]);
	}
	printf("%d",dp[now^1][T]);
	return 0;
}
