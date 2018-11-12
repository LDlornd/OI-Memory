#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	int n,sum=1;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		sum*=i;
		while(sum%10==0) sum/=10;
		sum%=1000;
	}
	printf("%d",sum%10);
	return 0;
}
