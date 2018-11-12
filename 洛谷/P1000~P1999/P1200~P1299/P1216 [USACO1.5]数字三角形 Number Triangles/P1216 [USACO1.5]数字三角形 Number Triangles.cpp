#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int n,m=0;
	scanf("%d",&n);
	int a[n][n];
	memset(a,0,sizeof(a));
	for(int i=0;i<n;++i)
		for(int j=0;j<=i;++j)
			scanf("%d",&a[i][j]);
	for(int i=1;i<n;++i)
		for(int j=0;j<=i;++j)
		{
			if(j==0) a[i][j]+=a[i-1][j];
			else a[i][j]+=max(a[i-1][j],a[i-1][j-1]);
		}
	for(int i=0;i<n;++i)
		if(m<a[n-1][i]) m=a[n-1][i];
	printf("%d",m);
	return 0;
}
