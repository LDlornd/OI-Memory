#include<cstdio>
#include<iostream>
using namespace std;
int n,k;
long long int ans=0;
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=k+1;i<=n;++i){
		int shang=n/i,yushu=n%i;
		ans+=((i-k)*shang+max(0,yushu+1-k));
		}
	if(k==0) ans-=n;
	cout<<ans;
	return 0;
}
