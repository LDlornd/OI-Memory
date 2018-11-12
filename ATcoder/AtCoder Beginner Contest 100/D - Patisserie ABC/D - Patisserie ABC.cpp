#include<cmath>
#include<cstdio>
#include<iostream>
using namespace std;
typedef long long int ll;
const int MAXN=1001;
int n,m;
struct node{
	ll x,y,z;
	node() {x=y=z=0;}
}arr[MAXN],dp[MAXN][MAXN],ans;
inline ll getans(node a){
	return abs(a.x)+abs(a.y)+abs(a.z);
}
inline node MAX(node a,node b){
	return (getans(a)>getans(b))?a:b;
}
inline node sum(node a,node b){
	a.x+=b.x;a.y+=b.y;a.z+=b.z;
	return a;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%lld%lld%lld",&arr[i].x,&arr[i].y,&arr[i].z);
	dp[1][1]=arr[1];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=i&&j<=m;++j)
			for(int k=j-1;k<i;++k)
				dp[i][j]=MAX(dp[i][j],sum(dp[k][j-1],arr[i]));
	for(int i=m;i<=n;++i)
		ans=MAX(ans,dp[i][m]);
	printf("%lld",getans(ans));
	return 0;
}
