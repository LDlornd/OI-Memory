#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN=1000001;
int n,m,u,v,visit=0,tot=0,ans=0;
int dfn[MAXN],low[MAXN],belong[MAXN];
int Stack[MAXN],top;
int rudu[MAXN],res[MAXN],head,tail;
int val[MAXN],dp[MAXN];
bool instack[MAXN];
struct edge{
	int v;
	edge *Next;
	edge() {v=0;Next=NULL;}
}*con[MAXN],*newcon[MAXN];
inline void ins(int Start,int End,edge *a[]){
	edge *p=new(edge);
	p->v=End;
	p->Next=a[Start];
	a[Start]=p;
}
inline void tarjan(int nv){
	int place;
	dfn[nv]=low[nv]=++visit;
	Stack[++top]=nv;instack[nv]=true;
	for(edge *p=con[nv];p;p=p->Next){
		int vv=p->v;
		if(dfn[vv]==0){
			tarjan(vv);
			low[nv]=min(low[nv],low[vv]);
		}
		else if(instack[vv]) low[nv]=min(low[nv],dfn[vv]);
	}
	if(low[nv]==dfn[nv]){
		++tot;
		do{
			place=Stack[top--];
			belong[place]=tot;
			instack[place]=false;
		}while(place!=nv);
	}
}
inline void rebuild(){
	for(int i=1;i<=n;++i){
		++val[belong[i]];
		for(edge *p=con[i];p;p=p->Next){
			int nv=p->v;
			if(belong[i]!=belong[nv]){
				ins(belong[i],belong[nv],newcon);
				++rudu[belong[nv]];
			}
		}
	}
}
inline void top_sort(){
	head=1;tail=0;
	for(int i=1;i<=tot;++i) if(rudu[i]==0) res[++tail]=i;
	while(head<=tail){
		int nv=res[head++];
		for(edge *p=newcon[nv];p;p=p->Next){
			int vv=p->v;--rudu[vv];
			if(rudu[vv]==0) res[++tail]=vv;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	while(m--){
		cin>>u>>v;
		ins(u,v,con);
	}
	for(int i=1;i<=n;++i)
		if(dfn[i]==0) tarjan(i);
	rebuild();
	top_sort();
	for(int i=1;i<=tot;++i) dp[i]=val[i];
	for(int i=1;i<=tot;++i){
		int nv=res[i];
		for(edge *p=newcon[nv];p;p=p->Next){
			int vv=p->v;
			dp[vv]=max(dp[vv],dp[nv]+val[vv]);
		}
	}
	for(int i=1;i<=tot;++i) ans=max(ans,dp[i]);
	cout<<ans;
	return 0;
}
