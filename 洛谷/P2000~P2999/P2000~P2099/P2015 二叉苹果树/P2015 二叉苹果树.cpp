#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN=105;
int n,q,u,v,k;
int arr[MAXN];
int dp[MAXN][MAXN];
struct edge{
	int v,val;
	edge *nex;
	edge() {v=val=0;nex=NULL;}
}*con[MAXN];
void ins(int Start,int End,int key){
	edge *p=new(edge);
	p->v=End;p->val=key;
	p->nex=con[Start];con[Start]=p;
}
int get_dp(int nv,int father){
	int cnt=1;
	for(edge *p=con[nv];p;p=p->nex){
		if(p->v==father) continue;
		cnt+=get_dp(p->v,nv);
		for(int i=cnt;i>=1;--i)
			for(int j=0;j<i;++j)
				dp[nv][i]=max(dp[nv][i],dp[nv][i-j-1]+dp[p->v][j]+p->val);
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
	n=read();q=read();
	for(int i=1;i<n;++i){
		u=read();v=read();k=read();
		ins(u,v,k);ins(v,u,k);
	}
	get_dp(1,0);
	printf("%d",dp[1][q]);
	return 0;
}
