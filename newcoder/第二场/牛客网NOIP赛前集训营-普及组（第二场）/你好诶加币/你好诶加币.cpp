#include<cstdio>
#include<iostream>
using namespace std;
typedef long long int ll;
ll a,b,c;
int main(){
	scanf("%lld%lld",&a,&b);
	c=a+b;
	if((a<0&&b<0&&c>=0)||(a>0&&b>0&&c<=0)) printf("\"hello, %%lld\\n\"");
	else printf("%lld",c);
	return 0;
}
