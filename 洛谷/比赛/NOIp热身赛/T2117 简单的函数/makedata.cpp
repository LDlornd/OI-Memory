#include<ctime>
#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
int main(){
	freopen("test.in","w",stdout);
	srand(time(0));
	cout<<rand()%10000+2;
	return 0;
}
