#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	if(n&1||n==2) printf("NO");
	else printf("YES");
	return 0;
}
