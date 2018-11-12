#include<cmath>
#include<cstdio>
#include<iostream>
using namespace std;
int n,x,p,ans;
int gcd(int a,int b){
	if(a<b) swap(a,b);
	if(b==0) return a;
	else return gcd(b,a%b);
}
int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read();x=read();p=read();
	ans=abs(x-p);
	while(--n){
		p=read();
		ans=gcd(ans,abs(x-p));
	}
	printf("%d",ans);
	return 0;
}
