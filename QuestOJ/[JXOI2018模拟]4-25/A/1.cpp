#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=2e5+1;
int n,arr[MAXN],dp[MAXN];
long long int ans=0;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&arr[i]);
	}
	dp[n]=1;
	for(int i=n-1;i>=1;--i){
		if(arr[i]<arr[i+1]-1){
			ans=-1;
			break;
		}
		else if(arr[i]==0) continue;
		else if(arr[i]==1) dp[i]=1;
		else if(arr[i+1]==1) dp[i]=1;
		else if(arr[i]>=arr[i+1]) dp[i]=dp[i+1]+1;
		else dp[i]=dp[i+1];
	}
	if(arr[1]!=0) ans=-1;
	for(int i=1;i<=n;++i) cout<<dp[i]<<" ";cout<<endl;
	if(ans!=-1){
		for(int i=1;i<=n;++i)
			ans+=dp[i];
	}
	printf("%lld",ans);
	return 0;
}
