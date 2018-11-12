#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN=1505;
int n,id,cnt,to;
int dp[2][MAXN];
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
void get_dp(int nv,int father){
	for(edge *p=con[nv];p;p=p->nex){
		if(p->v==father) continue;
		get_dp(p->v,nv);
		dp[0][nv]+=dp[1][p->v];
		dp[1][nv]+=min(dp[1][p->v],dp[0][p->v]);
	}
}
int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		id=read()+1;cnt=read();
		dp[1][id]=1;dp[0][id]=0;
		while(cnt--){
			to=read()+1;
			ins(id,to);ins(to,id);
		}
	}
	get_dp(1,0);
	printf("%d",min(dp[0][1],dp[1][1]));
	return 0;
}
