#include<cstdio>
#include<iostream>
using namespace std;
typedef long long int ll;
int n,s;
ll s,v,val[MAXN];
ll quick_mi(ll base,ll index){
	ll temp=0;
	while(index){
		if(index) temp=temp*base;
		base*=base;
		index>>=1;
		if(temp>s||temp<0) return 0;
	}
	return temp;
}
template<typename T>
T read(){
	T x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	s=read<int>();n=read<int>();
	while(n--){
		
	}
}
