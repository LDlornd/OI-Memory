#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int a[100002],fa[100002],c[100002],f[100002];
int find(int x)
{
	if (fa[x]!=x) {fa[x]=find(fa[x]);}
	return fa[x];
}

int main()
{
	/*
	freopen("defile10.in","r",stdin);
	freopen("defile10.out","w",stdout);
	*/
	int n,k;
	scanf("%d %d\n",&n,&k);
	int m=0;
	for (int i=1;i<=n;i++)
	{
		scanf("%d ",&a[i]);
		if (a[i]>m) m=a[i];
	}
	m++;

	for (int i=0;i<=m;i++)
	{
		fa[i]=i;
	}

	for (int i=1;i<=n;i++)
	{
		int p,q;
		p=a[i];
		q=a[i]-k; if (q<0) q=0;
		int fp=find(p);
		int fq=find(q);
		if (fp!=fq)
		{
			fa[fp]=fq;
		}
	}
	for (int i=1;i<=n;i++)
	{
		int j=find(a[i]);
		c[j]++;
	}
	for (int i=0;i<=m;i++)
	{
		int j=find(i);
		c[j]--;
		f[j]=0;
	}
	c[find(0)]++;
	for (int i=0;i<=m;i++)
	{
		int j=find(i);
		if ((c[j]==-1) && (i>f[j]))
		{
			f[j]=i;
		}
	}
	int d=m;
	for (int i=0;i<=m;i++)
	{
		int j=find(i);
		if ((c[j]==-1) && (f[j]<d)) d=f[j];
	}
	int ans=0;
	for (int i=1;i<=n;i++)
	{
		if ((a[i]<d) || ((a[i]-k)<d)) {
		ans++; }
	}
	printf("%d %d\n",ans,d);
	return 0;
 }
