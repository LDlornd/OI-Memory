#include<cstdio>
#include<iostream>
using namespace std;
typedef long long int ll;
const int MAXN=2001;
const int mod=998244353;
ll ans=0;
int n,num1=0,num2=0;
int jc[MAXN];
int du[MAXN];
inline ll get_peidui(int key){
	ll tempans=1;
	for(int i=1;i<=key;i+=2)
		{tempans*=i;tempans%=mod;}
	return tempans;
}
inline ll get_huan(int key){
	ll tempans=1;
	for(int i=1;i<=key-2;++i)
		{tempans*=i;tempans%=mod;}
	return tempans;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;jc[0]=1;
	for(int i=1;i<=n;++i){
		cin>>du[i];
		if(du[i]==1) ++num1;
		else ++num2;
		jc[i]=jc[i-1]*i%mod;
	}
	if(n==0) cout<<0;
	else if(num2==0) cout<<get_peidui(n);
	else if(num1==0) cout<<get_huan(n);
	return 0;
}
