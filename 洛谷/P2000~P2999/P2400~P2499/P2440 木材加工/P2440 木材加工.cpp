#include<cstdio>
#include<iostream>
using namespace std;
int a[100000];
int n,k,sum=0,ans=0;
bool judge(int x)
{
	int flag=0;
	for(int i=0;i<n;++i)
		flag+=a[i]/x;
	if(flag>=k) return true;
	else return false;
}
int main()
{
	cin>>n>>k;
	for(int i=0;i<n;++i)
	{
		cin>>a[i];
		sum+=a[i];
	}
	sum/=k;
	int left=1,right=sum;
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
