#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=8;
const int INF=100000;
int n;
int six[MAXN],nin[MAXN];
int dp[INF+1];
int main(){
	scanf("%d",&n);
	six[0]=nin[0]=1;
	for(int i=1;i<MAXN;++i){
		six[i]=six[i-1]*6;
		nin[i]=nin[i-1]*9;
	}
	for(int i=1;i<=n;++i){
		dp[i]=i;
		for(int j=0;j<MAXN;++j){
			if(six[j]>i) break;
			dp[i]=min(dp[i],dp[i-six[j]]+1);
		}
		for(int j=1;j<MAXN;++j){
			if(nin[j]>i) break;
			dp[i]=min(dp[i],dp[i-nin[j]]+1);
		}
	}
	printf("%d",dp[n]);
	return 0;
}
