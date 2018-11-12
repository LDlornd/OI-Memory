#include<cmath>
#include<cstdio>
#include<iostream>
using namespace std;
typedef long long int ll;
ll l,r;
ll dp[11][10];
int num[11],tot;
ll getdp(int digit,int now,bool limit,bool flag){
	if(digit==0) return 1;
	if(limit==false&&flag&&dp[digit][now]) return dp[digit][now];
	ll temp=0;
	int up=limit?num[digit]:9;
	for(int i=0;i<=up;++i)
		if(flag||abs(now-i)>=2) temp+=getdp(digit-1,i,limit&&(i==up),flag&&(i==0));
	if(limit==false&&flag) dp[digit][now]=temp;
	return temp;
}
ll solve(ll key){
	tot=0;
	while(key) {num[++tot]=key%10;key/=10;}
	return getdp(tot,0,true,true);
}
int main(){
	scanf("%lld%lld",&l,&r);
	printf("%lld",solve(r)-solve(l-1));
	return 0;
} 
