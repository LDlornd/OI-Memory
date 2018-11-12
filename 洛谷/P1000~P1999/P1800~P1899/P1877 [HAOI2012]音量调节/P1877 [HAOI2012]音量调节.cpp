#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN1=51;
const int MAXN2=1001;
int n,beginlevel,maxlevel,k;
bool dp[MAXN1][MAXN2];
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read();beginlevel=read();maxlevel=read();
	dp[0][beginlevel]=true;
	for(int i=0;i<n;++i){
		k=read();
		for(int j=0;j<=maxlevel;++j){
			if(dp[i][j]&&j+k<=maxlevel) dp[i+1][j+k]=true;
			if(dp[i][j]&&j-k>=0) dp[i+1][j-k]=true;
		}
	}
	for(int i=maxlevel;i>=0;--i)
		if(dp[n][i]){
		printf("%d",i);
		return 0;
	}
	printf("-1");
	return 0;
}
