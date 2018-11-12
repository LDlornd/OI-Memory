#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int num[10];
int main()
{
	memset(num,0,sizeof(num));
	int n,tot=0,ans=1;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		int k=i;
		while(k%5==0)
		{
			k/=5;
			++tot;
		}
		while(k%2==0&&tot>0)
		{
			k/=2;
			--tot;
		}
		ans*=k;
		ans%=10;
	}
	while(tot>0)
	{
		ans*=5;
		while(ans%10==0) ans/=10;
		ans%=10;
		--tot;
	}
	printf("%d",ans);
	return 0;
}
