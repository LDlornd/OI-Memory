#include<cstdio>
#include<iostream>
#include<map>
using namespace std;
typedef long long int ll;
ll L,R,l,r;
int cnt,num[20];
map<ll,ll> dp[20];
ll getdp(int now,ll sum,bool limit){
	if(now==0) return sum>=l&&sum<=r;
	if(limit==false&&dp[now].count(sum)) return dp[now][sum];
	ll temp=0;
	for(int i=0;i<=(limit?num[now]:9);++i){
		if(sum==-1){
			if(i==0) temp+=getdp(now-1,-1,limit&&(i==num[now]));
			else temp+=getdp(now-1,i,limit&&(i==num[now]));
		}
		else temp+=getdp(now-1,sum*i,limit&&(i==num[now]));
	}
	if(limit==false) dp[now].insert(make_pair(sum,temp));
	return temp;
}
ll caculate(ll key){
	for(int i=0;i<20;++i) dp[i].clear();
	cnt=0;
	if(key==-1) return 0;
	while(key) {num[++cnt]=key%10;key/=10;}
	return getdp(cnt,-1,true)+(L==0&&l==0);
}
int main(){
	scanf("%lld%lld%lld%lld",&L,&R,&l,&r);
	printf("%lld",caculate(R)-caculate(L-1));
	return 0;
}
