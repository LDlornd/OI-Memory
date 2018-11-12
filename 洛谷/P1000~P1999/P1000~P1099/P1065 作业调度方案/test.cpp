#include<cstdio>
#include<iostream>
#include<bitset>
using namespace std;
int main(){
	int n;
	bitset<20> a;
	cin>>n;
	a=n;
	for(int i=1;i<=10;++i){
		cout<<a<<endl;
		for(int j=0;j<20;++j) cout<<a[j];cout<<endl;
		a<<=1;
	}
}
