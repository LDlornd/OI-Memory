#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int a,b,c,d,e,f;
	int dec1=9999,dec2=9999;
	scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
	int k=f/(100+e);
	if(k==0)
	{
		int flag=min(a,b);
		if(f>flag*100) printf("%d %d",f,f-flag*100);
		else printf("0 0");
		return 0;
	}
	for(int i=0;;++i)
	{
		if(a*i>k||dec1==0) break;
		for(int j=0;;++j)
		{
			int flag=a*i+b*j;
			if(flag>k) break;
			dec1=min(dec1,k-flag);
		}
	}
	for(int i=0;;++i)
	{
		if(c*i>e*(k-dec1)||dec2==0) break;
		for(int j=0;;++j)
		{
			int flag1=c*i+d*j,flag2=e*(k-dec1);
			if(flag1>flag2) break;
			dec2=min(dec2,flag2-flag1);
		}
	}
	int sugar=(k-dec1)*e-dec2,all=sugar+100*(k-dec1);
	printf("%d %d",all,sugar);
	return 0;
}
