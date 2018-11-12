#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=15;
int n,sum;
int ans[MAXN];
int C[MAXN][MAXN];
bool vis[MAXN];
bool dfs(int now,int cnt){
	if(now==n+1){
		if(cnt==sum) return true;
		else return false;
	}
	for(int i=1;i<=n;++i){
		if(vis[i]) continue;
		int tmp=cnt+C[n-1][now-1]*i;
		if(tmp>sum||(tmp==sum&&now!=n)) break;
		vis[i]=true;ans[now]=i;
		if(dfs(now+1,tmp)) return true;
		vis[i]=false;
	}
	return false;
}
void init(){
	for(int i=0;i<MAXN;++i)
		for(int j=0;j<=i;++j)
			if(j==0||j==i) C[i][j]=1;
			else C[i][j]=C[i-1][j]+C[i-1][j-1];
}
int main(){
	init();
	scanf("%d%d",&n,&sum);
	if(dfs(1,0)){
		for(int i=1;i<=n;++i)
			printf("%d ",ans[i]);
	}
	return 0;
}
