#include<cstdio>
#include<iostream>
using namespace std;
typedef long long int ll;
ll a;
bool judge(ll key){
	for(ll i=2;i*i<=key;++i)
		if(key%i==0) return true;
	return false;
}
int main(){
	scanf("%lld",&a);
	while(judge(a)) --a;
	printf("%lld",a);
	return 0;
}
