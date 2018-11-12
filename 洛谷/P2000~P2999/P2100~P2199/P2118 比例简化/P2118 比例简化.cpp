#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	double a,b,l,t,ans=1000,ansa,ansb;
	cin>>a>>b>>l;
	t=a/b;
	for(double i=1;i<=l;i+=1)
	{
		for(double j=1;j<=l;j+=1)
		{
			double k=i/j;
			if(k==t) {cout<<i<<" "<<j;return 0;}
			if(k<t) continue;
			if(ans>k-t) {ans=k-t;ansa=i;ansb=j;}
		}
	}
	cout<<ansa<<" "<<ansb;
	return 0;
}
