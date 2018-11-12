#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN=201;
long long int ans=0;
int n,m,u,v,k;
int depth[MAXN];
int Queue[MAXN],head,tail;
bool flag[MAXN][MAXN];
struct edge{
	int v,remain;
	edge *nex,*rev;
	edge() {v=remain=0;nex=rev=NULL;}
}*con[MAXN],*now[MAXN];
inline void ins_1(int Start,int End,int key){
	edge *p=new(edge);
	p->v=End;p->remain=key;
	p->nex=con[Start];con[Start]=p;
	p=new(edge);
	p->v=Start;p->remain=0;
	p->nex=con[End];con[End]=p;
	con[Start]->rev=con[End];
	con[End]->rev=con[Start];
	flag[Start][End]=flag[End][Start]=true;
}
inline void ins_2(int Start,int End,int key){
	for(edge *p=con[Start];p;p=p->nex){
		if(p->v==End){
			p->remain+=key;
			break;
		}
	}
}
inline bool bfs(){
	memset(depth,-1,sizeof(depth));
	Queue[head=tail=1]=1;
	depth[1]=1;
	while(head<=tail){
		int nv=Queue[head++];
		for(edge *p=con[nv];p;p=p->nex){
			if(depth[p->v]==-1&&p->remain>0){
				depth[p->v]=depth[nv]+1;
				Queue[++tail]=p->v;
			}
		}
	}
	return depth[n]!=-1;
}
inline int dfs(int nv,int maxflow){
	int nowflow=0,totflow=0;
	if(depth[nv]==-1) return 0;
	if(nv==n) return maxflow;
	for(edge *p=now[nv];p;p=p->nex){
		now[nv]=p;
		if(depth[p->v]==depth[nv]+1&&p->remain>0){
			nowflow=dfs(p->v,min(maxflow-totflow,p->remain));
			p->remain-=nowflow;
			p->rev->remain+=nowflow;
			totflow+=nowflow;
		}
	}
	if(totflow==0) depth[nv]=-1;
	return totflow;
}
inline void dinic(){
	int nowflow;
	while(bfs()){
		for(int i=1;i<=n;++i) now[i]=con[i];
		while(nowflow=dfs(1,2147483647))
			ans+=nowflow;
	}
}
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	while(scanf("%d%d",&m,&n)!=EOF){
		memset(con,0,sizeof(con));
		memset(now,0,sizeof(now));
		memset(flag,0,sizeof(flag));
		ans=0;
		while(m--){
			u=read();v=read();k=read();
			if(flag[u][v]==false) ins_1(u,v,k);
			else ins_2(u,v,k);
		}
		dinic();
		printf("%lld\n",ans);
	}
	return 0;
}
