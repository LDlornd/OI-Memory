#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=55;
int n,sum1=0,sc;
double sum2=0,gpa;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%lf%d",&gpa,&sc);
		sum1+=sc;sum2+=gpa*sc;
	}
	printf("%.1lf",sum2/sum1);
	return 0;
}
