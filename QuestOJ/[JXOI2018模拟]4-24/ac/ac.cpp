#include<cstdio>
#include<iostream>
using namespace std;
typedef long long int ll;
const int mod=1e9+7;
const int MAXN=3010;
ll n,m,r,c,s,ans=0;
ll C[MAXN][MAXN];
inline ll read(){
	ll x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read();m=read();r=read();c=read();s=read();
	C[0][0]=1;
	for(int i=1;i<=3000;++i){
		C[i][0]=1;C[i][i]=1;
		for(int j=1;j<i;++j)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
	for(int i=0;i<=min(n,r);++i){
		for(int j=0;j<=min(m,c);++j){
			int temp=i*m+j*n-2*i*j;
			if(temp==s&&(r-i)%2==0&&(c-j)%2==0){
				ll N=n-1+(r-i)/2,M=m-1+(c-j)/2;
				(ans+=(C[n][i]*C[m][j]%mod*C[max(n-1,N)][min(n-1,N)]%mod*C[max(M,m-1)][min(M,m-1)]%mod))%=mod;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
