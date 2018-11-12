#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int a[20000];
int CMP(int a,int b)
{
	return a>b;
}
int main()
{
	int n,b,num=0;
	cin>>n>>b;
	for(int i=0;i<n;++i)
		cin>>a[i];
	sort(a,a+n,CMP);
	while(b>0)
	{
		b-=a[num];
		++num;
	}
	cout<<num;
	return 0;
}
