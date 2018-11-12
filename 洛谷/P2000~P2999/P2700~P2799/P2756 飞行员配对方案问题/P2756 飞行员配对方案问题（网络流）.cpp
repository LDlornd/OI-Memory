#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<vector> 
using namespace std;
const int MAXN=210;
int n,m,u,v,ans=0;
int depth[MAXN];
int Queue[MAXN],head,tail;
bool vis[MAXN];
struct G{
	int Left,Right;
	G(int ll=0,int rr=0) {Left=ll;Right=rr;}
};
vector<G> bian;
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
		for(edge *p=con[nv];p;p=p->nex)
			if(depth[p->v]==-1&&p->remain>0){
				depth[p->v]=depth[nv]+1;
				Queue[++tail]=p->v;
			}
	}
	return depth[n+1]!=-1;
}
inline int dfs(int nv,int maxflow){
	int nowflow=0,totflow=0;
	if(depth[nv]==-1) return 0;
	if(nv==n+1) return maxflow;
	for(edge *p=now[nv];p;p=p->nex){
		now[nv]=p;
		if(p->remain>0&&depth[p->v]==depth[nv]+1){
			nowflow=dfs(p->v,min(maxflow-totflow,p->remain));
			p->remain-=nowflow;
			p->rev->remain+=nowflow;
			totflow+=nowflow;
		}
		if(totflow==maxflow) break;
	}
	if(totflow==0) depth[nv]=-1;
	return totflow;
}
inline void dinic(){
	int flow;
	while(bfs()){
		for(int i=0;i<=n+1;++i) now[i]=con[i];
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
	m=read();n=read();
	while(true){
		u=read();v=read();
		if(u==-1&&v==-1) break;
		if(u>v) swap(u,v);
		ins(u,v,1);
		bian.push_back(G(u,v));
	}
	for(int i=1;i<=m;++i) ins(0,i,1);
	for(int i=m+1;i<=n;++i) ins(i,n+1,1);
	dinic();
	if(ans==0) printf("No Solution!");
	else{
		printf("%d\n",ans);
		for(int i=1;i<=m;++i){
			for(edge *p=con[i];p;p=p->nex){
				int vv=p->v;
				if(vv!=0&&vv!=n+1&&p->remain==0){
					printf("%d %d\n",i,vv);
				}
			}
		}
	}
	return 0;
}
