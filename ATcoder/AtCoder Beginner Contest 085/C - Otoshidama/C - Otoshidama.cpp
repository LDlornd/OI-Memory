#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	int n,total;
	scanf("%d%d",&n,&total);
	total/=1000;
	for(int i=0;i<=n;++i)
	{
		for(int j=0;j+i<=n;++j)
		{
			int h=n-i-j;
			if(i+5*j+10*h==total)
			{
				printf("%d %d %d",h,j,i);
				return 0;
			}
		}
	}
	printf("-1 -1 -1");
	return 0;
}
