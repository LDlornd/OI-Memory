#include<cstdio>
#include<iostream>
#include<bitset>
using namespace std;
const int MAXN=105;
int n,m,u,v,q,l;
bitset<MAXN> dp[MAXN][32];
bitset<MAXN> now,nex;
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
		dp[u][0][v]=1;
	}
	for(int i=1;i<32;++i)
		for(int j=1;j<=n;++j)
			for(int k=1;k<=n;++k)
				if(dp[j][i-1][k]) dp[j][i]=dp[j][i]|dp[k][i-1];
	q=read();
	while(q--){
		l=read();u=read();v=read();
		now.reset();now[u]=1;
		for(int w=0;(1ll<<w)<=l;++w){
			if((l&(1<<w))==0) continue;
			nex.reset();
			for(int i=1;i<=n;++i)
				if(now[i]) nex=nex|dp[i][w];
			now=nex;
		}
		if(now[v]) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
