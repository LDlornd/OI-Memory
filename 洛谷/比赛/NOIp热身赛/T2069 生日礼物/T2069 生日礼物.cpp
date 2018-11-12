#include<cmath>
#include<cstdio>
#include<iostream>
using namespace std;
typedef long long int ll;
int gcd(int a,int b){
	if(a<b) swap(a,b);
	if(b==0) return a;
	else return gcd(b,a%b);
}
int main(){
	int n;
	ll ans=0;
	scanf("%d",&n);
	for(ll i=1;i<=n;++i)
		for(ll j=1;j<=n;++j)
			if(i*j/gcd(i,j)==n) ++ans;
	//if((int)sqrt(n)==sqrt(n)) --ans;
	printf("%lld",ans);
	return 0;
}
