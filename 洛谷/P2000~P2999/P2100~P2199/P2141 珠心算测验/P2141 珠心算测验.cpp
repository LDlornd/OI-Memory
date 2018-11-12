#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
bool flag[10001];
int cmp(int a,int b)
{
	return a<b;
}
int main()
{
	memset(flag,0,sizeof(flag));
	int n,num=0;
	cin>>n;
	int a[n];
	for(int i=0;i<n;++i)
	{
		cin>>a[i];
		flag[a[i]]=1;
	}
	sort(a,a+n,cmp);
	for(int i=2;i<n;++i)
	{
		double k=a[i]/2.0;
		for(int j=0;a[j]<k;++j)
		{
			if(flag[a[i]-a[j]]) {++num;break;}
		}
	}
	cout<<num;
	return 0;
}
