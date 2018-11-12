#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
int n,len,ans=0;
int arr[MAXN],cparr[MAXN];
int change[MAXN],sum[MAXN];
bool judge(int key){
	for(int i=1;i<=n;++i){
		if(arr[i]<key) change[i]=-1;
		if(arr[i]==key) change[i]=0;
		if(arr[i]>key) change[i]=1;
		sum[i]=sum[i-1]+change[i];
	}
	int minsum=0;
	for(int i=len;i<=n;++i){
		minsum=min(minsum,sum[i-len]);
		if(sum[i]>=minsum) return true;
	}
	return false;
}
int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read();len=read();
	for(int i=1;i<=n;++i) cparr[i]=arr[i]=read();
	sort(cparr+1,cparr+n+1);
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(judge(cparr[mid])) {ans=mid;l=mid+1;}
		else r=mid-1;
	}
	printf("%d",cparr[ans]);
	return 0;
}
