#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int MAP[50][50];
int ans[50][50][50][50];
int main()
{
	ans[0][0][0][0]=0;
	int n,m,d1,d2,d3,d4;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			scanf("%d",&MAP[i][j]);
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			for(int x=0;x<n;++x)
			{
				for(int y=0;y<m;++y)
				{
					d1=d2=d3=d4=0;
					if(i!=0&&x!=0&&(i-1!=x-1||(i-1==x-1&&j!=y))) d1=ans[i-1][j][x-1][y];
					if(j!=0&&y!=0&&(j-1!=y-1||(j-1==y-1&&i!=x))) d2=ans[i][j-1][x][y-1];
					if(x!=0&&j!=0&&(x-1!=i||(x-1==i&&j-1!=y))) d3=ans[i][j-1][x-1][y];
					if(y!=0&&i!=0&&(y-1!=j||(y-1==j&&i-1!=x))) d4=ans[i-1][j][x][y-1];
					ans[i][j][x][y]=max(max(d1,d2),max(d3,d4))+MAP[i][j]+MAP[x][y];
				}
			}
		}
	}
	printf("%d",ans[n-1][m-1][n-1][m-1]);
	return 0;
}
