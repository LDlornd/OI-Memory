#include<cmath>
#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=205;
int n,sum=0,cnt,ans=0;
int arr[MAXN],dp[MAXN][MAXN];
int MIN(int a,int b){
	if(abs(a-sum)<abs(b-sum)) return a;
	else return b;
}
int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	cnt=(n=read())>>1;
	for(int i=1;i<=n;++i) sum+=(arr[i]=read());
	sum>>=1;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=cnt;++j){
			for(int k=j-1;k<i;++k){
				dp[i][j]=MIN(dp[i][j],dp[k][j-1]+arr[i]);
			}
		}
	}
	for(int i=cnt;i<=n;++i) ans=MIN(ans,dp[i][cnt]);
	printf("%d %d",ans,(sum<<1)-ans);
	return 0;
}
