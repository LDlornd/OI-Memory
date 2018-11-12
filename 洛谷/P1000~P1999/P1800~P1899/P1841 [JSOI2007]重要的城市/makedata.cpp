#include<ctime>
#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN=205;
bool flag[MAXN][MAXN];
int main(){
	freopen("city.in","w",stdout);
	srand(time(0));
	int n=rand()%50+1,m=0;
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			flag[i][j]=rand()%2;
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			if(flag[i][j]) ++m;
		}
	}
	cout<<n<<" "<<m<<endl;
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			if(flag[i][j]) cout<<i<<" "<<j<<" "<<1<<endl;
		}
	}
	return 0;
}
