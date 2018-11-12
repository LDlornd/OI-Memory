#include<cstdio>
#include<iostream>
using namespace std;
long long int n,a,b,now=1;
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>a>>b;
	if(a+b>(n+1)||a*b<n) cout<<"-1";
	else{
		long long int k=n-a+1;
		for(int i=k;i<=n;++i){
			cout<<i<<" ";
			for(int j=now+b-2;j>=now;--j){
				if(j>=k) j=k-1;
				if(j<now) break;
				cout<<j<<" ";
			}
			now=now+b-1;
		}
	}
	return 0;
}
