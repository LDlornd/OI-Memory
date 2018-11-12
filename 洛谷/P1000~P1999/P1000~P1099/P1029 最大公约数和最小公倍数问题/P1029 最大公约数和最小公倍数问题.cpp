#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int gcd(int x,int y)
{
	if(x<y) swap(x,y);
	if(y==0) return x;
	return gcd(x%y,y);
}
int main()
{
	int m,n,k,flag,ans=0;
	scanf("%d%d",&m,&n);
	k=m*n;
	flag=sqrt(k);
	for(int i=1;i<=flag;++i)
	{
		if(k%i!=0||gcd(i,k/i)!=m) continue;
		++ans;
	}
	printf("%d",ans*2);
	return 0;
}
