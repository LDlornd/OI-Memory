#include<cstdio>
#include<iostream>
using namespace std;
int main(){
	long long int n,k,sum=0;
	scanf("%lld",&n);
	while(n--){
		scanf("%lld",&k);
		sum+=k;
	}
	if(sum&1) printf("Alice");
	else printf("Bob");
	return 0;
}
