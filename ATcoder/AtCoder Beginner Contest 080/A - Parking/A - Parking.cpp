#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	if(a*b<c) printf("%d",a*b);
	else printf("%d",c);
	return 0;
}
