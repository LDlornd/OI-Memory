#include<cstdio>
#include<iostream>
using namespace std;
typedef long long int ll;
const int MAXN=100001;
ll ans=0;
int n,key;
int arr[MAXN],num[21];
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		key=read();
		for(int j=0;(1<<j)<=key;++j)
			if(key&(1<<j)) ++num[j];
	}
	while(true){
		bool flag=true;
		ll temp=0;
		for(int i=0;i<21;++i){
			if(num[i]){
				--num[i];
				temp+=(1<<i);
				if(num[i]) flag=false;
			}
		}
		ans+=(temp*temp);
		if(flag) break;
	}	
	printf("%lld",ans);
	return 0;
}
