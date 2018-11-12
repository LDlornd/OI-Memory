#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
typedef long long int ll;
const int INF=2147483647;
const int MAXN=2001;
int T,n,m,u,v,k;
ll dist[MAXN];
int rudu[MAXN],tot[MAXN];
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
	p->nex=con[Start];con[Start]=p;
	++rudu[End];
}
inline bool spfa(){
	for(int i=1;i<=n;++i) dist[i]=INF;
	dist[0]=0;tot[0]=1;
	Queue[head=tail=1]=0;vis[0]=true;
	while((head-1)!=tail%(MAXN-1)){
		int nv=Queue[head];
		for(edge *p=con[nv];p;p=p->nex){
			int vv=p->v;
			if(dist[vv]>dist[nv]+p->val){
				dist[vv]=dist[nv]+p->val;
				if(vis[vv]==false){
					tail=(tail==MAXN-1)?1:(tail+1);
					Queue[tail]=vv;
					vis[vv]=true;++tot[vv];
					if(tot[vv]>rudu[vv]) return false;
				}
			}
		}
		head=(head==MAXN-1)?1:(head+1);
		vis[nv]=false;
	}
	return true;
}
inline void getready(){
	memset(con,0,sizeof(con));
	memset(rudu,0,sizeof(rudu));
	memset(tot,0,sizeof(tot));
	memset(vis,0,sizeof(vis));
}
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	//freopen("testdata.in","r",stdin);
	T=read();
	while(T--){
		getready();
		n=read();m=read();
		while(m--){
			u=read();v=read();k=read();
			ins(u,v,k);
			if(k>=0) ins(v,u,k);
		}
		for(int i=1;i<=n;++i)
			if(rudu[i]==0) ins(0,i,0);
		if(con[0]==NULL) ins(0,1,0);
		if(spfa()) printf("N0\n");
		else printf("YE5\n");
	}
}
