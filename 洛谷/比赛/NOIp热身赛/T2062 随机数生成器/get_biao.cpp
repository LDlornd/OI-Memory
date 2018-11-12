#include<cstdio>
#include<iostream>
using namespace std;
typedef long long int ll;
const int val=10000000;
int n;
double E[100000];
double sum,k;
int main(){
	//scanf("%d",&n);
	//sum=E[n/val];
	//freopen("test.in","w",stdout);
	sum=0;
	for(int i=1;i<=2147483647;++i){
		if(i!=1) k=(sum+(ll)i)/(i-1);
		else k=0;
		sum+=k;
		if(i%10000000==0) printf("%.10lf,",k);
	}
	//printf("%.5lf",k);
	return 0;
}
