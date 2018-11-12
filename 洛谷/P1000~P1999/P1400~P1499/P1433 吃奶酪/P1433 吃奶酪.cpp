#include<cmath>
#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=20;
int n;
double ans=2147483647;
double x[MAXN],y[MAXN],dist[MAXN][MAXN];
bool vis[MAXN];
void dfs(int sum,int now,double cnt){
	if(sum==n) {ans=min(ans,cnt);return;}
	for(int i=1;i<=n;++i){
		if(vis[i]||cnt+dist[now][i]>ans) continue;
		vis[i]=true;
		dfs(sum+1,i,cnt+dist[now][i]);
		vis[i]=false;
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%lf%lf",&x[i],&y[i]);
		for(int j=0;j<i;++j){
			dist[i][j]=dist[j][i]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
		}
	}
	dfs(0,0,0);
	printf("%.2lf",ans);
	return 0;
}
