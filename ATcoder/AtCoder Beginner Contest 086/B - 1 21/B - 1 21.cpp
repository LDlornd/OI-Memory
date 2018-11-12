#include<cmath>
#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
int main()
{
	string a,b,c,d;
	cin>>a>>b;
	c=a+b;d=b+a;
	int len=c.length(),sum1=0,sum2=0;
	for(int i=0;i<len;++i)
	{
		sum1=sum1*10+c[i]-'0';
		sum2=sum2*10+d[i]-'0';
	}
	int x=sqrt(sum1),y=sqrt(sum2);
	if(x*x==sum1||y*y==sum2) printf("Yes");
	else printf("No");
	return 0;
}
