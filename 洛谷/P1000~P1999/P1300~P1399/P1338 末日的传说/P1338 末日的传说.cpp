#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=15;
int n,ans;
int arr[MAXN],a[MAXN],temp[MAXN],num[MAXN*MAXN];
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
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) arr[i]=i;
	for(int i=1;i<=n;++i) cout<<arr[i]<<" ";cout<<0<<endl;
	while(next_permutation(arr+1,arr+n+1)){
		for(int i=1;i<=n;++i) a[i]=arr[i];ans=0;
		merge_sort(1,n);
		++num[ans];
	}
	for(int i=1;i<=10;++i){
		cout<<num[i]<<" ";
	}
}
