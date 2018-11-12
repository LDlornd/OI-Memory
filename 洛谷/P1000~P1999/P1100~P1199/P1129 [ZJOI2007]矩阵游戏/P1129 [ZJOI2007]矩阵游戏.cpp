#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int MAXN=201;
int numq,n,ans=0;
int edge[MAXN][MAXN],flag[MAXN];
bool vis[MAXN];
inline bool Find(int place)
{
	for(int i=1;i<=n;++i)
		if(edge[place][i]&&vis[i]==false)
		{
			vis[i]=true;
			if(flag[i]==0||Find(flag[i]))
			{
				flag[i]=place;
				return true;
			}
		}
	return false;
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
	numq=read();
	while(numq--)
	{
		memset(flag,0,sizeof(flag));
		ans=0;n=read();
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				edge[i][j]=read();
		for(int i=1;i<=n;++i)
		{
			memset(vis,0,sizeof(vis));
			if(Find(i)) ++ans;
		}
		if(ans==n) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
