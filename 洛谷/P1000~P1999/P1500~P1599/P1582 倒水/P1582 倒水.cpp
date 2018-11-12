#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	int n,m,ans=0;
	scanf("%d%d",&n,&m);
	if(n<=m)
	{
		printf("0");
		return 0;
	}
	while(true)
	{
		if(n&1)
		{
			if((n+1)/2<=m) break;
			else {
			}++ans;
		}
		else
		{
			n/=2;
			if(n<=m) break;
		}
	}
}
