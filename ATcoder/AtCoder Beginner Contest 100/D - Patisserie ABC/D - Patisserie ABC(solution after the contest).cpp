#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long int ll;
const int MAXN=1001;
int n,m;
ll x[MAXN],y[MAXN],z[MAXN],sum[MAXN];
ll ans=0,temp;
int res[3];
inline bool CMP(ll a,ll b){
	return a>b;
}
template<typename T>
inline T read(){
	T x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read<int>();m=read<int>();
	for(int i=1;i<=n;++i){
		x[i]=read<ll>();y[i]=read<ll>();z[i]=read<ll>();
	}
	for(int i=0;i<8;++i){
		for(int j=0;j<3;++j)
			res[j]=(i&(1<<j))?1:-1;
		for(int j=1;j<=n;++j)
			sum[j]=x[j]*res[0]+y[j]*res[1]+z[j]*res[2];
		sort(sum+1,sum+n+1,CMP);
		temp=0;
		for(int j=1;j<=m;++j) temp+=sum[j];
		ans=max(ans,temp);
	}
	printf("%lld",ans);
	return 0;
}
