#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=1e7+5;
int L,S,T,m,k;
bool flag[MAXN];
int dp[MAXN];
int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	freopen("testdata.in","r",stdin);
	freopen("tle.out","w",stdout);
	L=read();S=read();T=read();m=read();
	for(int i=1;i<=m;++i){
		k=read();
		flag[k]=true;
	}
	for(int i=1;i<=L;++i) dp[i]=MAXN;
	for(int i=0;i<=L;++i){
		for(int j=S;j<=T;++j){
			if(i+j<L) dp[i+j]=min(dp[i+j],dp[i]+flag[i+j]);
			else dp[L]=min(dp[L],dp[i]);
		}
	}
	printf("%d",dp[L]);
	return 0;
}
