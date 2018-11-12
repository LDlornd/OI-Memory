#include<cstdio>
#include<iostream>
using namespace std;
int main(){
	int a,b,c,tot=0;
	scanf("%d%d%d",&a,&b,&c);
	if(a<b) swap(a,b);
	if(a<c) swap(a,c);
	if(b<c) swap(b,c);
	//cout<<a<<" "<<b<<" "<<c<<endl;
	if((a-b)%2==1&&(a-c)%2==1) tot=(a-b)/2+(a-c)/2+1;
	else if((a-b)%2==0&&(a-c)%2==0) tot=(a-b)/2+(a-c)/2;
	else tot=(a-b)/2+(a-c)/2+2;
	printf("%d",tot);
	return 0;
}
