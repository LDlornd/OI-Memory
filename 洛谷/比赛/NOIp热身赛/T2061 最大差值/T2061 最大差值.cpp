#include<cstdio>
#include<iostream>
using namespace std;
typedef long long int ll;
const int MAXN=1000005;
const int INF=2147483647;
int n;
ll ans=-INF;
ll arr[MAXN],Left[MAXN],Right[MAXN];
template<typename T>
T read(){
	T x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read<int>();
	for(int i=1;i<=n;++i) arr[i]=read<int>();
	Left[2]=arr[1];Right[n-1]=arr[n+1];
	for(int i=3;i<=n;++i) Left[i]=min(arr[i-1],Left[i-1]);
	for(int i=n-2;i>=1;--i) Right[i]=max(arr[i+1],Right[i+1]);
	for(int i=2;i<=n-1;++i){
		ans=max(ans,Right[i]-min(Left[i],arr[i]));
		ans=max(ans,max(arr[i],Right[i])-Left[i]);
	}
	ans=max(ans,Right[1]-arr[1]);
	ans=max(ans,arr[n]-Left[n]);
	printf("%lld",ans);
	return 0;
}
