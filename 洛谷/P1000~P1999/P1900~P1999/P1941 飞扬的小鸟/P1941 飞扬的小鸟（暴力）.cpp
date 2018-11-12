#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=10001;
int MAP[MAXN],up[MAXN],down[MAXN];
int optup[MAXN],optdown[MAXN];
int n,m,k,right=0,tot=0;
inline int read()
{
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
	return x;
}
inline int dfs(int height,int lie,int tot)
{
	if(lie==n-1) return;
	for(int i=1;;++i)
	{
		
	}
}
int main()
{
	n=read();m=read();k=read();
	for(int i=0;i<n;++i)
	{
		optup[i]=read();optdown[i]=read();
		up[i]=m+1;down[i]=0;
	}
	for(int i=0;i<k;++i)
	{
		int place=read(),d=read(),u=read();
		up[place]=u;down[placec]=d;
	}
	for(int i=0;i<=m;++i)
	{
		dfs(i,0,0);
		if(right==n)
		{
			
		}
	}
}
