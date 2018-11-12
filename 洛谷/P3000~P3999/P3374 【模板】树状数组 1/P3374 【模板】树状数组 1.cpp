#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int MAXN=500001;
int a[MAXN],pre[MAXN],val[MAXN];
int n,m,opt,x,y;
inline void modify(int place,int add)
{
	for(;place<=n;place+=(place&-place))
		val[place]+=add;
}
inline int query(int place)
{
	int r=0;
	for(;place;place-=(place&-place))
		r+=val[place];
	return r;
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
	n=read(),m=read();
	pre[0]=0;
	for(int i=1;i<=n;++i)
		pre[i]=(pre[i-1]+(a[i]=read()));
	for(int i=1;i<=m;++i)
	{
		opt=read();x=read();y=read();
		if(opt==1) modify(x,y);
		else if(opt==2) printf("%d\n",query(y)-query(x-1)+pre[y]-pre[x-1]);
	}
	return 0;
}
