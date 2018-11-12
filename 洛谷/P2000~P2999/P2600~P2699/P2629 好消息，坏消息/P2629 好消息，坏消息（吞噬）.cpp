#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=1000001;
int a[MAXN];
int zhan[MAXN],top=0;
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
	int n=read();
	for(int i=1;i<=n;++i)
		a[i]=read();
	for(int i=1;i<=n;++i)
	{
		zhan[++top]=a[i];
		while(zhan[top]<0&&top>1)
		{
			--top;
			zhan[top]+=zhan[top+1];
			zhan[top+1]=0;
		}
		while(zhan[top]<0)
		{
			zhan[top]+=a[n];
			--n;
			if(n<=i)
			{
				printf("0");
				return 0;
			}
		}
	}
	printf("%d",top);
	return 0;
}
