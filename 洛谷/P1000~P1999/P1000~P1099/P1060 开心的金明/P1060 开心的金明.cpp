#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int imp[26],val[26];
int ans[30001];
int main()
{
	imp[0]=val[0]=0;
	memset(ans,0,sizeof(ans));
	int n,m,v,p;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d",&v,&p);
		imp[i]=v*p;
		val[i]=v;
	}
	for(int i=0;i<=m;++i)
		for(int j=n;j>=val[i];--j)
			ans[j]=max(ans[j],ans[j-val[i]]+imp[i]);
	printf("%d",ans[n]);
	return 0;
}
