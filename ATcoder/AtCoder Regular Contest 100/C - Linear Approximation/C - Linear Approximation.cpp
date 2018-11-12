#include<cmath>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long int ll;
const int MAXN=2e5+1;
ll ans=0;
int n,m;
int arr[MAXN];
inline bool CMP(int a,int b){
	return a<b;
}
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read();
	for(int i=1;i<=n;++i) arr[i]=read()-i;
	sort(arr+1,arr+n+1,CMP);
	m=(n&1)?((n>>1)+1):(n>>1);
	for(int i=1;i<=n;++i) ans+=(ll)abs(arr[i]-arr[m]);
	printf("%lld",ans);
	return 0;
}
