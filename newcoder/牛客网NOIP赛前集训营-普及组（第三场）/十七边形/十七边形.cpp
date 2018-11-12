#include<cmath>
#include<cstdio>
#include<iostream>
using namespace std;
const double pi=3.1415926535897932;
double r;
int main(){
	scanf("%lf",&r);
	printf("%.6lf",r*r*sin(2*pi/17)/2*17);
	return 0;
}
