#include<cstdio>
#include<cstring>
#include<iostream>
#include<bitset>
using namespace std;
const int MAXN=15;
int n,m;
int ctrl[105][MAXN];
int dp[1<<MAXN];
int Queue[1<<MAXN],head,tail;
bitset<MAXN> now,nex;
void bfs(int Start){
	Queue[head=tail=1]=Start;
	dp[Start]=0;
	while(head<=tail){
		int nv=Queue[head++];
		now=nv;
		for(int i=1;i<=m;++i){
			for(int j=0;j<n;++j){
				if(ctrl[i][j+1]==1&&now[j]==1) nex[j]=0;
				else if(ctrl[i][j+1]==-1&&now[j]==0) nex[j]=1;
				else nex[j]=now[j];
			}
			int to=nex.to_ulong();
			if(dp[to]==-1){
				dp[to]=dp[nv]+1;
				if(to==0) break;
				else Queue[++tail]=to;
			}
		}
	}
}
int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	memset(dp,-1,sizeof(dp));
	n=read();m=read();
	for(int i=1;i<=m;++i)
		for(int j=1;j<=n;++j)
			ctrl[i][j]=read();
	bfs((1<<n)-1);
	printf("%d",dp[0]);
	return 0;
}
