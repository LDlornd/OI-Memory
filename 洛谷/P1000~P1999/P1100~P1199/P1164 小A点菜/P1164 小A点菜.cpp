#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN1=101;
const int MAXN2=10001;
int money[MAXN1],ans[MAXN2];
int main()
{
	memset(ans,0,sizeof(ans));
	ans[0]=1;
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%d",&money[i]);
	for(int i=1;i<=n;++i)
		for(int j=m;j>=money[i];--j)
			ans[j]+=ans[j-money[i]];
	printf("%d",ans[m]);
	return 0;
}
