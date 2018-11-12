#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
typedef long long int ll;
ll mod=1000000000;
ll RAND(ll key){
	return (rand()*rand()%mod)*(rand()*rand()%mod)*(rand()*rand()%mod)%mod;
}
int main(){
	freopen("testdata.in","w",stdout);
	srand(time(0));
	ll l=RAND(mod),r=RAND(mod);while(l<0) l=RAND(mod);while(l>r) r=RAND(mod);
	mod=100;
	ll L=RAND(mod),R=RAND(mod);while(L<0) L=RAND(mod);while(L>R) R=RAND(mod);
	cout<<l<<" "<<r<<" "<<L<<" "<<R;
	return 0;
}
