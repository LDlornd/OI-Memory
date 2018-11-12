#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=100001;
long long int ans=0;
int n,k;
int arr[MAXN],sum[MAXN],temp[MAXN];
inline void Merge(int pstart,int pend,int qstart,int qend){
	int p=pstart,q=qstart,place=pstart;
	while(p<=pend&&q<=qend){
		if(sum[p]<sum[q]){
			temp[place++]=sum[p++];
		}
		else{
			ans+=(pend-p+1);
			temp[place++]=sum[q++];
		}
	}
	while(p<=pend) temp[place++]=sum[p++];
	while(q<=qend) temp[place++]=sum[q++];
	for(int i=pstart;i<=qend;++i) sum[i]=temp[i];
}
inline void merge_sort(int Start,int End){
	if(Start==End) return;
	int mid=(Start+End)>>1;
	merge_sort(Start,mid);
	merge_sort(mid+1,End);
	Merge(Start,mid,mid+1,End);
}
int main(){
	ios::sync_with_stdio(false);
	sum[0]=0;
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>arr[i];
		sum[i]=sum[i-1]+arr[i]-k;
	}
	for(int i=1,j=n;i<j;++i,--j) swap(sum[i],sum[j]);
	merge_sort(1,n);
	for(int i=1;i<=n;++i) if(sum[i]>=0) ++ans;
	cout<<ans;
	return 0;
}
