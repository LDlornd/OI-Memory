#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long int ll;
const int MAXN=100005;
const int mod=1e9+7;
int n,m;
ll dp[MAXN];
ll fac[MAXN*3],inv[MAXN*3];
struct node{
	int x,y,z;
	node() {x=y=z=0;}
}arr[MAXN];
ll quick_mi(ll base,ll index){
	ll temp=1;
	while(index){
		if(index&1) temp=temp*base%mod;
		base=base*base%mod;
		index>>=1;
	}
	return temp;
}
void init(){
	fac[0]=1;inv[0]=1;
	for(int i=1;i<=n*3;++i) fac[i]=fac[i-1]*i%mod;
	inv[n*3]=quick_mi(fac[n*3],mod-2);
	for(int i=n*3-1;i>=1;--i) inv[i]=inv[i+1]*(i+1)%mod;
}
ll comb(int k1,int k2,int k3){
	return fac[k1+k2+k3]*inv[k1]%mod*inv[k2]%mod*inv[k3]%mod;
}
bool CMP(const node &a,const node &b){
	if(a.x==b.x&&a.y==b.y) return a.z<b.z;
	else if(a.x==b.x) return a.y<b.y;
	else return a.x<b.x;
}
int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	freopen("poly.in","r",stdin);
	freopen("poly.out","w",stdout);
	n=read();m=read();
	init();
	for(int i=1;i<=m;++i) {arr[i].x=read();arr[i].y=read();arr[i].z=read();}
	arr[++m].x=n;arr[m].y=n;arr[m].z=n;
	sort(arr+1,arr+m+1,CMP);
	for(int i=1;i<=m;++i){
		dp[i]=comb(arr[i].x,arr[i].y,arr[i].z);
		for(int j=1;j<i;++j){
			if(arr[j].x>arr[i].x||arr[j].y>arr[i].y||arr[j].z>arr[i].z) continue;
			dp[i]=(dp[i]-dp[j]*comb(arr[i].x-arr[j].x,arr[i].y-arr[j].y,arr[i].z-arr[j].z)+mod)%mod;
		}
	}
	printf("%lld",dp[m]);
	return 0;
}
