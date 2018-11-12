#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int MAXN=101;
int height[MAXN];
int ansup[MAXN],ansdown[MAXN],best[MAXN];
inline int search_up(int nlen,int k)
{
	int l=1,r=nlen+1,tempans;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(best[mid]>=k||best[mid]==0)
		{
			tempans=mid;
			r=mid;
		}
		else l=mid+1;
	}
	if(best[l]>=k||best[l]==0) tempans=l;
	return tempans;
}
int main()
{
	int n,len=0,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&height[i]);
	memset(best,0,sizeof(best));
	for(int i=1;i<=n;++i)
	{
		int place=search_up(len,height[i]);
		best[place]=height[i];
		ansup[i]=place;
		if(place>len) ++len;
	}
	memset(best,0,sizeof(best));
	len=0;
	for(int i=n;i>=1;--i)
	{
		int place=search_up(len,height[i]);
		best[place]=height[i];
		ansdown[i]=place;
		if(place>len) ++len;
	}
	for(int i=1;i<=n;++i)
		if(ans<ansup[i]+ansdown[i]-1) ans=ansup[i]+ansdown[i]-1;
	printf("%d",n-ans);
	return 0;
}
