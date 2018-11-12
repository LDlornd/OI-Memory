#include<cstdio>
#include<iostream>
using namespace std;
typedef long long int ll;
ll k,m,ans=0;
int main(){
	scanf("%lld%lld",&k,&m);
	while(k){
		if(k%10==1) k/=10,++ans;
		else k+=m;
	}
	printf("%lld",ans);
	return 0;
}
