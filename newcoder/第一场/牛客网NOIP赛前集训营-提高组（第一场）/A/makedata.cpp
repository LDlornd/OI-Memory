#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main(){
	freopen("testdata.in","w",stdout);
	srand(time(0));
	int n=1e5;
	cout<<n<<" "<<rand()%n+1<<endl;
	for(int i=1;i<=n;++i) cout<<rand()<<" ";
	return 0;
}
