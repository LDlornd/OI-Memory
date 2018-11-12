#include<cmath>
#include<cstdio>
#include<iostream>
using namespace std;
char num[21]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K'};
int ans[100];
int n,base,cnt=0;
int main(){ 
	scanf("%d%d",&n,&base);
	printf("%d=",n);
	while(n){
		int m=n%base;
		if(m<0){
			m+=abs(base);
			n-=m;
		}
		ans[++cnt]=m;
		n/=base;
	}
	for(int i=cnt;i;--i) printf("%c",num[ans[i]]);
	printf("(base%d)",base);
	return 0;
}
