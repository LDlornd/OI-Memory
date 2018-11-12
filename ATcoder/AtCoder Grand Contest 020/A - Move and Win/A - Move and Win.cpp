#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	int n,a,b;
	scanf("%d%d%d",&n,&a,&b);
	if((a-b)&1) printf("Borys");
	else printf("Alice");
	return 0;
}
