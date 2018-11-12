#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int RAND(){
	int temp=rand()*rand()*rand()*rand();
	if(temp<0) temp*=-1;
	return temp;
}
int main(){
	freopen("trans.in","w",stdout);
	srand(time(0));
	for(int key=1;key<=10;++key){
		int n=RAND()%100000+1,k=RAND()%1000000+1;
		cout<<n<<" "<<k<<endl;
		for(int i=1;i<=n;++i) cout<<rand()%4+1;
		cout<<endl;
	}
	return 0;
}
