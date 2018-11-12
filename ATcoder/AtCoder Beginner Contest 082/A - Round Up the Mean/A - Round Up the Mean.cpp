#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	double a,b,x;
	scanf("%lf%lf",&a,&b);
	x=(a+b)/2;
	if(x-(int)x<0.5) printf("%d",(int)x);
	else printf("%d",(int)x+1);
	return 0;
}
