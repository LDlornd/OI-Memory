#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=2e5+1;
int n,m,q,u,v,k;
int fa[MAXN],num[MAXN];
struct edge{
	int v;
	edge *nex;
	edge() {v=0;nex=NULL;}
}*con[MAXN];
void ins(int Start,int End){
	edge *p=new(edge);
	p->v=End;
	p->nex=con[Start];con[Start]=p;
}
void gettree(int nv,int father){
	fa[nv]=father;
	for(edge *p=con[nv];p;p=p->nex){
		if(p->v==father) continue;
		gettree(p->v,nv);
	}
}
int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read();m=read();
	for(int i=1;i<n;++i){
		u=read();v=read();
		ins(u,v);ins(v,u);
	}
	gettree(1,0);
	while(m--){
		u=read();v=read();
		while(u!=1) {++num[u];u=fa[u];}
		while(v!=1) {++num[v];v=fa[v];}
	}
	q=read();
	while(q--){
		u=read();k=read();
		int ans=0;
		while(u!=1){
			if(num[u]<k) break;
			++ans;
			u=fa[u];
		}
		printf("%d\n",ans);
	}
	return 0;
}
