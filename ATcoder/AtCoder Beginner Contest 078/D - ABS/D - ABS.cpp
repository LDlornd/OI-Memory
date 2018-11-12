#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=2001;
const int INF=1000000001;
int a[MAXN];
int main()
{
	int n,z,w;
	scanf("%d%d%d",&n,&z,&w);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	int maxnum=0,pmax=0,minnum=INF,pmin=0;
	while(pmax<n||pmin<n)
	{
		for(int i=max(pmax,pmin)+1;i<=n;++i)
		{
			if(a[i]>maxnum) {maxnum=a[i];pmax=i;}
			if(a[i]<minnum) {minnum=a[i];pmin=i;}
		}
		
	}
}
