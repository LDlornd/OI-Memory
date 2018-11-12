#include<cstdio>
#include<iostream>
using namespace std;
typedef long long int ll;
const int MAXN=1e5+5;
int n;
ll arr[MAXN<<1];
ll addsum[MAXN],powersum[MAXN];
template<typename T>
T read(){
	T x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read<int>();
	for(int i=1;i<=n;++i) arr[n+i]=arr[i]=read<ll>();
	for(int i=1;i<=(n<<1);++i){
		addsum[i]=addsum[i-1]+arr[i];
		powersum[i]=powersum[i-1]+arr[i]*arr[i];
	}
	for(int i=2;i<=(n+1);++i){
		ll ans=(n-1)*(powersum[i+n-2]-powersum[i-1]);
		ans-=(addsum[i+n-2]-addsum[i-1])*(addsum[i+n-2]-addsum[i-1]);
		printf("%lld ",ans);
	}
	return 0;
}
