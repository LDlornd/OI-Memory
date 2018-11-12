#include<cstdio>
#include<iostream>
using namespace std;
typedef long long int ll;
int a[1000001];
ll fastmi(ll dishu,ll zhishu,ll chushu)
{
	int ans=1;
	while(zhishu!=0)
	{
		dishu%=chushu;
		if(zhishu&1) {ans%=chushu;ans*=dishu;}
		dishu*=dishu;
		zhishu=zhishu>>1;
	}
	ans%=chushu;
	return ans;
}
int main()
{
	ll n,m,k,x;
	scanf("%lld%lld%lld%lld",&n,&m,&k,&x);
	a[0]=0;
	for(int i=1;i<n;++i)
		a[i]=(a[i-1]+m)%n;
	int flag=fastmi(10,k,n);
	printf("%d",(a[flag]+x)%n);
	return 0;
}
