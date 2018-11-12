#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long int ll;
const int MAXN=100001;
int n;
double ans=0;
ll arr[MAXN],sum[MAXN];
inline ll getsum(int Start,int End){
	return sum[End]-sum[Start-1];
}
inline bool CMP(int a,int b){
	return a<b;
}
template<typename T>
inline T read(){
	T x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read<int>();
	for(int i=1;i<=n;++i) arr[i]=read<ll>();
	sort(arr+1,arr+n,CMP);
	for(int i=1;i<=n;++i) sum[i]=sum[i-1]+arr[i];
	for(int i=3;i<=n;++i){
		int mintemp=i/2+1,maxtemp=i-mintemp;
		double pjs=(double)(getsum(1,mintemp)+(getsum(n-maxtemp+1,n)))/i,zws;
		if(i&1) zws=arr[mintemp];
		else zws=(double)(arr[mintemp]+arr[mintemp-1])/2;
		//cout<<mintemp<<" "<<maxtemp<<" "<<pjs<<" "<<zws<<endl;
		ans=max(ans,pjs-zws);
	}
	printf("%.2lf",ans);
	return 0;
}
