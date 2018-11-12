#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int a[100000],flag[100000][16],ans[100000];
int main()
{
	int m,n;
	scanf("%d%d",&m,&n);
	for(int i=0;i<m;++i)
		scanf("%d",&a[i]);
	for(int i=0;i<m;++i) flag[i][0]=a[i];
	for(int i=1;(1<<i)<m;++i)
	{
		for(int j=0;j-1+(1<<i)<m;++j)
			flag[j][i]=min(flag[j][i-1],flag[j+(1<<(i-1))][i-1]);
	}
	for(int i=0;i<n;++i)
	{
		int l,r,k=0;
		scanf("%d%d",&l,&r);
		--l,--r;
		while(l+(1<<(k+1))<=r+1) ++k;
		ans[i]=min(flag[l][k],flag[r-(1<<k)+1][k]);
	}
	for(int i=0;i<n;++i)
		printf("%d ",ans[i]);
	return 0;
}
