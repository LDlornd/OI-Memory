#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1000001;
int con[MAXN];
int n,x,inf=0;
int main()
{
	memset(con,0,sizeof(con));
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&x);
		if(inf<x) inf=x;
		for(int j=1;j*j<=x;++j)
			if(x%j==0)
			{
				int k=x/j;
				++con[j];
				if(k!=j) ++con[k];
			}
	}
	int j=inf;
	for(int i=1;i<=n;++i)
		for(;j>=1;--j)
			if(con[j]>=i)
			{
				printf("%d\n",j);
				break;
			}
	return 0;
}
