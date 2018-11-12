#include<cstdio>
#include<iostream>
using namespace std;
int a[50000];
int len=0,sum=0;
int main()
{
	int n,k;
	cin>>n;
	for(int i=0;i<n;++i)
	{
		cin>>k;
		sum+=k;
		sum%=7;
		a[i]=sum;
	}
	for(int i=0;i<n;++i)
	{
		for(int j=i+len;j<n;++j)
		{
			if(a[j]==a[i]) len=j-i;
		}
	}
	cout<<len;
	return 0;
}
