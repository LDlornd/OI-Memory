#include<cmath>
#include<cstdio>
#include<iostream>
using namespace std;
typedef long long int ll;
const int MAXN=2e5+1;
int n,cut1,cut2,cut3;
ll ans,arr[MAXN],presum[MAXN];
inline ll getsum(int Start,int End){
	if(Start>End) return 0;
	return presum[End]-presum[Start-1];
}
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read();
	for(int i=1;i<=n;++i) presum[i]=presum[i-1]+(arr[i]=read());
	ans=presum[n];cut1=1;cut3=3;
	for(cut2=3;cut2<=n-1;++cut2){
		while(getsum(1,cut1-1)<=getsum(cut1,cut2-1)) ++cut1;
		while(getsum(cut2,cut3-1)<=getsum(cut3,n)) ++cut3; // only god and i kown what this is 
		while(getsum(1,cut1-1)>getsum(cut1,cut2-1)) --cut1; 
		while(getsum(cut2,cut3-1)>getsum(cut3,n)) --cut3;
		if(cut1==cut2) --cut1;if(cut1<=1) cut1=2;
		if(cut3>n) cut3=n;if(cut3<=cut2) cut3=cut2+1;
		ll P=getsum(1,cut1-1),Q=getsum(cut1,cut2-1),R=getsum(cut2,cut3-1),S=getsum(cut3,n);
		if(abs(getsum(1,cut1)-getsum(cut1+1,cut2-1))<abs(P-Q)) {P=getsum(1,cut1);Q=getsum(cut1+1,cut2-1);}
		if(abs(getsum(cut2,cut3)-getsum(cut3+1,n))<abs(R-S)) {R=getsum(cut2,cut3);S=getsum(cut3+1,n);}
		ans=min(ans,max(max(P,Q),max(R,S))-min(min(P,Q),min(R,S)));//now only god knows
	}
	printf("%lld",ans);
	return 0;
}
