#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	int l,r,m,sum=0;
	cin>>l>>r;
	for(int i=l;i<=r;++i)
	{
		m=i;
		while(m!=0)
		{
			if(m%10==2) ++sum;
			m/=10;
		}
	}
	cout<<sum;
	return 0;
}
