#include<ctime>
#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
int main(){
	freopen("merge.in","w",stdout);
	srand(time(0));
	int n=rand()%10+1;;
	cout<<n<<endl;
	while(n--) cout<<rand()%10+1<<" ";
	return 0;
}
