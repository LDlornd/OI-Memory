#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=1000001;
int n,opt,num,tot=0;
int array[MAXN];
inline void add(int val)
{
	array[++tot]=val;
	int now=tot;
	while(now>1)
	{
		int fa=now>>1;
		if(array[fa]<=array[now]) return;
		swap(array[fa],array[now]);
		now=fa;
	}
}
inline void delmin()
{
	int now=1;
	array[1]=array[tot--];
	while(now*2<=tot)
	{
		int son=now<<1;
		if(son<tot&&array[son]>array[son+1]) ++son;
		if(array[now]<=array[son]) return;
		swap(array[now],array[son]);
		now=son;
	}
}
inline int read()
{
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
	return x*f;
}
int main()
{
	n=read();
	while(n--)
	{
		opt=read();
		if(opt==1) {num=read();add(num);}
		else if(opt==2) printf("%d\n",array[1]);
		else if(opt==3) delmin();
	}
	return 0;
}
