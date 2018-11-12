#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int a[10000];
int CMP(int a,int b)
{
	return a<b;
}
int main()
{
	memset(a,0,sizeof(0));
	int n,sum=0;
	bool flag=false;
	cin>>n;
	for(int i=0;i<n;++i)
		cin>>a[i];
	sort(a,a+n,CMP);
	for(int i=1;i<n;++i)
	{
		if(flag) {++i;flag=false;}
		a[i]+=a[i-1];
		sum+=a[i];
		for(int j=i+1;j<n;++j)
		{
			if(a[j]>a[j-1]) break;
			swap(a[j],a[j-1]); 
		}
	}
	cout<<sum;
	return 0;
}
