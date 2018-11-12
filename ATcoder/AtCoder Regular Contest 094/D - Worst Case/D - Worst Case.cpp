#include<cmath>
#include<cstdio>
#include<iostream>
using namespace std;
int main(){
	int T;
	long long int a,b;
	scanf("%d",&T);
	while(T--){
		scanf("%lld%lld",&a,&b);
		if(a>b) swap(a,b);
		if(a==b) printf("%lld\n",2*a-2);
		else if(a+1==b) printf("%lld\n",2*a-2);
		else{
			long long int c=sqrt(a*b);
			if(c*c==a*b) --c;
			if(c*(c+1)>=a*b) printf("%lld\n",2*c-2);
			else printf("%lld\n",2*c-1);
		}
	}
	return 0;
}
