#include<cstdio>
#include<iostream>
using namespace std;
typedef long long int ll;
const int MAXN=1e6+5;
int n,cnt=0;
ll prime[MAXN],help[MAXN],f[MAXN];
bool flag[MAXN];
void init(){
	f[1]=1;
	for(int i=2;i<MAXN;++i){
		if(flag[i]==false){
			prime[++cnt]=i;
			help[i]=i+1;
			f[i]=i+1;
		}
		for(int j=1;j<=cnt&&(ll)i*prime[j]<MAXN;++j){
			int tmp=i*prime[j];
			flag[tmp]=true;
			if(i%prime[j]==0){
				help[tmp]=help[i]*prime[j]+1;
				f[tmp]=f[i]/help[i]*help[tmp];
				break;
			}
			f[tmp]=f[i]*f[prime[j]];
			help[tmp]=prime[j]+1;
		}
	}
}
int main(){
	init();
	scanf("%d",&n);
	ll ans=n-1;
	for(int i=1;i<=n;++i){
		printf("%lld ",ans);
		ans=ans+n-f[i+1];
	}
	return 0;
}
