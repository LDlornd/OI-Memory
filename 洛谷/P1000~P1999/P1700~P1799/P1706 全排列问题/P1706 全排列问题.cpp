#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int MAXN=10;
bool vis[MAXN];
int ans[MAXN];
int n;
inline void dfs(int x)
{
	if(x==n)
	{
		for(int i=0;i<n;++i)
			printf("%5d",ans[i]);
		printf("\n");
		return;
	}
	for(int i=1;i<=n;++i)
	{
		if(vis[i]==false)
		{
			ans[x]=i;
			vis[i]=true;
			dfs(x+1);
			vis[i]=false;
		}
	}
}
int main()
{
	memset(vis,0,sizeof(vis));
	scanf("%d",&n);
	dfs(0);
	return 0;
}
