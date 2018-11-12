#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<map>
using namespace std;
const int MAXN=100001;
int n,m,standard,u,v,lowsize=0,highsize=0;
int in[MAXN];
bool vis[MAXN];
vector<int> low,high;
map<int,bool> G[MAXN];
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
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') c=getchar();
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
inline void print(int k1,int k2,int k3){
	if(k1>k2) swap(k1,k2);
	if(k1>k3) swap(k1,k3);
	if(k2>k3) swap(k2,k3);
	printf("%d %d %d",k1,k2,k3);
	return;
}
int main(){
	n=read();m=read();standard=sqrt(m);
	while(m--){
		u=read();v=read();
		ins(u,v);ins(v,u);
		++in[u];++in[v];
		G[u].insert(make_pair(v,true));
		G[v].insert(make_pair(u,true));
	}
	for(int i=1;i<=n;++i){
		int x=i;
		vis[x]=true;
		for(edge *p=con[x];p;p=p->Next){
			int y=p->v;
			if(vis[y]) continue;
			for(edge *q=p->Next;q;q=q->Next){
				int z=q->v;
				if(vis[z]) continue;
				if(G[y].count(z)){
					print(x,y,z);
					return 0;
				}
			}
		}
	}
	return 0;
}
