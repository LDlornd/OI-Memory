#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int tim[100001],val[100001],maxval[100001];
int main()
{
	memset(maxval,0,sizeof(maxval));
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
		scanf("%d%d",&tim[i],&val[i]);
	for(int i=1;i<=m;++i)
		for(int j=1;j<=n;++j)
			if(j<tim[i]) continue;
			else maxval[j]=max(maxval[j],maxval[j-tim[i]]+val[i]);
	printf("%d",maxval[n]);
	return 0;
}
