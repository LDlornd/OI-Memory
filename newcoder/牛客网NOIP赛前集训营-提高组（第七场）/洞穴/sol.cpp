#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int MAXN=105;
int n,m,u,v,q,l;
bool dp[MAXN][32][MAXN];
bool now[MAXN],nex[MAXN];
int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read();m=read();
	while(m--){
		u=read();v=read();
		dp[u][0][v]=true;
	}
	for(int i=1;i<32;++i)
		for(int j=1;j<=n;++j)
			for(int k=1;k<=n;++k)
				for(int to=1;to<=n;++to)
					dp[j][i][to]=dp[j][i][to]|(dp[j][i-1][k]&&dp[k][i-1][to]);
	q=read();
	while(q--){
		l=read();u=read();v=read();
		memset(now,0,sizeof(now));
		now[u]=true;
		for(int w=0;(1ll<<w)<=l;++w){
			if((l&(1<<w))==0) continue;
			memset(nex,0,sizeof(nex));
			for(int i=1;i<=n;++i){
				if(now[i]){
					for(int j=1;j<=n;++j)
						nex[j]=nex[j]|dp[i][w][j];
				}
			}
			for(int i=1;i<=n;++i) now[i]=nex[i];
		}
		if(now[v]) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
