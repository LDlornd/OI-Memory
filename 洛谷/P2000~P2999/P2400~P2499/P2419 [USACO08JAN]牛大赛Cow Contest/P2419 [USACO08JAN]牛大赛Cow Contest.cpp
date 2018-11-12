#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int MAXN=101;
bool con[MAXN][MAXN];
int main()
{
	memset(con,0,sizeof(con));
	int n,m,x,y,ans=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) con[i][i]=true;
	for(int i=0;i<m;++i)
	{
		scanf("%d%d",&x,&y);
		con[y][x]=true;
	}
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				con[i][j]=con[i][j]||(con[i][k]&&con[k][j]);
	for(int i=1;i<=n;++i)
	{
		int tot=1;
		for(int j=1;j<=n;++j)
			if(con[i][j]==false&&con[j][i]==false) {tot=0;break;}
		ans+=tot;
	}
	printf("%d",ans);
	return 0;
}
