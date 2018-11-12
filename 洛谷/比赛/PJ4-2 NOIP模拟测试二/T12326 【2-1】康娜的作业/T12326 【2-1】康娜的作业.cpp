#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	long long int t,x,y,z,a,b,c,flag=0;
	scanf("%lld",&t);
	for(int i=0;i<t;++i)
	{
		flag=0;
		scanf("%lld%lld%lld%lld%lld%lld",&x,&y,&z,&a,&b,&c);
		if(x>=a) flag+=(x-a)>>1;
		else flag-=(a-x);
		if(y>=b) flag+=(y-b)>>1;
		else flag-=(b-y);
		if(z>=c) flag+=(z-c)>>1;
		else flag-=(c-z);
		if(flag>=0) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
