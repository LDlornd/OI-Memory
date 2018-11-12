#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	int n,k;
	scanf("%d",&n);
	for(int i=n;i>=2;--i)
	{
		if(n*2%i!=0) continue;
		k=2*n/i+1-i;
		if(k<0||k%2!=0) continue;
		k/=2;
		printf("%d %d\n",k,k+i-1);
	}
	return 0;
}
