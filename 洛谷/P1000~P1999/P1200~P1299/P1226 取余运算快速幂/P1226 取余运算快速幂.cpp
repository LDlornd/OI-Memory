#include<cstdio>
#include<iostream>
using namespace std;
typedef long long int ll;
ll quickmi(ll dishu,ll zhishu,ll chushu)
{
	ll ans=1;
	while(zhishu!=0)
	{
		dishu%=chushu;
		if(zhishu&1) {ans%=chushu;ans=ans*dishu%chushu;}
		dishu=dishu*dishu%chushu;
		zhishu>>=1;
	}
	return ans;
}
int main()
{
	ll b,p,k;
	scanf("%lld%lld%lld",&b,&p,&k);
	ll ans=quickmi(b,p,k);
	printf("%lld^%lld mod %lld=%lld",b,p,k,ans);
	return 0;
}
