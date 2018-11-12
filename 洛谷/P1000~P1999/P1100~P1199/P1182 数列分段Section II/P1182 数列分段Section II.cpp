#include<cstdio>
#include<iostream>
using namespace std;
int n,m,ans,sum=0;
int a[100000];
bool judge(int x)
{
	int s=0,tot=1;
	for(int i=0;i<n;++i)
	{
		s+=a[i];
		if(s>x) {++tot;s=0;--i;}
		if(tot>m) return false;
	}
	return true;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i)
		{scanf("%d",&a[i]);sum+=a[i];}
	int l=1,r=sum;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(judge(mid))
		{
			ans=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	if(judge(l)) ans=l;
	printf("%d",ans);
	return 0;
}
