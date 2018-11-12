#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
char s[4]={'Q','A','P','C'};
int main(){
	freopen("testdata.in","w",stdout);
	srand(time(0));
	int n=rand()%10+1;
	cout<<n<<endl;
	for(int i=1;i<=n;++i) cout<<rand()%100<<" ";cout<<endl;
	int m=rand()%10;
	cout<<m<<endl;
	while(m--){
		int opt=rand()%4,x=rand()%n+1,y=rand()%n+1,z=rand()%100;
		if(x>y) swap(x,y);
		cout<<s[opt]<<" "<<x<<" "<<y;
		if(opt>1) cout<<" "<<z;
		cout<<endl;
	}
	return 0;
}
