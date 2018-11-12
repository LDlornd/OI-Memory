#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
const double g=10;
const double judge=0.0001; 
int main(){
	double h,s,v,l,k,n;
	scanf("%lf%lf%lf%lf%lf%lf",&h,&s,&v,&l,&k,&n);
	double t=sqrt(2*(h-k)/g);
	double tail=s+l-v*t+judge;
	t=sqrt(2*h/g);
	double head=s-v*t-judge;
	int Start=head,End=tail;
	if(head!=Start) ++Start;
	printf("%d",max(0,min((int)n-1,End)-max(0,Start)+1));
	return 0;
}
