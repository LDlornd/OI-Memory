#include<cstdio>
#include<iostream>
using namespace std;
typedef long long int ll;
const int MAXN=10001;
ll C[1007][1007];
ll kuaisumi(ll dishu,ll zhishu,ll chushu)
{
	ll tempans=1;
	while(zhishu!=0)
	{
		if(zhishu%2==1) {tempans*=dishu;tempans%=chushu;}
		dishu*=dishu;dishu%=chushu;
		tempans%=chushu;
		zhishu>>=1;
	}
	return tempans%chushu;
}
int main()
{
	//freopen("testdata.in","r",stdin);
	//freopen("ans.out","w",stdout);
	ll a,b,k,m,n,x;
	scanf("%lld%lld%lld%lld%lld",&a,&b,&k,&n,&m);
	x=min(m,n);
	for(int i=0;i<=k;++i)
		for(int j=0;j<=i;++j)
			if(i==j||j==0) C[i][j]=1;
			else C[i][j]=(C[i-1][j-1]+C[i-1][j])%10007;
	ll ans=kuaisumi(a,n,10007)*kuaisumi(b,m,10007)%10007;
	ans*=(C[k][x]%10007);ans%=10007;
	printf("%lld",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}
