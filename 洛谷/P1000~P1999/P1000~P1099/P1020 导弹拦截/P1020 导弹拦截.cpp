#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int MAXN=100001;
const int INF=2147483647;
int height[MAXN];
int best[MAXN];
int n,num=0,no_uplen=0,downlen=0;
inline int search_noup(int nlen,int k)
{
	int l=1,r=nlen+1,tempans=0;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(best[mid]<k) 
		{
			tempans=mid;
			r=mid;
		}
		else l=mid+1;
	}
	if(best[l]<k) tempans=l;
	return tempans;
}
inline int search_down(int nlen,int k)
{
	int l=1,r=nlen+1,tempans=0;
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
	memset(best,0,sizeof(best));
	while(scanf("%d",&n)!=EOF)
		height[++num]=n;
	for(int i=1;i<=num;++i)
	{
		int temp=search_noup(no_uplen,height[i]);
		best[temp]=height[i];
		if(temp>no_uplen) ++no_uplen;
	}
	memset(best,0,sizeof(best));
	for(int i=1;i<=num;++i)
	{
		int temp=search_down(downlen,height[i]);
		best[temp]=height[i];
		if(temp>downlen) ++downlen;
	}
	printf("%d\n%d",no_uplen,downlen);
	return 0;
}
