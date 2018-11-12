#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=205;
int n,m,u,v,ans=0;
int mp[MAXN][6];
bool stop[MAXN][5];
void dfs(int nx,int ny,int points){
	
}
int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=5;++j)
			mp[i][j]=read();
	m=read();
	while(m--)
		stop[u=read()][y=read()]=true;
	dfs(1,3,0);
}
