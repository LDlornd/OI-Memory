#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m,a[1000000],flag[1000000][21];
int search(int l,int r)
{
	int k=0;
	while(1<<(k+1)<=r-l+1) ++k;
	return min(flag[l][k],flag[r-(1<<k)+1][k]);
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;++i)
		{scanf("%d",&a[i]);flag[i][0]=a[i];}
	for(int	j=1;j<=20;++j)
		for(int i=0;i+(1<<j)<=n;++i)
			flag[i][j]=min(flag[i][j-1],flag[i+(1<<(j-1))][j-1]);
	for(int i=0;i<n-m+1;++i)
		cout<<search(i,i+m-1)<<endl;
	return 0;
}
