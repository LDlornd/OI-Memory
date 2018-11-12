#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=102;
int MAP[MAXN][MAXN],f[MAXN][MAXN];
int main()
{
	memset(MAP,0,sizeof(MAP));
	int m,n,ans=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			scanf("%d",&MAP[i][j]);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			if(MAP[i][j]==0) f[i][j]=0;
			else f[i][j]=min(f[i-1][j-1],min(f[i-1][j],f[i][j-1]))+1;
			ans=max(ans,f[i][j]);
		}
	printf("%d",ans);
	return 0;
}
