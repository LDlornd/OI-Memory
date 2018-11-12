#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	long long int n,m,a,ansn,ansm;
	scanf("%lld%lld%lld",&n,&m,&a);
	ansn=(n%a==0)?(n/a):(n/a+1);
	ansm=(m%a==0)?(m/a):(m/a+1);
	printf("%lld",ansm*ansn);
	return 0;
}
