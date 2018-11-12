#include<cstdio>
#include<iostream>
#include<map>
# define lld I64d
using namespace std;
typedef long long int ll;
int T,sum=0;
ll l,r,ans;
ll dp[20][50][2520];
int num[20],tot;
map<int,int> mp;
int gcd(int a,int b){
	if(a<b) swap(a,b);
	if(b==0) return a;
	else return gcd(b,a%b);
}
int Lcm(int a,int b){
	return a*b/gcd(a,b);
}
ll getdp(int now,int lcm,int remainder,bool limit){
	if(now==0) return remainder%lcm==0;
	if(limit==false&&dp[now][mp[lcm]][remainder]) return dp[now][mp[lcm]][remainder];
	ll temp=0;
	int up=limit?num[now]:9;
	for(int i=0;i<=up;++i){
		if(i==0) temp+=getdp(now-1,lcm,remainder,limit&(i==num[now]));
		else temp+=getdp(now-1,Lcm(lcm,i),(remainder*10+i)%2050,limit&(i==num[now]));
	}
	if(limit==false) dp[now][mp[lcm]][remainder]=temp;
	return temp;
}
ll solve(ll key){
	tot=0;
	while(key) {num[++tot]=key%10;key/=10;}
	return getdp(tot,1,0,true);
}
void getready(){
	for(int i=1;i<=2520;++i)
		if(2520%i==0) mp.insert(make_pair(i,++sum));
}
int main(){
	getready();
	scanf("%d",&T);
	while(T--){
		scanf("%lld%lld",&l,&r);
		printf("%lld\n",solve(r)-solve(l-1));
	}
	return 0;
}#include<cstdio>
#include<iostream>
#include<map>
# define lld I64d
using namespace std;
typedef long long int ll;
int T,sum=0;
ll l,r,ans;
ll dp[20][50][2520];
int num[20],tot;
map<int,int> mp;
int gcd(int a,int b){
	if(a<b) swap(a,b);
	if(b==0) return a;
	else return gcd(b,a%b);
}
int Lcm(int a,int b){
	return a*b/gcd(a,b);
}
ll getdp(int now,int lcm,int remainder,bool limit){
	if(now==0) return remainder%lcm==0;
	if(limit==false&&dp[now][mp[lcm]][remainder]) return dp[now][mp[lcm]][remainder];
	ll temp=0;
	int up=limit?num[now]:9;
	for(int i=0;i<=up;++i){
		if(i==0) temp+=getdp(now-1,lcm,remainder,limit&(i==num[now]));
		else temp+=getdp(now-1,Lcm(lcm,i),(remainder*10+i)%2050,limit&(i==num[now]));
	}
	if(limit==false) dp[now][mp[lcm]][remainder]=temp;
	return temp;
}
ll solve(ll key){
	tot=0;
	while(key) {num[++tot]=key%10;key/=10;}
	return getdp(tot,1,0,true);
}
void getready(){
	for(int i=1;i<=2520;++i)
		if(2520%i==0) mp.insert(make_pair(i,++sum));
}
int main(){
	getready();
	scanf("%d",&T);
	while(T--){
		scanf("%lld%lld",&l,&r);
		printf("%lld\n",solve(r)-solve(l-1));
	}
	return 0;
}
