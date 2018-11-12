#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
const int INF=1e9+7;
const int MAXN=205;
int n,m,u,v,l;
int dist[MAXN][MAXN];
int Queue[10000],head,tail; 
bool flag1=false,flag2=false;
bool vis[MAXN];
struct edge{
	int v,len;
	edge *nex;
}*con[MAXN];
void ins(int Start,int End,int key){
	edge *p=new(edge);
	p->v=End;p->len=key;
	p->nex=con[Start];con[Start]=p;
}
void dfs(int broken,int Start){
	Queue[head=tail=1]=Start;
	vis[Start]=true;
	while(head<=tail){
		int nv=Queue[head++];
		for(edge *p=con[nv];p;p=p->nex){
			if(p->v!=broken&&vis[p->v]==false&&dist[Start][p->v]==dist[Start][nv]+p->len&&dist[nv][p->v]==p->len) {Queue[++tail]=p->v;vis[p->v]=true;}
		}
	}
}
void init(){
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			dist[i][j]=(i==j)?0:INF;
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
	while(m--){
		u=read();v=read();l=read();
		ins(u,v,l);ins(v,u,l);
		dist[u][v]=dist[v][u]=l;
	}
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)			
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
	for(int i=1;i<=n;++i){
		flag1=false;
		for(int j=1;j<=n;++j){
			if(i==j) continue;
			memset(vis,0,sizeof(vis));
			dfs(i,j);
			for(int k=1;k<=n;++k)
				if(dist[j][k]!=INF&&vis[k]==false&&k!=i) {flag1=true;break;}
			if(flag1) break;
		}
		if(flag1){
			flag2=true;
			printf("%d ",i);
		}
	}
	if(flag2==false) printf("No important cities.");
	return 0;
}
