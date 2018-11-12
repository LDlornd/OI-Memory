#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	int m,n,k,sum=0,ans=1;
	cin>>n>>m;
	for(int i=0;i<n;++i)
	{
		cin>>k;
		sum+=k;
		if(sum>m) {sum=k;++ans;}
	}
	cout<<ans;
	return 0;
}
