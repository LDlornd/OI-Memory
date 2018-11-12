#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int imp[61][3],val[61][3],fujian[61];
int ans[61][3201];
int v,p,q,n,m,num=0;
int main()
{
	memset(imp,0,sizeof(imp));
	memset(val,0,sizeof(val));
	memset(ans,0,sizeof(ans));
	scanf("%d%d",&n,&m);
	n/=10;
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d%d",&v,&p,&q);
		fujian[i]=q;
		if(q==0)
		{
			val[i][0]=v/10;
			imp[i][0]=p*v;
			continue;
		}
		if(val[q][1]!=0) {val[q][2]=v/10;imp[q][2]=p*v;}
		else {val[q][1]=v/10;imp[q][1]=p*v;}
	}
	for(int i=1;i<=m;++i)
	{
		for(int j=n;j>=0;--j)
		{
			ans[i][j]=ans[i-1][j];
			if(j>=val[i][0]) ans[i][j]=max(ans[i][j],ans[i-1][j-val[i][0]]+imp[i][0]);
			if(j>=val[i][0]+val[i][1]) ans[i][j]=max(ans[i][j],ans[i-1][j-val[i][0]-val[i][1]]+imp[i][0]+imp[i][1]);
			if(j>=val[i][0]+val[i][2]) ans[i][j]=max(ans[i][j],ans[i-1][j-val[i][0]-val[i][2]]+imp[i][0]+imp[i][2]);
			if(j>=val[i][0]+val[i][1]+val[i][2]) ans[i][j]=max(ans[i][j],ans[i-1][j-val[i][0]-val[i][1]-val[i][2]]+imp[i][0]+imp[i][1]+imp[i][2]);
		}
	}
	printf("%d",ans[m][n]);
	return 0;
}
/*f[i,j]=max
{
f[i-1,j],

f[i-1,j-w[i,0]]+v[i,0],

f[i-1,j-w[i,0]-w[i,1]]+v[i,0]+v[i,1],

f[i-1,j-w[i,0]-w[i,2]]+v[i,0]+v[i,2],

f[i-1,j-w[i,0]-w[i,1]-w[i,2]]+v[i,0]+v[i,1]+v[i,2]
}*/
