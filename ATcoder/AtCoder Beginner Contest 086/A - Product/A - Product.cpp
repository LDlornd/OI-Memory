#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	if((a&1)&&(b&1)) printf("Odd");
	else printf("Even");
	return 0;
}
