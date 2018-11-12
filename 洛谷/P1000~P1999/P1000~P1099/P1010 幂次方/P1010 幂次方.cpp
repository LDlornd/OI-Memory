#include<cstdio>
#include<iostream>
using namespace std;
inline void fenjie(int k)
{
	bool flag=true;
	int a[20],place=0;
	while(k!=0)
	{
		a[place++]=k&1;
		k/=2;
	}
	for(int i=place-1;i>=0;--i)
	{
		if(a[i]==1)
		{
			if(flag) flag=false;
			else printf("+");
			if(i==0) printf("2(0)");
			else if(i==1) printf("2");
			else if(i==2) printf("2(2)");
			else
			{
				printf("2(");
				fenjie(i);
				printf(")");
			}
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	fenjie(n);
	return 0;
}
