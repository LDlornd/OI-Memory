#include<cstdio>
#include<iostream>
using namespace std;
int main(){
	int a,b,ans=0;
	scanf("%d",&a);
	while(a--){
		scanf("%d",&b);
		while(!(b&1)){
			b>>=1;
			++ans;
		}
	}
	printf("%d",ans);
	return 0;
}
