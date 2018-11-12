#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
using namespace std;
const int MAXN1=51;
const int MAXN2=500001;
int n,top=0,ans=0,height[MAXN1];
int dp[MAXN1][MAXN2];
bool vis[MAXN1][MAXN2];
struct backpack
{
	int cost,val;
	backpack(int cc=0,int vv=0) {cost=cc;val=vv;}
};
vector<backpack> group[MAXN1],k;
inline int read()
{
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
	return x*f;
}
int main()
{
	memset(dp,0,sizeof(dp));
	memset(vis,0,sizeof(vis));
	n=read();
	for(int i=1;i<=n;++i)
	{
		top+=(height[i]=read());
		group[i].push_back(backpack(height[i]*2,height[i]));
		group[i].push_back(backpack(height[i],0));
		vis[i][0]=true;
	}
	vis[0][0]=true;
	for(int i=1;i<=n;++i)
	{
		for(int j=top;j>=0;--j)
		{
			for(int k=0;k<2;++k)
			{
				backpack &a=group[i][k];
				if(a.cost>j) continue;
				if(vis[i-1][j-a.cost]&&dp[i-1][j-a.cost]+a.val>dp[i][j])
					{dp[i][j]=dp[i-1][j-a.cost]+a.val;vis[i][j]=true;}
			}
		}
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=top;++j)
				printf("%-3d",dp[i][j]);
			printf("\n");
		}
		printf("\n");
	}
	
	for(int i=1;i<=n;++i) ans=max(ans,dp[i][top]);
	if(ans==0) printf("-1");
	else printf("%d",ans);
	return 0;
}
