#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int a[200000];
int CMP(int a,int b)
{
	return a<b;
}
int main()
{
	memset(a,0,sizeof(a));
	int n,k=-1,ans=1;
	cin>>n;
	for(int i=0;i<n;++i)
		cin>>a[i];
	sort(a,a+n,CMP);
	for(int i=0;i<n;++i)
	{
		if(k==-1) {k=a[i];continue;}
		if(k!=a[i]) {cout<<k<<" "<<ans<<endl;ans=1;k=a[i];continue;}
		++ans;
	}
	cout<<k<<" "<<ans;
	return 0;
}
