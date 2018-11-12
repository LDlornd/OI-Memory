#include<cstdio>
#include<iostream>
using namespace std;
inline int read()
{
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
	return x;
}
int main()
{
	int n=read(),t=read(),a;
	int ans=0,p=0,now=0;
	for(int i=1;i<=n;++i)
	{
		a=read();
		if(now>=a) now=a+t;
		else
		{
			ans+=(now-p);
			now=a+t;
			p=a;
		}
	}
	ans+=(now-p);
	printf("%d",ans);
	return 0;
}
