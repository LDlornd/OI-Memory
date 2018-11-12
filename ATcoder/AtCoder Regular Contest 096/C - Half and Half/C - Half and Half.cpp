#include<cstdio>
#include<iostream>
using namespace std;
int main(){
	int a,b,c,x,y,ans;
	scanf("%d%d%d%d%d",&a,&b,&c,&x,&y);
	if(x<=y){
		if(a+b>=2*c) ans=2*c*x+min(b,2*c)*(y-x);
		else ans=a*x+b*y;
	}
	else if(x>y){
		if(a+b>=2*c) ans=2*c*y+min(a,2*c)*(x-y);
		else ans=a*x+b*y;
	}
	printf("%d",ans);
	return 0;
}
