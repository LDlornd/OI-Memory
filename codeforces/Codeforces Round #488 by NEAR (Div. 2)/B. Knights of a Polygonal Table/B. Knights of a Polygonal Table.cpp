#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long int ll;
const int MAXN=1e5+1;
int m,n;
ll ans[MAXN];
ll Queue[MAXN],tail,now;
struct knight{
	int power,id;
	ll coin;
	knight() {power=coin=id=0;}
}arr[MAXN];
inline bool CMP(const knight &a,const knight &b){
	return a.power<b.power;
}
template<typename T>
inline T read(){
	T x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read<int>();m=read<int>();
	for(int i=1;i<=n;++i)
		{arr[i].power=read<int>();arr[i].id=i;}
	for(int i=1;i<=n;++i)
		arr[i].coin=read<ll>();
	sort(arr+1,arr+n+1,CMP);
	tail=now=0;
	for(int i=1;i<=n;++i){
		ll temp=0;
		for(int j=1;j<=tail;++j) temp+=Queue[j];
		ans[arr[i].id]=arr[i].coin+temp;
		Queue[now=++tail]=arr[i].coin;
		while(now>1&&Queue[now]>Queue[now-1]){
			swap(Queue[now],Queue[now-1]);
			--now;
		}
		if(tail>m) --tail;
	}
	for(int i=1;i<=n;++i)
		printf("%I64d ",ans[i]);
	return 0;
}
