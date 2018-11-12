#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>
#include <time.h>
using namespace std;

int n,m;
bool g[1001][1001];

int main()
{
	/*
	srand((unsigned)time(NULL));
	freopen("search8.in","r",stdin);
	freopen("search88.out","w",stdout);
	*/
	scanf("%d %d\n",&n,&m);
	for (int i=1;i<=m;i++)
	{
		int a,b;
		scanf("%d %d\n",&a,&b);
		g[a][b]=true;
		g[b][a]=true;
	}
	for (int i=1;i<=n;i++) {
		for (int j=1;j<i;j++) {
			for (int k=1;k<j;k++) {
				if ((g[i][j]) && (g[j][k]) && (g[k][i]))
				{
					printf("%d %d %d\n",k,j,i);
				}
			}
		}
	}
	return 0;
}
