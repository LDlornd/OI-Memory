#include <cstdio>

#include <cmath>

#include <algorithm>

#include <cstring>

#include <queue>


#include <time.h>

using namespace std;

int a[10000001],b[10000001];
int p[100001];
int n;
int main()
{
	srand((unsigned)time(NULL));
	//freopen("search8.in","w",stdout);
	int n=1000;
	int m=0;
	for (int i=1;i<=n;i++)
	{
		a[++m]=i;
		b[m]=i+n;
		for (int j=1;j<=n;j++){

		a[++m]=i;
		b[m]=2*n+j;
		a[++m]=i+n;
		b[m]=3*n+j; }
	}

	a[++m]=1;
	b[m]=4*n+1;
	a[++m]=1+n;
	b[m]=4*n+1;

	for (int i=1;i<=4*n+1;i++) p[i]=i;

	for (int i=1;i<=15*n;i++)
	{
		int x,y;
		x=rand()*rand() % (4*n+1)+1;
		y=rand()*rand() % (4*n+1)+1;
		int z=p[x];
		p[x]=p[y];
		p[y]=z;
	 }

	printf("%d %d\n",4*n+1,m);
	for (int i=1;i<=m;i++)
	printf("%d %d \n",p[a[i]],p[b[i]]);
	fclose(stdout);
	freopen("search8.out","w",stdout);
	printf("%d %d %d\n",p[1],p[1+n],p[1+4*n]);
	return 0;
}
