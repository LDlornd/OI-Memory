#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int MAXN=500001;
int a[MAXN],val[MAXN];
int n,m,opt,x,y,k;
inline void modify(int place,int add)
{
	for(;place<=n;place+=(place&-place))
		val[place]+=add;
}
inline int query(int place)
{
	int tot=0;
	for(;place;place-=(place&-place))
		tot+=val[place];
	return tot;
}
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
	memset(val,0,sizeof(val));
	n=read();m=read();
	for(int i=1;i<=n;++i)
		a[i]=read();
	while(m--)
	{
		opt=read();
		if(opt==1)
		{
			x=read();y=read();k=read();
			modify(x,k);modify(y+1,-k);
		}
		else if(opt==2)
		{
			x=read();
			printf("%d\n",query(x)+a[x]);
		}
	}
	return 0;
}
