#include <cstdio>

#include <cmath>

#include <algorithm>

#include <cstring>

#include <queue> 


#include <time.h>

using namespace std; 

int main()
{
	srand((unsigned)time(NULL));
	freopen("defile10.in","w",stdout);
	int n=100;
	int k=1;
	printf("%d %d\n",n,k);
	for (int i=1;i<=n;i++)
	{
		int j=(rand()*rand()) % 90+1;
		printf("%d ",j);
	}
	printf("\n");
	return 0;
}

