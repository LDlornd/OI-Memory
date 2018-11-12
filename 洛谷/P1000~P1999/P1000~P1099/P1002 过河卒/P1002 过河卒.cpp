#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
long long int a[21][21];
int main()
{
	memset(a,0,sizeof(a));
	int n,m,x,y;
	scanf("%d%d%d%d",&m,&n,&x,&y);
	for(int i=0;i<=n;++i)
		for(int j=0;j<=m;++j)
		{
			if((i==y&&j==x)||(abs(j-x)==2&&abs(i-y)==1)||(abs(j-x)==1&&abs(i-y)==2))
				continue;
			if(i==0&&j!=1&&a[i][j-1]==0) continue;
			if(j==0&&i!=1&&a[i-1][j]==0) continue;
			if(i==0||j==0) {a[i][j]=1;continue;}
			a[i][j]=a[i][j-1]+a[i-1][j];
		}
	printf("%d",a[n][m]);
	return 0;
}
