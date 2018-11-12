#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	int n,a;
	scanf("%d%d",&n,&a);
	n*=n;
	n-=a;
	printf("%d",n);
	return 0;
}
