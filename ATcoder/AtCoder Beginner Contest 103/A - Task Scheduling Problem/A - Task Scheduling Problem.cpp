#include<cstdio>
#include<iostream>
using namespace std;
int main(){
	int a,b,c,ans;
	scanf("%d%d%d",&a,&b,&c);
	if(a>b) swap(a,b);
	if(a>c) swap(a,c);
	if(b>c) swap(b,c);
	printf("%d\n",c-a);
	return 0;
}
