#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	int m,n,k;
	scanf("%d%d%d",&m,&n,&k);
	for(int i=0;i<=n;++i)
		for(int j=0;j<m;++j)
			if((m*i+n*j-2*i*j)==k)
				{printf("Yes");return 0;}
	printf("No");
	return 0;
}
