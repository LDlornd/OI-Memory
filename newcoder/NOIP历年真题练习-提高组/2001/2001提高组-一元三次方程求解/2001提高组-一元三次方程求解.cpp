#include<cmath>
#include<cstdio>
#include<iostream>
using namespace std;
double a,b,c,d,delta,p1,p2,ans1,ans2,ans3;
double f(double x){
	return a*x*x*x+b*x*x+c*x+d;
}
double Search(double Left,double Right){
	if(f(Left)==0) return Left;
	if(f(Right)==0) return Right;
	double mid;
	while(Right-Left>=0.0001){
		mid=(Left+Right)/2;
		if(f(mid)==0) break;
		double fl=f(Left),fm=f(mid),fr=f(Right);
		if(fm*fl>0) Left=mid;
		if(fm*fr>0) Right=mid;
	}
	return mid;
}
int main(){
	scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
	delta=4*b*b-4*3*a*c;
	p1=(-2*b-sqrt(delta))/(6*a);
	p2=(-2*b+sqrt(delta))/(6*a);
	ans1=Search(-100,p1);
	ans2=Search(p1,p2);
	ans3=Search(p2,100);
	printf("%.2lf %.2lf %.2lf",ans1,ans2,ans3);
}
