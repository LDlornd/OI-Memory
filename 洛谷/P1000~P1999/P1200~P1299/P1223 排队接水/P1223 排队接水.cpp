#include<cstdio>
#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
struct water
{
	int w,num;
};
water a[1000];
int CMP(const water &a,const water &b)
{
	return a.w<b.w;
}
int main()
{
	int n;
	double ans=0;
	cin>>n;
	for(int i=0;i<n;++i)
		{cin>>a[i].w;a[i].num=i+1;}
	sort(a,a+n,CMP);
	for(int i=0;i<n;++i)
	{
		cout<<a[i].num<<" ";
		ans+=(a[i].w*(n-1-i));
	}
	ans/=n;
	cout<<endl<<fixed<<setprecision(2)<<ans;
	return 0;
}
