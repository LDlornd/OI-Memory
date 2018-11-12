#include<ctime>
#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN=105;
int n,m=0,q,u,v,l;
bool flag[MAXN][MAXN];
int main(){
	freopen("cave.in","w",stdout);
	srand(time(0));
	n=rand()%5+1;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(i==j) continue;
			flag[i][j]=rand()&1;
			if(flag[i][j]) ++m;
		}
	}
	cout<<n<<" "<<m<<endl;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if(flag[i][j]) cout<<i<<" "<<j<<endl;
	q=rand()%10+1;
	cout<<q<<endl;
	while(q--){
		u=rand()%n+1;v=rand()%n+1;l=rand()%1000+1;
		cout<<l<<" "<<u<<" "<<v<<endl;
	}
	return 0;
}
