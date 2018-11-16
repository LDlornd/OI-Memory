#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=1e5+5;
int n,m,l,r;
int arr[MAXN],LG[MAXN];
int dp[MAXN][20];
void init(){
	LG[1]=0;
	for(int i=2;i<=n;++i) LG[i]=LG[i>>1]+1;
	for(int i=1;i<=n;++i) dp[i][0]=arr[i];
	for(int w=1;w<=LG[n];++w)
		for(int i=1;i+(1<<w)-1<=n;++i)
			dp[i][w]=max(dp[i][w-1],dp[i+(1<<(w-1))][w-1]);
}
int query(int Left,int Right){
	int tmp=LG[Right-Left+1];
	return max(dp[Left][tmp],dp[Right-(1<<tmp)+1][tmp]);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) scanf("%d",&arr[i]);
	init();
	while(m--){
		scanf("%d%d",&l,&r);
		printf("%d\n",query(l,r));
	}
	return 0;
}
