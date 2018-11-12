#include<cmath>
#include<cstdio>
#include<iostream>
using namespace std;
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	int c=b-a;
	c=(c*(c+1))>>1;
	printf("%d",c-b);
	return 0; 
}
