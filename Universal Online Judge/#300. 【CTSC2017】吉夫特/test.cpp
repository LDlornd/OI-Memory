#include<cstdio>
#include<iostream>
#include<bitset>
using namespace std;
int main(){
	bitset<10> s;
	cin>>s;
	cout<<s<<endl;
	int a=(int)s.to_ulong(),b;
	for(b=(a-1)&a;b!=0;b=(b-1)&a){
		s=b;
		cout<<s<<endl£» 
	}
	return 0;
}
