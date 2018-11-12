#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN=100001;
int T,N,K,u,ans=0;
bool vis[MAXN],flag[MAXN];
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
inline void dfs(int nv,int fa){
	flag[nv]=true;
	for(edge *p=con[nv];p;p=p->Next) if(flag[p->v]==false) dfs(p->v,nv);
	if(vis[nv]==false&&vis[fa]==false&&K>=2){
		K-=2;++ans;
		vis[nv]=vis[fa]=true;
	}
}
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';
	return x*f;
}
int main(){
	T=read();
	while(T--){
		memset(vis,0,sizeof(vis));vis[0]=1;
		memset(flag,0,sizeof(flag));
		ans=0;
		N=read();K=read();
		for(int i=2;i<=N;++i){
			u=read();
			ins(i,u);
			ins(u,i);
		}
		dfs(1,0);
		printf("%d\n",ans+K);
	}
	return 0;
}
