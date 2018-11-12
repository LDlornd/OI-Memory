#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN=40002;
int N,N1,N2,N3,M,u,v,ans=0;
int depth[MAXN];
int Queue[MAXN],head,tail;
struct edge{
	int v,remain;
	edge *nex,*rev;
	edge() {v=remain=0;nex=rev=NULL;}
}*con[MAXN],*now[MAXN];
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
		for(edge *p=con[nv];p;p=p->nex){
			if(depth[p->v]==-1&&p->remain>0){
				depth[p->v]=depth[nv]+1;
				Queue[++tail]=p->v;
			}
		}
	}
	return depth[N+1]!=-1;
}
inline int dfs(int nv,int maxflow){
	int nowflow,totflow=0;
	if(depth[nv]==-1) return 0;
	if(nv==N+1) return maxflow;
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
		for(int i=0;i<=N+1;++i) now[i]=con[i];
		while(flow=dfs(0,2147483647))
			ans+=flow;
	}
}
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	N1=read();N2=read();N3=read();
	N=N1+N2+N3+N1;
	for(int i=1;i<=N1;++i) ins(i,N1+N2+N3+i,1);
	for(int i=1;i<=N2;++i) ins(N1+i,N+1,1);
	for(int i=1;i<=N3;++i) ins(0,N1+N2+i,1);
	M=read();
	while(M--){
		u=read();v=read();
		ins(N1+N2+N3+u,N1+v,1);
	}
	M=read();
	while(M--){
		u=read();v=read();
		ins(N1+N2+v,u,1);
	}
	dinic();
	printf("%d",ans);
	return 0;
}
