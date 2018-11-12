#include<cstdio>
#include<iostream>
using namespace std;
int T,a,b;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&a,&b);
		int temp;
		if(a>b){
			if(b==0) printf("%d\n",a);
			else pritnf("%d\n",a-3*b);
		}
		else{
			if(a==0) printf("%d\n",-b);
			else printf("%d",);
		}
	}
	return 0;
}
