#include<cstdio>
#include<iostream>
using namespace std;
typedef long long int ll;
const int MAXN=1e5+1;
const int mod1=1e9+9;
const int mod2=1e9+7;
int n,k,p;
ll fib[MAXN],f[MAXN],F[MAXN],s=0,ans=0;
inline ll quickmi(ll base,ll index,int mod){
	int temp=1;
	base%=mod;
	while(index>1){
		if(index&1) (temp*=base)%=mod;
		index>>=1;
		(base*=base)%=mod;
	}
	return (temp*=base)%=mod;
}
int main(){
	freopen("sbt.in","r",stdin);
	freopen("sbt.out","w",stdout);
	scanf("%d%d%d",&n,&k,&p);
	fib[0]=0;fib[1]=1;
	for(int i=2;i<=n;++i) fib[i]=fib[i-1]+fib[i-2];
	for(int i=1;i<=n;++i) f[i]=quickmi(fib[i],k,mod1);
	for(int i=1;i<=n;++i) (s+=f[i])%=mod1;
	s%=p;
	for(int i=1;i<=s;++i){
		ll temp=2*i*i-3*i+3;
		for(int j=1;j<i;++j)
			if(i%j==0) temp-=F[j];
		F[i]=temp;
		(ans+=F[i])%=mod2;
	}
	printf("%d",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}
