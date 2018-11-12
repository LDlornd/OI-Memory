#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
bool a[100000000];
char s[10];
bool judge1(int a)
{
	int k=ceil(sqrt(a));
	for(int i=2;i<k;++i)
		if(a%i==0) return false;
	return true;
}
bool judge2(char a[],int n)
{
	for(int i=0,j=n-1;i<j;++i,--j)
		if(a[i]!=a[j]) return false;
	return true;
}
void change(bool a[])
{
	for(int i=1;i<100000000;++i)
	{
		for(int j=i*2;j<100000000;j+=i)
			a[j]=1;
	}
}
int main()
{
	memset(a,0,sizeof(a));
	int m,n;
	scanf("%d%d",&m,&n);
	//change(a);
	for(int i=m;i<=n;++i)
	{
		printf("%d,",i);
	}
	return 0;
}
