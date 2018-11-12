#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
struct num
{
	string s;
	int len;
};
num k[20];
int CMP(const num &a,const num &b)
{
	string i=a.s+b.s,j=b.s+a.s;
	if(i<=j) return 0;
	else return 1;
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;++i)
	{
		cin>>k[i].s;
		k[i].len=k[i].s.length();
	}
	sort(k,k+n,CMP);
	for(int i=0;i<n;++i)
		cout<<k[i].s;
	return 0;
}
