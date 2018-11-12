#include<cstdio>
#include<iostream>
using namespace std;
int a,b,c,m,n,k;
int gcd(int x,int y){
	if(y==0) return x;
	else return gcd(y,x%y);
}
int main(){
	scanf("%d%d%d",&a,&b,&c);
	m=max(a,max(b,c));
	n=min(a,min(a,b));
	k=gcd(m,n);
	printf("%d/%d",n/k,m/k);
	return 0;
}
