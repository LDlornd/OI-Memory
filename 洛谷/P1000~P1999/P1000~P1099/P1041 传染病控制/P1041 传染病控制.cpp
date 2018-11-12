#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=305;
int n,p,u,v;
int dp[MAXN],sum[MAXN],maxson[MAXN];
struct edge{
	int v;
	edge *nex;
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
		sum[nv]+=dp[p->v];maxson[nv]=max(maxson[nv],dp[p->v]);
	}
	if(sum[nv]==0) {dp[nv]=sum[nv]=maxson[nv]=1;}
	else dp[nv]=sum[nv]-maxson[nv]+1;
}
int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read();p=read();
	while(p--){
		u=read();v=read();
		ins(u,v);ins(v,u);
	}
	get_dp(1,0);
	printf("%d",dp[1]);
	return 0;
}
