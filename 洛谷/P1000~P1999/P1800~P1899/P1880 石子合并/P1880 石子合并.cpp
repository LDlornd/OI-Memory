#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=202;
const int INF=9999999;
int stone[MAXN],sum[MAXN];
int minans[MAXN][MAXN],maxans[MAXN][MAXN];
int MIN=INF,MAX=0;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&stone[i]);
		stone[i+n]=stone[i];
	}
	sum[0]=0;
	for(int i=1;i<=2*n;++i)
	{
		sum[i]=sum[i-1]+stone[i];
		minans[i][i]=0;maxans[i][i]=0;
		for(int j=i+1;j<=2*n;++j)
		{
			minans[i][j]=INF;
			maxans[i][j]=0;
		}
	}
	for(int i=2*n-1;i>=1;--i)
		for(int j=i+1;j<=2*n;++j)
			for(int k=i;k<j;++k)
			{
				minans[i][j]=min(minans[i][j],minans[i][k]+minans[k+1][j]+sum[j]-sum[i-1]);
				maxans[i][j]=max(maxans[i][j],maxans[i][k]+maxans[k+1][j]+sum[j]-sum[i-1]);
			}
	for(int i=1;i<=n;++i)
	{
		if(MIN>minans[i][i+n-1]) MIN=minans[i][i+n-1];
		if(MAX<maxans[i][i+n-1]) MAX=maxans[i][i+n-1];
	}
	printf("%d\n%d",MIN,MAX);
	return 0;
}
