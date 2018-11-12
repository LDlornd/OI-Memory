#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
int a[10000];
bool flag[100000];
int main()
{
	memset(flag,0,sizeof(flag));
	int n;
	cin>>n;
	for(int i=0;i<n;++i)
	{
		cin>>a[i];
		if(i!=0) flag[abs(a[i]-a[i-1])]=true;
	}
	for(int i=1;i<n;++i)
		if(!flag[i]) {cout<<"Not jolly";return 0;}
	cout<<"Jolly";
	return 0;
}
