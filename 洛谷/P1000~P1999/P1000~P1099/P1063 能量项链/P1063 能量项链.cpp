#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=202;
int a[MAXN];
int ans[MAXN][MAXN],MAX=0;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		a[i+n]=a[i];
	}
	for(int i=1;i<=2*n;++i)
		for(int j=i;j<=2*n;++j)
			ans[i][j]=0;
	for(int i=2*n-1;i>=1;--i)
		for(int j=i+1;j<=2*n;++j)
			for(int k=i;k<j;++k)
				ans[i][j]=max(ans[i][j],ans[i][k]+ans[k+1][j]+a[i]*a[k+1]*a[j+1]);
	for(int i=1;i<=n;++i)
		if(MAX<ans[i][i+n-1]) MAX=ans[i][i+n-1];
	printf("%d",MAX);
	return 0;
}
