#include<cstdio>
#include<iostream>
using namespace std;
typedef long long int ll;
const int MAXN=1e5+5;
ll k;
int n,t;
ll zxx[MAXN],zxy[MAXN],ysx[MAXN],ysy[MAXN],place[MAXN];
ll dist[MAXN];
int Queue[MAXN],head,tail;
bool vis[MAXN];
struct edge{
	int v;
	ll len;
	edge *nex;
	edge() {v=len=0;nex=NULL;}
}*con[MAXN];
void ins(int Start,int End,ll key){
	edge *p=new(edge);
	p->v=End;p->len=key;
	p->nex=con[Start];con[Start]=p;
}
void dfs(int key){
	for(int i=1;i<=n;++i) dist[i]=k;
	Queue[head=tail=1]=key;
	dist[key]=0;vis[key]=true;
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
template<typename T>
T read(){
	T x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read<int>();t=read<int>();k=read<ll>();
	for(int i=1;i<=n;++i) {zxx[i]=read<ll>();zxy[i]=read<ll>();ysx[i]=read<ll>();ysy[i]=read<ll>();}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if(i!=j&&zxx[j]>=ysx[i]&&zxy[i]<ysy[j]&&ysy[i]>zxy[j]) ins(i,j,zxx[j]-ysx[i]);
	dfs(t);	
	for(int i=1;i<=n;++i) place[i]=zxx[i]+k-dist[i];
	for(int i=1;i<=n;++i) printf("%lld ",place[i]);
	return 0;
}
