#include<cstdio>
#include<iostream>
using namespace std;
typedef long long int ll;
inline ll quickmi(ll base,ll index,int mod){
	int temp=1;
	base%=mod;
	while(index>1){
		cout<<temp<<" "<<base<<" "<<index<<endl;
		if(index&1) (temp*=base)%=mod;
		index>>=1;
		(base*=base)%=mod;
	}
	return (temp*=base)%=mod;
}
int main(){
	int a,b,c;
	while(scanf("%d%d%d",&a,&b,&c)!=EOF)
		cout<<quickmi(a,b,c)<<endl;
		return 0;
}
