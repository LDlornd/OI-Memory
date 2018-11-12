#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN=510;
int t,n,m,S,T,tot,temp,casenum=0,maxtime=0;
int s[MAXN],p[MAXN],e[MAXN];
int depth[MAXN];
int Queue[MAXN],head,tail;
struct edge{
	int v,remain;
	edge *nex,*rev;
	edge() {v=remain=0;nex=rev=NULL;}
}*con[MAXN<<1],*now[MAXN<<1];
inline void ins(int Start,int End,int key){
	edge *p=new(edge);
	p->v=End;p->remain=key;
	p->nex=con[Start];con[Start]=p;
	p=new(edge);
	p->v=Start;p->remain=0;
	p->nex=con[End];con[End]=p;
	con[Start]->rev=con[End];
	con[End]->rev=con[Start];
}
inline bool bfs(){
	memset(depth,-1,sizeof(depth));
	Queue[head=tail=1]=0;
	depth[0]=1;
	while(head<=tail){
		int nv=Queue[head++];
		for(edge *p=con[nv];p;p=p->nex)
			if(depth[p->v]==-1&&p->remain>0){
				depth[p->v]=depth[nv]+1;
				Queue[++tail]=p->v;
			}
	}
	return depth[T]!=-1;
}
inline int dfs(int nv,int maxflow){
	int nowflow=0,totflow=0;
	if(depth[nv]==-1||maxflow<=0) return 0;
	if(nv==T) return maxflow;
	for(edge *p=now[nv];p;p=p->nex){
		now[nv]=p;
		if(depth[p->v]==depth[nv]+1&&p->remain>0){
			nowflow=dfs(p->v,min(maxflow-totflow,p->remain));
			p->remain-=nowflow;
			p->rev->remain+=nowflow;
			totflow+=nowflow;
		}
		if(totflow>=maxflow) break;
	}
	if(totflow==0) depth[nv]=-1;
	return totflow;
}
inline void dinic(){
	int flow;
	while(bfs()){
		for(int i=0;i<=T;++i) now[i]=con[i];
		while(flow=dfs(S,2147483647))
			tot+=flow;
	}
}
int main(){
	//t=read();
	scanf("%d",&t);
	while(t--){
		memset(con,0,sizeof(con));
		//n=read();m=read();
		scanf("%d%d",&n,&m);
		temp=0;
		for(int i=1;i<=n;++i){
			//p[i]=read();s[i]=read();e[i]=read();
			scanf("%d%d%d",&p[i],&s[i],&e[i]);
			temp+=p[i];
			maxtime=max(maxtime,e[i]);
		}
		S=0;T=maxtime+n+1;tot=0;
		for(int i=1;i<=n;++i){
			ins(S,maxtime+i,p[i]);
			for(int j=s[i];j<=e[i];++j){
				ins(maxtime+i,j,1);
			}
		}
		for(int i=1;i<=maxtime;++i) ins(i,T,m);
		dinic();
		printf("Case %d: ",++casenum);
		if(tot==temp) printf("Yes\n\n");
		else printf("No\n\n");
	}
}
