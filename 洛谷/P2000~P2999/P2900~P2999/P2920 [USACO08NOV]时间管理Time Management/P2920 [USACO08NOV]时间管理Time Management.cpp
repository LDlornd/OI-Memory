#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
struct Time
{
	int t,s;
};
Time a[1000];
int n,ans=-1;
int CMP(const Time &a,const Time &b)
{
	return a.s<b.s;
}
bool judge(int x)
{
	int i=0;
	while(i<n)
	{
		x+=a[i].t;
		if(x>a[i].s) return false;
		++i;
	}
	return true;
}
int main()
{
	cin>>n;
	for(int i=0;i<n;++i)
		cin>>a[i].t>>a[i].s;
	sort(a,a+n,CMP);
	int left=0,right=a[n-1].s;
	while(left<right)
	{
		int mid=(left+right)>>1;
		if(judge(mid))
		{
			ans=mid;
			left=mid+1;
		}
		else right=mid;
	}
	if(left==right&&judge(left)) ans=left;
	cout<<ans;
	return 0;
}
