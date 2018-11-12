#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN=1e5+1;
int n,m,u,v;
int dist[MAXN];
int Queue[MAXN],head,tail;
bool flag[MAXN];
struct edge{
	int v,len;
	edge *nex;
	edge() {v=len=0;nex=NULL;}
}*con[MAXN];
inline void ins(int Start,int End,int key){
	edge *p=new(edge);
	p->v=End;p->len=key;
	p->nex=con[Start];con[Start]=p;
}
inline void spfa(){
	for(int i=2;i<=n;++i) dist[i]=-2147483647;
	dist[1]=0;flag[1]=true;
	Queue[head=tail=1]=1;
	while((head-1)!=(tail%(MAXN-1))){
		int nv=Queue[head];
		for(edge *p=con[nv];p;p=p->nex){
			int vv=p->v;
			if(dist[vv]<dist[nv]+p->len){
				dist[vv]=dist[nv]+p->len;
				if(flag[vv]==false){
					tail=(tail==MAXN-1)?1:tail+1;
					Queue[tail]=vv;flag[vv]=true;
				}
			}
		}
		head=(head==MAXN-1)?1:head+1;
		flag[nv]=false;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;++i){
		ins(i+1,i,-1);ins(i,i+1,0);
	}
	while(m--){
		scanf("%d%d",&u,&v);
		ins(u,v,1);
	}
	spfa();
	printf("%d",dist[n]);
	return 0;
}
