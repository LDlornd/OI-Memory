#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN=1000001;
int n,m,tot,k,ans=0;
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
	p->v=Start;p->remain=key;
	p->nex=con[End];con[End]=p;
	con[Start]->rev=con[End];
	con[End]->rev=con[Start];
}
inline bool bfs(){
	memset(depth,-1,sizeof(depth));
	Queue[head=tail=1]=1;
	depth[1]=1;
	while(head<=tail){
		int nv=Queue[head++];
		for(edge *p=con[nv];p;p=p->nex)
			if(depth[p->v]==-1&&p->remain>0){
				depth[p->v]=depth[nv]+1;
				Queue[++tail]=p->v;
			}
	}
	return depth[tot]!=-1;
}
inline int dfs(int nv,int maxflow){
	int nowflow=0,totflow=0;
	if(depth[nv]==-1) return 0;
	if(nv==tot) return maxflow;
	for(edge *p=now[nv];p;p=p->nex){
		now[nv]=p;
		if(depth[p->v]==depth[nv]+1&&p->remain>0){
			nowflow=dfs(p->v,min(maxflow-totflow,p->remain));
			p->remain-=nowflow;
			p->rev->remain+=nowflow;
			totflow+=nowflow;
		}
		if(maxflow==totflow) break;
	}
	if(totflow==0) depth[nv]=-1;
	return totflow;
}
inline void dinic(){
	int flow;
	while(bfs()){
		for(int i=1;i<=tot;++i) now[i]=con[i];
		while(flow=dfs(1,2147483647))
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
	tot=(n=read())*(m=read());
	for(int i=1;i<=n;++i)
		for(int j=1;j<m;++j){
			int nv=(i-1)*m+j;
			ins(nv,nv+1,(k=read()));
		}
	for(int i=1;i<n;++i)
		for(int j=1;j<=m;++j){
			int nv=(i-1)*m+j;
			ins(nv,nv+m,(k=read()));
		}
	for(int i=1;i<n;++i)
		for(int j=1;j<m;++j){
			int nv=(i-1)*m+j;
			ins(nv,nv+m+1,(k=read()));
		}
	dinic();
	printf("%d",ans);
	return 0;
}
