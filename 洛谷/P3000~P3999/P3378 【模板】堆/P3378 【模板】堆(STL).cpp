#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1000001;
int n,opt,num,tot=0;
int array[MAXN];
inline bool CMP(int a,int b)
{
	return a>b;
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
		if(opt==1)
		{
			array[++tot]=read();
			push_heap(array+1,array+tot+1,CMP);
		}
		else if(opt==2) printf("%d\n",array[1]);
		else
		{
			pop_heap(array+1,array+tot+1,CMP);
			--tot;
		}
	}
	return 0;
}
