#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
const int INF=1e9+7;
const int MAXN=3005;
int n,m,k,A,C,ans=0;
int money[MAXN];
int dp[MAXN][MAXN];
bool vis[MAXN];
struct edge{
	int v,val;
	edge *nex;
	edge() {v=0;nex=NULL;}
}*con[MAXN],*tree[MAXN];
void ins(int Start,int End,int key,edge *a[]){
	edge *p=new(edge);
	p->v=End;p->val=key;
	p->nex=a[Start];a[Start]=p;
}
void get_tree(int nv,int father){
	for(edge *p=con[nv];p;p=p->nex){
		if(p->v==father) continue;
		ins(nv,p->v,p->val,tree);
		get_tree(p->v,nv);
	}
}
int get_dp(int nv){
	if(nv>=n-m+1){
		dp[nv][1]=money[nv];
		return 1;
	}
	int sum=0;
	for(edge *p=tree[nv];p;p=p->nex){
		sum+=get_dp(p->v);
		for(int i=sum;i>=1;--i){
			for(int j=0;j<=i;++j)
				dp[nv][i]=max(dp[nv][i],dp[nv][i-j]+dp[p->v][j]-p->val);
		}
	}
	return sum;
}
void init(){
	for(int i=1;i<=n;++i) dp[i][0]=0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			dp[i][j]=-INF;
}
int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read();m=read();
	init();
	for(int i=1;i<=(n-m);++i){
		k=read();
		while(k--){
			A=read();C=read();
			ins(i,A,C,con);ins(A,i,C,con);
		}
	}
	for(int i=n-m+1;i<=n;++i) money[i]=read();
	get_tree(1,0);
	get_dp(1);
	for(int i=m;i>=0;--i){
		if(dp[1][i]>=0){
			printf("%d",i);
			break;
		}
	}
	return 0;
}
