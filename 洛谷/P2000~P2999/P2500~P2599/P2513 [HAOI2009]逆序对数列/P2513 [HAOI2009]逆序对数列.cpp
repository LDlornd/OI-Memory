#include<cstdio>
#include<iostream>
using namespace std;
const int mod=10000;
const int MAXN=1005;
int n,m,k;
int dp[MAXN],sum[MAXN];
int main(){
	scanf("%d%d",&n,&m);
	dp[0]=1;
	for(int i=0;i<=m;++i) sum[i]=1;
	for(int i=1;i<=n;++i){
		k=min(m,i*(i-1)/2);
		for(int j=1;j<=k;++j){
			if(j<i) dp[j]=sum[j];
			else dp[j]=sum[j]-sum[j-i];
			while(dp[j]<0) dp[j]+=mod;
		}
		for(int j=1;j<=m;++j)
			sum[j]=(sum[j-1]+dp[j])%mod;
	}
	printf("%d",dp[m]);
	return 0;
}
