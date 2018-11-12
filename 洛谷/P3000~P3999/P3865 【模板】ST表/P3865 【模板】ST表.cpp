#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=100001;
int n,q,l,r;
int a[MAXN],ans[MAXN][15];
inline int read()
{
	int x=0;
	char c=getcha();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
}
void getready()
{
	for(int i=1;i<=n;++i) ans[i][0]=a[i];
	for(int i=1;i<15;++i)
	{
		for(int j=1;j+(1<<i)<=n;++j)
		{
			ans[]
		}
	}
}
int main()
{
	n=read();q=read();
	for(int i=1;i<=n;++i)
		a[i]=read();
	getready(n);
	for(int w=0;w<q;++w)
	{
		l=read();r=read();
		
	}
}
