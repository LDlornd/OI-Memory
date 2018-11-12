#include<cstdio>
#include<iostream>
using namespace std;
typedef long long int ll;
const int MAXN=2e5+5;
int n,maxlen=1;
ll arr[MAXN],sum[MAXN];
ll dp[MAXN],get[MAXN];
int Queue[MAXN],head=1,tail=0; 
template<typename T>
T read(){
	T x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read<int>();
	for(int i=1;i<=n;++i) {arr[i]=read<ll>();sum[i]=sum[i-1]+arr[i];}
	for(int i=1;i<=n;++i){
		while(head<=tail&&sum[i]>=sum[Queue[head]]+get[Queue[head]]) ++head;
		dp[i]=dp[Queue[head-1]]+1;
		get[i]=sum[i]-sum[Queue[head-1]];
		while(head<=tail&&sum[i]+get[i]<sum[Queue[tail]]+get[Queue[tail]]) --tail;
		Queue[++tail]=i;
	}
	printf("%lld",n-dp[n]);
	return 0;
}
