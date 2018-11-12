#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=202;
int MAP[MAXN][MAXN];
int main()
{
	memset(MAP,0,sizeof(MAP));
	int m,n,mid;
	scanf("%d%d",&n,&m);
	mid=m>>1;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			scanf("%d",&MAP[i][j]);
	for(int i=2;i<=n;++i)
		for(int j=1;j<=m;++j)
			MAP[i][j]+=max(MAP[i-1][j-1],max(MAP[i-1][j],MAP[i-1][j+1]));
	printf("%d",max(MAP[n][mid],max(MAP[n][mid+1],MAP[n][mid+2])));
	return 0;
}
