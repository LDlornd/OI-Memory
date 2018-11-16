#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
typedef long long int ll;
const int MAXN=10005;
const int INF=2147483647;
int n,m,s,u,v,k;
int dist[MAXN];
int Queue[MAXN],head,tail;
bool vis[MAXN];
struct edge{
	int v,len;
	edge *nex;
	edge() {v=len=0;nex=NULL;}
}*con[MAXN];
void ins(int Start,int End,int key){
	edge *p=new(edge);
	p->v=End;p->len=key;
	p->nex=con[Start];con[Start]=p;
}
void spfa(){
	for(int i=1;i<=n;++i) dist[i]=INF;
	dist[s]=0;vis[s]=true;
	Queue[head=tail=1]=s;
	while(head<=tail){
		int nv=Queue[head%MAXN];
		for(edge *p=con[nv];p;p=p->nex){
			if(dist[p->v]>dist[nv]+p->len){
				dist[p->v]=dist[nv]+p->len;
				if(vis[p->v]==false){
					++tail;vis[p->v]=true;
					Queue[tail%MAXN]=p->v;
				}
			}
		}
		++head;vis[nv]=false;
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&s);
	while(m--){
		scanf("%d%d%d",&u,&v,&k);
		ins(u,v,k);
	}
	spfa();
	for(int i=1;i<=n;++i) printf("%d ",dist[i]);
	return 0;
}
