#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int val[101],tim[101],maxval[1001];
int main()
{
	memset(maxval,0,sizeof(maxval));
	int t,n;
	scanf("%d%d",&t,&n);
	for(int i=1;i<=n;++i)
		scanf("%d%d",&tim[i],&val[i]);
	for(int i=1;i<=n;++i)
		for(int j=t;j>=tim[i];--j)
			maxval[j]=max(maxval[j],maxval[j-tim[i]]+val[i]);
	printf("%d",maxval[t]);
	return 0;
}
