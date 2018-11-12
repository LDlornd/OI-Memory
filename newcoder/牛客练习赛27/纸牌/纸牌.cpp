#include<cstdio>
#include<iostream>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	if(n&1) n=(n>>1)+1;
	else n>>=1;
	printf("%d",n);
	return 0;
};
