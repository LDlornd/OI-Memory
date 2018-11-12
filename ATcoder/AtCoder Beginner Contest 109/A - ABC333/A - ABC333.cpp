#include<cstdio>
#include<iostream>
using namespace std;
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	if(a&1&&b&1) printf("Yes");
	else printf("No");
	return 0;
}
