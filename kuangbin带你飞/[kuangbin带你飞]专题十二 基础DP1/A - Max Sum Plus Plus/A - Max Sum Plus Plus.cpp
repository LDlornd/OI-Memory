#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
typedef long long int ll;
const ll INF=32768100000;
const int MAXN=1e6+5;
int n,m,now;
ll temp;
ll arr[MAXN],dp[MAXN],flag[MAXN];
ll read(){
	ll x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	while(scanf("%d%d",&m,&n)!=EOF){
		memset(dp,0,sizeof(dp));
		memset(flag,0,sizeof(flag));
		for(int i=1;i<=n;++i) arr[i]=read();
		for(int i=1;i<=m;++i){
			temp=-INF;
			for(int j=i;j<=n;++j){
				dp[j]=max(dp[j-1],flag[j-1])+arr[j];
				flag[j-1]=temp;
				temp=max(dp[j],temp);
			}
		}
		printf("%lld\n",temp);
	}
	return 0;
}
