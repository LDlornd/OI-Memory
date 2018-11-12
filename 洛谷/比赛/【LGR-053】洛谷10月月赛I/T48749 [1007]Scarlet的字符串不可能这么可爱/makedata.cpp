#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
typedef long long int ll;
int main(){
	freopen("testdata.in","w",stdout);
	srand(time(0));
	ll k=rand()%5+1,l=rand()%10+1,mod=1e9+7;
	int s=rand()%l+1,w=rand()%k+1;
	cout<<k<<" "<<l<<" "<<mod<<endl<<s<<" "<<w;
	return 0;
}
