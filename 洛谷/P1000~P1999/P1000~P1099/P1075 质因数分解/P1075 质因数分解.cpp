#include<cstdio>
#include<cmath>
using namespace std;
bool judge(int n)
{
	if(n==2) return true;
	int k=ceil(sqrt(n));
	for(int i=2;i<=k;++i)
		if(n%i==0) return false;
	return true;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=2;;++i)
		if(judge(i)==true&&n%i==0)
			{printf("%d",n/i);return 0;}
}
