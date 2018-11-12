#include<cstdio>
#include<iostream>
using namespace std;
double a,b,c,d;
int p1=101,p2=101,p3=101;
inline double f(double t)
{
	return a*t*t*t+b*t*t+c*t+d;
}
double Search(int k)
{
	if(f(k)==0) return k;
	if(f(k+1)==0) return k+1;
	double l=k,r=k+1;
	if(f(l)>0) swap(l,r);
	while(r-l>1e-4||l-r>1e-4)
	{
		double mid=(l+r)/2;
		double flag=f(mid);
		if(flag==0) return mid;
		if(flag>0) r=mid;
		if(flag<0) l=mid;
	}
	return l;
}
int main()
{
	scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
	for(int i=-100;i<100;++i)
	{
		if(f(i)*f(i+1)<=0)
		{
			if(p1!=101)
				if(p2!=101) {p3=i;break;}
				else p2=i;
			else p1=i;
		}
		if(f(i+1)==0) ++i;
	}
	printf("%.2lf %.2lf %.2lf",Search(p1),Search(p2),Search(p3));
	return 0;
}
