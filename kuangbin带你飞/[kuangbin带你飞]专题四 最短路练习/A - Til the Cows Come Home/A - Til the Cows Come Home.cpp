#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
const int INF=2147483647;
const int MAXN=1005;
int m,n,u,v,k;
int dist[MAXN];
int Queue[MAXN],head,tail;
bool vis[MAXN];
struct edge{
	int v,val;
	edge *nex;
	edge() {v=val=0;nex=NULL;}
}*con[MAXN];
void ins(int Start,int End,int key){
	edge *p=new(edge);
	p->v=End;p->val=key;
	p->nex=con[Start];con[Start]=p;
}
void spfa(){
	for(int i=1;i<n;++i) dist[i]=INF;
	Queue[head=tail=1]=n;vis[n]=true;
	while((head-1)!=tail%(MAXN-1)){
		int nv=Queue[head];
		for(edge *p=con[nv];p;p=p->nex){
			if(dist[p->v]>dist[nv]+p->val){
				dist[p->v]=dist[nv]+p->val;
				if(vis[p->v]==false){
					tail=(tail==MAXN-1)?1:(tail+1);
					Queue[tail]=p->v;vis[p->v]=true;
				}
			}
		}
		head=(head==MAXN-1)?1:(head+1);
		vis[nv]=false;
	}
}
int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	m=read();n=read();
	while(m--){
		u=read();v=read();k=read();
		ins(u,v,k);ins(v,u,k);
	}
	spfa();
	printf("%d",dist[1]);
	return 0;
}
