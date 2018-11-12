#include<cstdio>
#include<iostream>
using namespace std;
typedef long long int ll;
ll n,a,ans;
int main(){
	scanf("%lld",&n);ans=-n;
	while(n--){
		scanf("%lld",&a);
		ans+=a;
	}
	printf("%lld",ans);
	return 0;
}
