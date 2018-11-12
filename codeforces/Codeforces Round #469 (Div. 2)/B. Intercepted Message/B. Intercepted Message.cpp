#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=1e5+1;
int m,n,placea=1,placeb=1,ans=0;
long long int A[MAXN],B[MAXN];
long long int suma=0,sumb=0;
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>A[i];
	for(int i=1;i<=m;++i) cin>>B[i];
	while(placea<=n){
		suma+=A[placea];
		while(sumb<suma) sumb+=B[placeb++];
		if(suma==sumb) {++ans;suma=sumb=0;}
		++placea;
	}
	cout<<ans;
	return 0;
}
