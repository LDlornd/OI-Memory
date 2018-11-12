#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=40001;
int a[MAXN],temp[MAXN],ans=0;
inline void Merge(int Left,int middle,int Right)
{
	int p1=Left,p2=middle+1,p=Left;
	while(p1<=middle&&p2<=Right)
		if(a[p1]>a[p2])
		{
			temp[p++]=a[p2++];
			ans+=(middle-p1+1);
		}
		else temp[p++]=a[p1++];
	while(p1<=middle) temp[p++]=a[p1++];
	while(p2<=Right) temp[p++]=a[p2++];
	for(int i=Left;i<=Right;++i) a[i]=temp[i];
}
inline void merge_sort(int start,int end)
{
	if(start>=end) return;
	int mid=(start+end)>>1;
	merge_sort(start,mid);
	merge_sort(mid+1,end);
	Merge(start,mid,end);
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	merge_sort(1,n);
	printf("%d",ans);
	return 0;
}
