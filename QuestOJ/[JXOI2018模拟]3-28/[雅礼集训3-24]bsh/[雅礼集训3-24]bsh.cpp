#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
const int MAXN=52001;
int n,q,u,v;
int dist[MAXN];
int Queue[MAXN],head,tail;
bool vis[MAXN];
struct edge{
	int v;
	edge *Next;
	edge() {v=0;Next=NULL;}
}*con[MAXN];
inline void ins(int Start,int End){
	edge *p=new(edge);
	p->v=End;
	p->Next=con[Start];
	con[Start]=p;
}
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
inline int bfs(int Start,int End){
	if(Start==End) return 0;
	memset(vis,0,sizeof(vis));
	head=1;tail=1;Queue[1]=Start;
	dist[Start]=0;vis[Start]=true;
	while(head<=tail){
		int nv=Queue[head++];
		for(edge *p=con[nv];p;p=p->Next){
			int vv=p->v;
			if(vv==End) return dist[nv]+1;
			if(vis[vv]==false){
				Queue[++tail]=vv;
				vis[vv]=true;
				dist[vv]=dist[nv]+1;
			}
		}
	}
}
int main(){
	n=read();
	for(int i=4;i<=n;++i){
		u=read();v=read();
		ins(u,v);ins(v,u);
	}
	for(int i=1;i<n;++i) {ins(i,i+1);ins(i+1,i);}
	ins(1,n);ins(n,1);
	q=read();
	while(q--){
		u=read();v=read();
		printf("%d\n",bfs(u,v));
	}
	return 0;
}
