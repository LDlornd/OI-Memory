#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	int x,k,ans=0,num=0;
	scanf("%d%d",&x,&k);
	for(int i=1;i<=x;++i)
	{
		if(x%i==0) {ans+=i;++num;}
		if(num==k) break;
	}
	printf("%d",ans);
	return 0;
}
