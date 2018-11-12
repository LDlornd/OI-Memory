#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN=10001;
long long int ans=0;
int n,m,s,t,u,v,k;
int depth[MAXN];
int Queue[MAXN],head,tail;
struct edge{
	int v,remain;
	edge *Next,*rev;
	edge() {v=remain=0;Next=rev=NULL;}
}*con[MAXN],*now[MAXN];
inline void ins(int Start,int End,int Key){
	edge *p=new(edge);
	p->v=End;p->remain=Key;
	p->Next=con[Start];con[Start]=p;
	p=new(edge);
	p->v=Start;p->remain=0;
	p->Next=con[End];con[End]=p;
	con[End]->rev=con[Start];
	con[Start]->rev=con[End];
}
inline bool bfs(){
	memset(depth,-1,sizeof(depth));
	Queue[head=tail=1]=s;
	depth[s]=1;
	while(head<=tail){
		int nv=Queue[head++];
		for(edge *p=con[nv];p;p=p->Next)
			if(depth[p->v]==-1&&p->remain>0){
				depth[p->v]=depth[nv]+1;
				Queue[++tail]=p->v;
			}
	}
	return depth[t]!=-1;
}
inline int dfs(int nv,int maxflow){
	int Now=0,tot=0;
	if(depth[nv]==-1||maxflow==0) return 0;
	if(nv==t) return maxflow;
	for(edge *p=now[nv];p;p=p->Next){
		now[nv]=p;
		if(p->remain>0&&depth[p->v]==depth[nv]+1){
			Now=dfs(p->v,min(maxflow-tot,p->remain));
			p->remain-=Now;
			p->rev->remain+=Now;
			tot+=Now;
		}
		if(maxflow==tot) break;
	}
	if(tot==0) depth[nv]=-1;
	return tot;
}
inline void dinic(){
	int flow;
	while(bfs()){
		for(int i=1;i<=n;++i) now[i]=con[i];
		while(flow=dfs(s,2147483647))
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
	n=read();m=read();s=read();t=read();
	while(m--){
		u=read();v=read();k=read();
		ins(u,v,k);
	}
	dinic();
	printf("%d",ans);
	return 0;
}
