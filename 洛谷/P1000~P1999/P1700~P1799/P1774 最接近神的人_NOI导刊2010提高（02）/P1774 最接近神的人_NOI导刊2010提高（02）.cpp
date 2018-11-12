#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=500001;
int a[MAXN],temp[MAXN];
int n;
long long int ans=0;
inline void Merge(int start1,int end1,int start2,int end2)
{
	int p1=start1,p2=start2,p=start1;
	while(p1<=end1&&p2<=end2)
	{
		if(a[p1]<=a[p2]) temp[p++]=a[p1++];
		else
		{
			ans+=(end1-p1+1);
			temp[p++]=a[p2++];
		}
	}
	while(p1<=end1) temp[p++]=a[p1++];
	while(p2<=end2) temp[p++]=a[p2++];
	for(int i=start1;i<=end2;++i) a[i]=temp[i];
}
inline void merge_sort(int start,int end)
{
	if(start>=end) return;
	int mid=(start+end)>>1;
	merge_sort(start,mid);
	merge_sort(mid+1,end);
	Merge(start,mid,mid+1,end);
}
inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
	return x*f;
}
int main()
{
	n=read();
	for(int i=1;i<=n;++i)
		a[i]=read();
	merge_sort(1,n);
	printf("%lld",ans);
	return 0;
}
