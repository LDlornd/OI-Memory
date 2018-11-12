#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long int ll;
const int MAXN=2005;
const int INF=0x3f3f3f3f;
int n,m,u,v,k;
int dis[MAXN],link[MAXN][MAXN];
int Queue[MAXN],head,tail;
ll dp[MAXN];
bool vis[MAXN];
struct edge{
	int v,len;
	edge *nex;
	edge() {v=len=0;nex=NULL;}
}*con[MAXN],*gra[MAXN];
void ins(int Start,int End,int key,edge *a[]){
	edge *p=new(edge);
	p->v=End;p->len=key;
	p->nex=a[Start];a[Start]=p;
}
void spfa(){
	for(int i=1;i<=n;++i){
		dis[i]=INF;
	}
	dis[n]=0;
	Queue[head=tail=1]=n;vis[n]=true;
	while(head<=tail){
		int nv=Queue[head%MAXN];
		for(edge *p=con[nv];p;p=p->nex){
			if(dis[p->v]>dis[nv]+p->len){
				dis[p->v]=dis[nv]+p->len;
				if(vis[p->v]==false){
					vis[p->v]=true;
					++tail;
					Queue[tail%MAXN]=p->v;
				}
			}
		}
		++head;vis[nv]=false;
	}
}
ll dfs(int nv){
	if(dp[nv]) return dp[nv];
	dp[nv]=(nv==n)?1:0;
	for(edge *p=gra[nv];p;p=p->nex){
		if(dis[nv]==dis[p->v]+p->len){
			dp[nv]+=dfs(p->v);
		}
	}
	return dp[nv];
}
int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	memset(link,INF,sizeof(link));
	n=read();m=read();
	while(m--){
		u=read();v=read();k=read();
		if(link[u][v]<=k) continue;
		ins(v,u,k,con);ins(u,v,k,gra);
		link[u][v]=k;
	}
	spfa();
	if(dis[1]==INF) printf("No answer");
	else printf("%d %lld",dis[1],dfs(1));
	return 0;
}
