#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	long long int k,n=-1,sum=0;
	while(scanf("%lld",&k)!=EOF)
	{
		++n;
		sum+=k;
	}
	if(n==-1) {cout<<0;return 0;}
	sum*=pow(2,n);
	cout<<sum;
	return 0;
}
