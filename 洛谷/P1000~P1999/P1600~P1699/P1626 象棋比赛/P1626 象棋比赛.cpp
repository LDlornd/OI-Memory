#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int a[100000],cha[100000];
int CMP(int a,int b)
{
	return a<b;
}
int main()
{
	int n,k,sum=0;
	cin>>n>>k;
	for(int i=0;i<n;++i)
		cin>>a[i];
	sort(a,a+n,CMP);
	for(int i=0;i<n-1;++i)
		cha[i]=a[i+1]-a[i];
	sort(cha,cha+n-1,CMP);
	for(int i=0;i<k;++i)
		sum+=cha[i];
	cout<<sum; 
}
