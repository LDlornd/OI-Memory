#include<cstdio>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
typedef long long int ll;
const int MAXN=2e5+1;
int n,ans=1;
ll ans1,ans2,ans3,temp1,temp2,temp3;
ll arr[MAXN];
map<ll,bool> mp;
inline bool CMP(ll a,ll b){
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
	for(int i=1;i<=n;++i){
		arr[i]=read<ll>();
		if(mp.count(arr[i])==false) mp.insert(make_pair(arr[i],true));
	}
	sort(arr+1,arr+n+1,CMP);
	for(int k=30;k>=0;--k){
		for(int i=1;arr[i]+((ll)1<<k)<=arr[n];++i){
			if(ans==3) break;
			temp1=arr[i];temp2=arr[i]+((ll)1<<k);temp3=arr[i]+((ll)1<<(k+1));
			if(ans==2)
				if(mp.count(temp2)&&mp.count(temp3)) {ans=3;ans1=temp1;ans2=temp2;ans3=temp3;}
				else continue;
			if(ans==1){
				if(mp.count(temp2)) {ans=2;ans1=temp1;ans2=temp2;}
				if(mp.count(temp3)) {ans=2;ans1=temp1;ans3=temp3;}
			}
		}
	}
	if(ans==1) ans1=arr[1];
	printf("%d\n%lld",ans,ans1);
	if(ans>1) printf(" %lld",ans2);
	if(ans>2) printf(" %lld",ans3);
	return 0;
}
