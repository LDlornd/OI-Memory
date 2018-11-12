#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN=305;
int n,m,fa;
int arr[MAXN],dp[MAXN][MAXN];
struct edge{
	int v;
	edge *nex;
	edge() {v=0;nex=NULL;}
}*con[MAXN];
void ins(int Start,int End){
	edge *p=new(edge);
	p->v=End;
	p->nex=con[Start];con[Start]=p;
}
int get_dp(int nv){
	dp[nv][1]=arr[nv];
	int cnt=1;
	for(edge *p=con[nv];p;p=p->nex){
		cnt+=get_dp(p->v);
		for(int i=cnt;i>=1;--i){
			for(int k=0;k<i;++k)
				dp[nv][i]=max(dp[nv][i],dp[nv][i-k]+dp[p->v][k]);
		}
	}
	return cnt;
}
int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read();m=read()+1;
	for(int i=1;i<=n;++i){
		fa=read();arr[i]=read();
		ins(fa,i);
	}
	get_dp(0);
	printf("%d",dp[0][m]);
	return 0;
}
