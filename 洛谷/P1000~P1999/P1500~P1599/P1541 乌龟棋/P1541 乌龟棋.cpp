#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=355;
int n,m;
int arr[MAXN],cnt[5];
int dp[45][45][45][45];
int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read();m=read();
	for(int i=1;i<=n;++i) arr[i]=read();
	while(m--) ++cnt[read()];
	for(int k1=0;k1<=cnt[1];++k1){
		for(int k2=0;k2<=cnt[2];++k2){
			for(int k3=0;k3<=cnt[3];++k3){
				for(int k4=0;k4<=cnt[4];++k4){
					if(k1==0&&k2==0&&k3==0&&k4==0) dp[k1][k2][k3][k4]=arr[1];
					else{
						int now=1*k1+2*k2+3*k3+4*k4+1;
						if(k1!=0) dp[k1][k2][k3][k4]=max(dp[k1][k2][k3][k4],dp[k1-1][k2][k3][k4]+arr[now]);
						if(k2!=0) dp[k1][k2][k3][k4]=max(dp[k1][k2][k3][k4],dp[k1][k2-1][k3][k4]+arr[now]);
						if(k3!=0) dp[k1][k2][k3][k4]=max(dp[k1][k2][k3][k4],dp[k1][k2][k3-1][k4]+arr[now]);
						if(k4!=0) dp[k1][k2][k3][k4]=max(dp[k1][k2][k3][k4],dp[k1][k2][k3][k4-1]+arr[now]);
					}
				}
			}
		}
	}
	printf("%d",dp[cnt[1]][cnt[2]][cnt[3]][cnt[4]]);
	return 0;
}
