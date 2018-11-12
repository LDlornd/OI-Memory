#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	long long int n,m,d,tot1,tot2;
	scanf("%lld%lld%lld",&n,&m,&d);
	if(n%d==0) tot1=n/d;
	else tot1=n/d+1;
	if(m%d==0) tot2=m/d;
	else tot2=m/d+1;
	printf("%lld",tot1*tot2);
	return 0;
}
