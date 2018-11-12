#include<cstdio>
#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	long long int m,n,ans;
	cin>>m>>n;
	if(m>1&&n>1) ans=(m-2)*(n-2);
	else if(m==1&&n==1) ans=1;
	else ans=max(m,n)-2;
	cout<<ans;
	return 0;
}
