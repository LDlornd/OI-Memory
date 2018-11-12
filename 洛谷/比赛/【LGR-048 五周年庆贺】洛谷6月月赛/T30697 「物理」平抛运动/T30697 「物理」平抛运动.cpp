#include<cmath>
#include<cstdio>
#include<iostream>
using namespace std;
const double pi=3.1415926535;
const int g=10;
double v,sita,vx,vy,t,ansx,ansy;
int main(){
	scanf("%lf%lf",&v,&sita);
	vx=v*sin(sita);
	vy=v*cos(sita);
	t=vy/g;
	ansx=vx*t;
	ansy=0.5*g*t*t;
	printf("%.5lf %.5lf",ansx,ansy);
	//printf("%.5lf",cos(pi/2));
}
