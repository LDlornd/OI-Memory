#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	int n,k,tot=0;
	scanf("%d",&n);
	k=n;
	while(k!=0)
	{
		tot+=(k%10);
		k/=10;
	}
	if(n%tot==0) printf("Yes");
	else printf("No");
	return 0;
}
