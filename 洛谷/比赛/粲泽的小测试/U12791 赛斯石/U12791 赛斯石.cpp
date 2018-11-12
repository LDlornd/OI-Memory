#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=100001;
int a[11]={0,1,3,5,7,10,15,16,18,21,23};
int dp[MAXN];
int main()
{
	memset(dp,0,sizeof(dp));
	int limit,x;
	scanf("%d",&limit);
	for(int i=1;i<=10;++i)
	{
		scanf("%d",&x);
		a[i]=x-a[i];
	}
	for(int i=1;i<=10;++i)
		for(int j=i;j<=limit;++j)
			dp[j]=max(dp[j],dp[j-i]+a[i]);
	printf("%d",dp[limit]);
	return 0;
}
