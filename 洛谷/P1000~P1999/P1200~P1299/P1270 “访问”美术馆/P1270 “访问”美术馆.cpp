#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN=1000;
int limit,n=1,ignore;
int arr[MAXN];
int dp[MAXN][MAXN];
struct edge{
	int v,len;
	edge *nex;
	edge() {v=len=0;nex=NULL;}
}*con[MAXN];
void ins(int Start,int End,int key){
	edge *p=new(edge);
	p->v=End;p->len=key;
	p->nex=con[Start];con[Start]=p;
}
void get_dp(int nv,int father){
	if(arr[nv]!=0){
		for(int i=5;i<=limit;++i) dp[nv][i]=min(arr[nv],dp[nv][i-5]+1);
		return;
	}
	for(edge *p=con[nv];p;p=p->nex){
		if(p->v==father) continue;
		get_dp(p->v,nv);
		for(int i=limit;i>=p->len;--i){
			for(int j=0;j+p->len<=i;++j){
				dp[nv][i]=max(dp[nv][i],dp[nv][j]+dp[p->v][i-j-p->len]);
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
void get_tree(int nv,int father){
	int len=read(),temp=read();
	ins(father,nv,len<<1);
	if(temp) {arr[nv]=temp;return;}
	get_tree(++n,nv);
	get_tree(++n,nv);
}
int main(){
	limit=read()-1;
	get_tree(1,0);
	get_dp(0,0);
	printf("%d",dp[0][limit]);
	return 0;
}
