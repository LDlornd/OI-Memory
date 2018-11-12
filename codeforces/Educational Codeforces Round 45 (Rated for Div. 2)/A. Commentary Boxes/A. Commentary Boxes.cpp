#include<cstdio>
#include<iostream>
using namespace std;
long long int m,n,a,b,temp,ans;
int main(){
	scanf("%lld%lld%lld%lld",&n,&m,&a,&b);
	temp=n/m;
	ans=(n-temp*m)*b;
	ans=min(ans,((temp+1)*m-n)*a);
	printf("%lld",ans);
	return 0;
}
