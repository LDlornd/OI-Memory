#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int MAXN=2001;
int zuhe[MAXN][MAXN];
int num[MAXN][MAXN];
int main()
{
	memset(num,0,sizeof(num));
	int k,t,x,y;
	scanf("%d%d",&t,&k);
	for(int i=0;i<=2000;++i)
		for(int j=0;j<=i;++j)
		{
			if(j==0||j==i) zuhe[i][j]=1;
			else zuhe[i][j]=(zuhe[i-1][j-1]+zuhe[i-1][j])%k;
		}
	for(int i=1;i<=2000;++i)
		for(int j=1;j<=2000;++j)
		{
			num[i][j]+=(num[i-1][j]+num[i][j-1]-num[i-1][j-1]);
			if(zuhe[i][j]==0) ++num[i][j];
		}
	for(int i=0;i<t;++i)
	{
		scanf("%d%d",&x,&y);
		if(x<y) y=x;
		printf("%d\n",num[y][x]);
	}
	return 0;
}
