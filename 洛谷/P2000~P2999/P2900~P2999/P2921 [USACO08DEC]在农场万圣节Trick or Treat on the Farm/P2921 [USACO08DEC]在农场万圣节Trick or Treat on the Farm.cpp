#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN=100005;
int n,v,visit=0,tot=0;
int dfn[MAXN],low[MAXN],belong[MAXN],sum[MAXN];
int Stack[MAXN],top=0;
int Queue[MAXN],head,tail;
int indu[MAXN],outdu[MAXN];
bool vis[MAXN];
struct edge{
	int v;
	edge *nex;
	edge() {v=0;nex=NULL;}
}*con[MAXN],*new_con[MAXN];
void ins(int Start,int End,edge *a[]){
	edge *p=new(edge);
	p->v=End;
	p->nex=a[Start];a[Start]=p;
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
		++tot;
		for(;Stack[top+1]!=nv;--top){
			vis[Stack[top]]=false;
			belong[Stack[top]]=tot;
			++sum[tot];
		}
	}
}
void rebuild(){
	for(int i=1;i<=n;++i){
		for(edge *p=con[i];p;p=p->nex){
			if(belong[i]!=belong[p->v]){
				ins(belong[i],belong[p->v],new_con);
				++indu[belong[p->v]];++outdu[belong[i]];
			}
		}
	}
}
void top_sort(){
	head=1;tail=0;
	for(int i=1;i<=tot;++i)
		if(indu[i]==0) Queue[++tail]=i;
	while(head!=tail+1){
		int nv=Queue[head++];
		for(edge *p=new_con[nv];p;p=p->nex)
			if(--indu[p->v]==0) Queue[++tail]=p->v;
	}
}
int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		v=read();
		ins(i,v,con);
	}
	for(int i=1;i<=n;++i)
		if(dfn[i]==0) tarjan(i);
	rebuild();
	top_sort();
	for(int i=tot;i>=1;--i){
		int nv=Queue[i];
		if(outdu[nv]==0) continue;
		for(edge *p=new_con[nv];p;p=p->nex){
			sum[nv]+=sum[p->v];
		}
	}
	for(int i=1;i<=n;++i)
		printf("%d\n",sum[belong[i]]);
	return 0;
}
