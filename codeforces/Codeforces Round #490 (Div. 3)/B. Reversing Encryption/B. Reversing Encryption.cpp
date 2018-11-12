#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
int main(){
	int n;
	string s;
	cin>>n>>s;
	for(int w=1;w<=n;++w)
		if(n%w==0)
			for(int i=0,j=w-1;i<j;++i,--j)
				swap(s[i],s[j]);
	cout<<s;
	return 0;
}
