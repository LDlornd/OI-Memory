#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN1=31;
const int MAXN2=20001;
int tiji[MAXN1];
int ans[MAXN2];
int main()
{
	memset(ans,0,sizeof(ans));
	int v,n;
	scanf("%d%d",&v,&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&tiji[i]);
	for(int i=1;i<=n;++i)
		for(int j=v;j>=tiji[i];--j)
			ans[j]=max(ans[j],ans[j-tiji[i]]+tiji[i]);
	printf("%d",v-ans[v]);
	return 0;
}
