#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
typedef long long int ll;
const int MAXN=1005;
int n;
ll ans;
ll arr[MAXN],dp[MAXN];
template<typename T>
T read(){
	T x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	while(true){
		if((n=read<int>())==0) break;
		for(int i=1;i<=n;++i) arr[i]=read<ll>();
		memset(dp,0,sizeof(dp));ans=0;
		for(int i=1;i<=n;++i){
			for(int j=0;j<i;++j)
				if(arr[j]<arr[i]) dp[i]=max(dp[i],dp[j]+arr[i]);
			ans=max(ans,dp[i]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
