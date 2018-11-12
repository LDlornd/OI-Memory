#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=51;
const int INF=2147483647;
int n,minnum=INF,maxnum=-INF,minpos,maxpos;
int arr[MAXN];
inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
	return x*f;
}
int main()
{
	n=read();
	for(int i=1;i<=n;++i)
	{
		arr[i]=read();
		if(maxnum<arr[i]) {maxnum=arr[i];maxpos=i;}
		if(minnum>arr[i]) {minnum=arr[i];minpos=i;}
	}
	printf("%d\n",2*n-1);
	if(maxnum>=-minnum)
	{
		for(int i=1;i<=n;++i)
			printf("%d %d\n",maxpos,i);
		for(int i=2;i<=n;++i)
			printf("%d %d\n",i-1,i);
	}
	else
	{
		for(int i=1;i<=n;++i)
			printf("%d %d\n",minpos,i);
		for(int i=n;i>=2;--i)
			printf("%d %d\n",i,i-1);
	}
	return 0;
}
