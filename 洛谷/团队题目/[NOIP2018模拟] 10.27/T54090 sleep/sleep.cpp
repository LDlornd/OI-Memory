#include<cstdio>
#include<iostream>
using namespace std;
typedef long long int ll;
const int MAXN=200005;
int n,k,flag[MAXN];
ll arr[MAXN],sum[2][MAXN];
ll ans=0;
template<typename T>
T read(){
	T x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	freopen("sleep.in","r",stdin);
	freopen("sleep.out","w",stdout);
	n=read<int>();k=read<int>();
	for(int i=1;i<=n;++i){
		arr[i]=read<ll>();
		sum[0][i]=sum[0][i-1]+arr[i];
	}
	for(int i=1;i<=n;++i){
		flag[i]=read<int>();
		sum[1][i]=sum[1][i-1]+arr[i]*flag[i];
	}
	for(int i=1;i<=n;++i){
		int j=min(i+k-1,n);
		ans=max(ans,sum[1][i-1]-sum[1][0]+sum[1][n]-sum[1][j]+sum[0][j]-sum[0][i-1]);
	}
	printf("%lld",ans);
	return 0;
}
