#include<cstdio>
#include<iostream>
using namespace std;
int MAP[16][16],flag=0;
int dx[5]={0,0,-1,0,1};
int dy[5]={0,-1,0,1,0};
int m,n,sx,sy,ex,ey,now=1;
int lux[500],luy[500];
inline void dfs(int nx,int ny)
{
	if(nx==ex&&ny==ey)
	{
		flag=1;
		for(int i=1;i<now;++i)
			printf("(%d,%d)->",lux[i],luy[i]);
		printf("(%d,%d)\n",lux[now],luy[now]);
		return;
	}
	for(int i=1;i<=4;++i)
	{
		if(nx+dx[i]<=m&&nx+dx[i]>0&&ny+dy[i]<=n&&ny+dy[i]>0&&MAP[nx+dx[i]][ny+dy[i]]==1)
		{
			++now;
			lux[now]=nx+dx[i];
			luy[now]=ny+dy[i];
			MAP[lux[now]][luy[now]]=0;
			dfs(lux[now],luy[now]);
			MAP[lux[now]][luy[now]]=1;
			--now;
		}
	}
}
int main()
{
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;++i)
		for(int j=1;j<=n;++j)
			scanf("%d",&MAP[i][j]);
	scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
	lux[1]=sx;luy[1]=sy;MAP[sx][sy]=1;
	dfs(sx,sy);
	if(flag==0) printf("-1");
	return 0;
}
