#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=2001;
struct edge
{
	int zsx,zsy,yxx,yxy;
}a[MAXN];
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
	int n=read(),m=read();
	for(int i=1;i<=n;++i)
	{
		a[i].zsx=read();a[i].zsy=read();
		a[i].yxx=read();a[i].yxy=read();
	}
	while(m--)
	{
		int x=read(),y=read(),tot=0,lastest=0;
		for(int i=1;i<=n;++i)
			if(x>=a[i].zsx&&x<=a[i].yxx&&y>=a[i].zsy&&y<=a[i].yxy)
				{++tot;lastest=i;}
		if(tot==0) printf("NO\n");
		else printf("YES %d %d\n",tot,lastest);
	}
	return 0;
}
