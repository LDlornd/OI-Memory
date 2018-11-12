#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
inline long long int RAND(long long int key){
	long long int temp=1;
	while(temp<key) temp+=rand()*rand();
	return temp;
}
int main(){
	srand(time(0));
	freopen("RP10.in","w",stdout);
	int T=10;
	cout<<T<<endl;
	cout<<RAND(10000000)<<endl;
	cout<<RAND(25000000)<<endl;
	cout<<RAND(30000000)<<endl;
	cout<<RAND(59000000)<<endl;
	cout<<RAND(75000000)<<endl;
	cout<<RAND(90000000)<<endl;
	cout<<RAND(100000000)<<endl;
	cout<<RAND(200000000)<<endl;
	cout<<RAND(500000000)<<endl;
	cout<<RAND(100000000)<<endl;
	return 0;
}
