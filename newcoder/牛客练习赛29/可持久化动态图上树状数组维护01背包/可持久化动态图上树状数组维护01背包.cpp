#include<cstdio>
#include<iostream>
typedef long long int ll;
ll ans=0,k;
int n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%lld",&k);
		if(k>0) ans+=k;
		else ans+=k*i;
	}
	printf("%lld",ans);
	return 0;
}
