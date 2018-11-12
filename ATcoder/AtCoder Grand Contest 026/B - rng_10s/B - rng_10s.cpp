#include<cstdio>
#include<iostream>
using namespace std;
typedef long long int ll;
int T;
ll a,b,c,d,temp;
int main(){
	freopen("testdata.in","r",stdin);
	scanf("%d",&T);
	while(T--){
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		if(a<b) {printf("No\n");continue;}
		a%=b;temp=d-b;
		if(a>c||temp<0) {printf("No\n");continue;}
		if(temp==0) {printf("Yes\n");continue;}
		bool flag=true;
		for(int i=1;i<=100000;++i){
			a=a+(c-a)/temp*temp+temp;
			if(a<b) {flag=false;break;}
			a%=b;
		}
		if(flag) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
