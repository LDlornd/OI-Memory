#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int a,b,c,d,e,f,answater=0,anssugar=0;
	double midu=-1;
	scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
	a*=100;b*=100;
	for(int i=0;i*a<=f;++i)
		for(int j=0;i*a+j*b<=f;++j)
			for(int m=0;i*a+j*b+m*c<=f;++m)
				for(int n=0;i*a+j*b+m*c+n*d<=f;++n)
				{
					double water=i*a+j*b+m*c+n*d,sugar=m*c+n*d;
					if((i*a+j*b)*e/100<sugar) break; 
					double k=sugar/water;
					if(k>midu) {answater=water;anssugar=sugar;midu=k;}
				}
	printf("%d %d",answater,anssugar);
	return 0;
}
