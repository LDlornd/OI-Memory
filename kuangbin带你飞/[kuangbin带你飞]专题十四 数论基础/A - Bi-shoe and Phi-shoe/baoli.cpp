#include<cstdio>
#include<iostream>
using namespace std;
int gcd(int a,int b){
	if(b==0) return a;
	else return gcd(b,a%b);
}
int f(int key){
	int temp=0;
	for(int i=1;i<key;++i)
		if(gcd(key,i)==1) ++temp;
	return temp;
}
int main(){
	freopen("testdata.in","r",stdin);
	freopen("TLE.out","w",stdout);
	for(int i=1;i<=10000;++i)
		cout<<i<<" "<<f(i)<<endl;
	return 0;
}
