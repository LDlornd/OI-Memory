#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN=16005;
int n,u,v,ans=-2147483647;
int arr[MAXN],dp[MAXN];
struct edge{
	int v;
	edge *nex;
	edge() {v=0;nex=NULL;}
}*con[MAXN],*tree[MAXN];
void ins(int Start,int End,edge *a[]){
	edge *p=new(edge);
	p->v=End;
	p->nex=a[Start];a[Start]=p;
}
void get_tree(int nv,int father){
	for(edge *p=con[nv];p;p=p->nex){
		if(p->v==father) continue;
		ins(nv,p->v,tree);
		get_tree(p->v,nv);
	}
}
void get_dp(int nv){
	dp[nv]=arr[nv];
	for(edge *p=tree[nv];p;p=p->nex){
		get_dp(p->v);
		dp[nv]=max(dp[nv],dp[nv]+dp[p->v]);
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
	for(int i=1;i<=n;++i) arr[i]=read();
	for(int i=1;i<n;++i){
		u=read();v=read();
		ins(u,v,con);ins(v,u,con);
	}
	get_tree(1,0);
	get_dp(1);
	for(int i=1;i<=n;++i) ans=max(ans,dp[i]);
	printf("%d",ans);
	return 0;
}
