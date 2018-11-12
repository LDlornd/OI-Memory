#include<cmath>
#include<cstdio>
#include<iostream>
using namespace std;
double n,l,r,x[11],y[11];
inline double getdist(double sx,double sy,double ex,double ey){
	return sqrt((ex-sx)*(ex-sx)+(ey-sy)*(ey-sy));
}
inline bool judge(double xx,double yy){
	for(int i=1;i<=n;++i){
		if(getdist(xx,yy,x[i],y[i])<=r) return false;
	}
	return true;
}
int main(){
	scanf("%lf%lf",&n,&l);
	r=l/n;
	for(int i=1;i<=n;++i)
		scanf("%lf%lf",&x[i],&y[i]);
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j){
			double nx=(x[i]+x[j])/2,ny=(y[i]+y[j])/2;
			if(judge(nx,ny)){
				printf("%.3lf %.3lf",nx,ny);
				return 0;
			}
		}
	if(judge(0,0)){printf("0.000 0.000");return 0;}
	if(judge(0,l)){printf("0.000 %.3lf",l);return 0;}
	if(judge(l,0)){printf("%.3lf 0.000",l);return 0;}
	if(judge(l,l)){printf("%.3lf %.3lf",l,l);return 0;}
	printf("GG");
	return 0;
}
