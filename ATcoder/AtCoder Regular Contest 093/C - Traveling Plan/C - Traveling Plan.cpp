#include<cmath>
#include<cstdio>
#include<iostream>
using namespace std;
typedef long long int ll;
const int MAXN=1e5+1;
ll n,N,arr[MAXN];
ll chafen[MAXN],sum[MAXN];
inline ll read(){
	ll x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';
	return x*f;
}
inline ll getsum(int Start,int End){
	return abs(arr[Start]-arr[End]);
}
int main(){
	n=read();
	for(int i=1;i<=n;++i) arr[i]=read();
	for(int i=1;i<=n;++i) chafen[i]=abs(arr[i]-arr[i-1]);
	for(int i=1;i<=n;++i) sum[i]=sum[i-1]+chafen[i];
	printf("%lld\n",sum[n]-sum[2]+getsum(0,2)+getsum(n,0));
	for(int i=2;i<n;++i) printf("%lld\n",sum[i-1]+sum[n]-sum[i+1]+getsum(i-1,i+1)+getsum(n,0));
	printf("%lld\n",sum[n-1]+getsum(n-1,0));
	return 0;
}
