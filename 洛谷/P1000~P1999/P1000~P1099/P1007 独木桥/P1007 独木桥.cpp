#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
int a[10000]; 
int main()
{
	int l,n,k,lon=0,sho=0;
	cin>>l>>n;
	for(int i=0;i<n;++i)
		cin>>a[i];
	for(int i=0;i<n;++i)
	{
		int k=a[i]-0,t=l+1-a[i];
		lon=max(lon,max(k,t));
		sho=max(sho,min(k,t));
	}
	cout<<sho<<" "<<lon;
	return 0;
}
