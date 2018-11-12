#include<cstdio>
#include<iostream>
#include<bitset>
using namespace std;
const int MAXN=25;
int n,m,cnt,ans=0;
int order[MAXN*MAXN];
int use[MAXN][MAXN],cost[MAXN][MAXN];
int now[MAXN],End[MAXN][MAXN];
bitset<8000> machine[MAXN],nex,judge;
int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	m=read();n=read();cnt=n*m;
	for(int i=1;i<=cnt;++i) order[i]=read();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			use[i][j]=read();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			cost[i][j]=read();
	for(int i=1;i<=n;++i) now[i]=1;
	judge.reset();
	for(int i=1;i<=cnt;++i){
		int tmp=order[i];
		nex.reset();
		for(int j=1;j<=cost[tmp][now[tmp]];++j) nex[j+End[tmp][now[tmp]-1]]=1;
		for(int j=End[tmp][now[tmp]-1]+1;j<8000;++j){
			if((machine[use[tmp][now[tmp]]]&nex)==judge){
				machine[use[tmp][now[tmp]]]|=nex;
				End[tmp][now[tmp]]=j-1+cost[tmp][now[tmp]];
				break;
			}
			nex<<=1;
		}
		++now[tmp];
	}
	for(int i=1;i<=m;++i){
		for(int j=7999;j>=0;--j){
			if(machine[i][j]==1){
				ans=max(ans,j);
				break;
			}
		}
	}
	printf("%d",ans);
	return 0;
}
