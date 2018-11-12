#include<cstdio>
#include<iostream>
using namespace std;
int n,k,ans=0,now;
int main(){
	scanf("%d%d",&n,&k);
	now=1;
	for(now=1;now<n;now+=k){
		++ans;--now;
	}
	printf("%d",ans);
	return 0;
}
