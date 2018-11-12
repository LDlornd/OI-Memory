#include <cstdio>

#include <cmath>

#include <algorithm>

#include <cstring>

#include <queue> 


#include <time.h>

using namespace std; 

double pr[1201][1201];
int bl[1201][1201];
int ty[100001];
int main()
{
	srand((unsigned)time(NULL));
	freopen("counting0.in","w",stdout);
	int n=200;
	int l=400;
	printf("%d\n",n);
	for (int i=1;i<=l;i++)
	{
		for (int j=1;j<=20;j++)
		{
			int a=0,b=0;
			while ((a==b) || (bl[b][a]>0))
			{
				a=rand()%(n-1)+2;
				b=rand()%(a-1)+1;
			 }
			 bl[b][a]=i;
			 pr[b][a]=0.05;
			 
		}
		ty[i]=rand()%2+2;
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<i;j++)
		{
			if (bl[j][i]==0) 
			{
				double p=double(rand()% 10)/10;
				printf("%d %d %d %.2lf\n",i,j,1,p);
			} else
			{
				printf("%d %d %d %.2lf %d\n",i,j,ty[bl[j][i]],pr[j][i],bl[j][i]);
			}
		}
		
	return 0;
}
