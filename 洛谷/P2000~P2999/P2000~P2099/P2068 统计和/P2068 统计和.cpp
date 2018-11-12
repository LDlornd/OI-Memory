#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int MAXN=100001;
int val[MAXN];
int n,m,x,y;
char opt;
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
inline char read2()
{
	char c=getchar();
	while(c!='x'&&c!='y') c=getchar();
	return c;
}
int main()
{
	memset(val,0,sizeof(val));
	n=read(),m=read();
	for(int i=1;i<=m;++i)
	{
		opt=read2();
		x=read();y=read();
		if(opt=='x') modify(x,y);
		else if(opt=='y') printf("%d\n",query(y)-query(x-1));
	}
	return 0;
}
