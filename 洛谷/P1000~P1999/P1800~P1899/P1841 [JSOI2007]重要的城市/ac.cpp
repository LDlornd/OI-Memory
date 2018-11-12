#include<cstdio>
#include<cstring>
#include<iostream>
#include<bitset>
using namespace std;
const int INF=1e9+7;
const int MAXN=205;
int n,m,u,v,l;
int dist[MAXN][MAXN];
bitset<MAXN> flag[MAXN][MAXN];
bool ans[MAXN],output=false;
void init(){
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			dist[i][j]=(i==j)?0:INF;
}
int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read();m=read();
	init();
	while(m--){
		u=read();v=read();l=read();
		dist[u][v]=dist[v][u]=l;
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j){
			flag[i][j][i]=flag[i][j][j]=1;
			flag[j][i][i]=flag[j][i][j]=1;
		}
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j){
				if(dist[i][j]==dist[i][k]+dist[k][j]) flag[i][j]=flag[i][j]&(flag[i][k]|flag[k][j]);
				else if(dist[i][j]>dist[i][k]+dist[k][j]){
					dist[i][j]=dist[i][k]+dist[k][j];
					flag[i][j]=flag[i][k]|flag[k][j];
				}
			}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			for(int k=1;k<=n;++k)
				if(k!=i&&k!=j&&flag[i][j][k]) ans[k]=true;
	for(int i=1;i<=n;++i)
		if(ans[i]){
			output=true;
			printf("%d ",i);
		}
	if(output==false) printf("No important cities.");
	return 0;
}
