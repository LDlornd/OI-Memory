#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int flag[201];
bool judge=false;
int cmp(int a,int b)
{
	return a>b;
}
int main()
{
	memset(flag,0,sizeof(flag));
	int n,w,i;
	cin>>w>>n;
	int a[n];
	for(i=0;i<n;++i)
	{
		cin>>a[i];
		++flag[a[i]];
	}
	sort(a,a+n,cmp);
	for(i=0;i<n;++i)
	{
		if(flag[a[i]]==0) continue;
		int k=w-a[i];
		for(int j=n-1;j>i;--j)
		{
			if(k-a[j]<0) break;
			k-=a[j];
			--n;
		}
	}
	cout<<i;
	return 0;
}
