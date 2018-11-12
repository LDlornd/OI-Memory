#include<cstdio>
#include<iostream>
using namespace std;
int a[30][30];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			scanf("%d",&a[i][j]);
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			if(i==0||j==0||a[i][j]==1) continue;
			int sum=0;
			if(a[i-1][j]!=0) ++sum;
			if(a[i][j-1]!=0) ++sum;
			for(int k=(i+1);k<n;++k)
				if(a[k][j]==1) {++sum;break;}
			for(int k=(j+1);k<n;++k)
				if(a[i][k]==1) {++sum;break;}
			if(sum==4) a[i][j]=2;
		}
	}
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			if(j==0) printf("%d",a[i][j]);
			else printf(" %d",a[i][j]);
		}
		printf("\n");
	} 
	 
	return 0;
}
