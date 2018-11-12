#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
const int INF=2147483647;
const int MAXN=30001;
int n,m,l,r,k;
int dist[MAXN];
int Queue[MAXN],head,tail;
bool vis[MAXN];
struct edge{
	int v,val;
	edge *nex;
	edge() {v=val=0;nex=NULL;}
}*con[MAXN];
inline void ins(int Start,int End,int key){
	edge *p=new(edge);
	p->v=End;p->val=key;
	p->nex=con[Start];
	con[Start]=p;
}
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
inline void spfa(){
	for(int i=1;i<=n;++i) dist[i]=-INF;
	Queue[head=tail=1]=0;vis[0]=true;
	while((head-1)!=tail%(MAXN-1)){
		int nv=Queue[head];
		for(edge *p=con[nv];p;p=p->nex){
			int vv=p->v;
			if(dist[vv]<dist[nv]+p->val){
				dist[vv]=dist[nv]+p->val;
				if(vis[vv]==false){
					tail=(tail==MAXN-1)?1:(tail+1);
					Queue[tail]=vv;
					vis[vv]=true;
				}
			}
		}
		head=(head==MAXN-1)?1:(head+1);
		vis[nv]=false;
	}
}
int main(){
	n=read();m=read();
	while(m--){
		l=read();r=read();k=read();
		ins(l-1,r,k);
	}
	for(int i=0;i<n;++i) {ins(i,i+1,0);ins(i+1,i,-1);}
	spfa();
	printf("%d",dist[n]);
	return 0;
} 
