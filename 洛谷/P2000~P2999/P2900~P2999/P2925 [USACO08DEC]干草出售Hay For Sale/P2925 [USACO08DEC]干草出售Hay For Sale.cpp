#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int rongliang=50001;
const int MAXN=5001;
int grass[MAXN];
int ans[rongliang];
int main()
{
	memset(ans,0,sizeof(ans));
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
		scanf("%d",&grass[i]);
	for(int i=1;i<=m;++i)
	{
		for(int j=n;j>=grass[i];--j)
			ans[j]=max(ans[j],ans[j-grass[i]]+grass[i]);
		/*for(int i=1;i<=n;++i)
			printf("%d ",ans[i]);
		printf("\n");*/
		if(ans[n]==n)
		{printf("%d",n);return 0;}
	}
	printf("%d",ans[n]);
	return 0;
}
