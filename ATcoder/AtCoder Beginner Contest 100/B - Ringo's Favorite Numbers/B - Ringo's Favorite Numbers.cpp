#include<cstdio>
#include<iostream>
using namespace std;
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	if(b==100) ++b;
	printf("%d",b);
	while(a--){
		printf("00");
	}
	return 0;
}
