#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
typedef long long int ll;
const int MAXN=100005;
int n,v,k,cnt=0,visit=0,ans=0;
int Stack[MAXN],top=0;
int dfn[MAXN],low[MAXN],belong[MAXN],sum[MAXN];
bool vis[MAXN];
struct edge{
	int v,len;
	edge *nex;
	edge() {v=len=0;nex=NULL;}
}*con[MAXN];
void ins(int Start,int End,ll key){
	edge *p=new(edge);
	p->v=End;p->len=key;
	p->nex=con[Start];con[Start]=p;
}
int dfs(int nv){
	dfn[nv]=1;
	for(edge *p=con[nv];p;p=p->nex)
		if(belong[nv]==belong[p->v]){
			if(dfn[p->v]) return p->len;
			else return dfs(p->v)+p->len;
		}
	return 0;
}
void tarjan(int nv){
	dfn[nv]=low[nv]=++visit;
	Stack[++top]=nv;vis[nv]=true;
	for(edge *p=con[nv];p;p=p->nex){
		if(dfn[p->v]==0){
			tarjan(p->v);
			low[nv]=min(low[nv],low[p->v]);
		}
		else if(vis[p->v]) low[nv]=min(low[nv],dfn[p->v]);
	}
	if(dfn[nv]==low[nv]){
		++cnt;
		for(;Stack[top]!=nv;--top){
			belong[Stack[top]]=cnt;
			vis[Stack[top]]=false;
		}
		belong[nv]=cnt;--top;
		vis[nv]=false;
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
	n=read<int>();
	for(int i=1;i<=n;++i){
		v=read<int>();k=read<int>();
		ins(i,v,k);
	}
	for(int i=1;i<=n;++i)
		if(dfn[i]==0) tarjan(i);
	memset(dfn,0,sizeof(dfn));
	for(int i=1;i<=n;++i){
		if(dfn[i]==0){
			ans=max(ans,dfs(i));
		}
	}
	printf("%d",ans);
	return 0;
}
