#include<cstdio>
#include<iostream>
using namespace std;
typedef long long int ll;
const int MAXN=100001;
int a[MAXN],sum[MAXN],temp[MAXN];
ll ans=0;
inline void Merge(int Left,int Mid,int Right)
{
	int p1=Left,p2=Mid+1,p=Left;
	while(p1<=Mid&&p2<=Right)
	{
		if(sum[p1]<=sum[p2])
		{
			ans+=(Right-p2+1);
			temp[p++]=sum[p1++];
		}
		else temp[p++]=sum[p2++];
	}
	while(p1<=Mid) temp[p++]=sum[p1++];
	while(p2<=Right) temp[p++]=sum[p2++];
	for(int i=Left;i<=Right;++i)
		sum[i]=temp[i];
}
inline void merge_sort(int start,int end)
{
	if(start>=end) return;
	int mid=(start+end)>>1;
	merge_sort(start,mid);
	merge_sort(mid+1,end);
	Merge(start,mid,end);
}
inline int read()
{
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
	return x;
}
int main()
{
	int n=read(),k=read();
	sum[0]=0;
	for(int i=1;i<=n;++i)
	{
		a[i]=read()-k;
		sum[i]=sum[i-1]+a[i];
	}
	merge_sort(1,n);
	for(int i=n;i>=1&&sum[i]>=0;--i)
		++ans;
	printf("%lld",ans);
	return 0;
}
