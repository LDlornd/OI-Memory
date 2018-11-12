#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long int ll;
const int mod=998244353;
const int MAXN=1e6+5;
int n,m,visit=0;
ll ans[MAXN];
int len[MAXN];
int dfn[MAXN],low[MAXN],belong[MAXN],sum[MAXN],cnt=0;
int indu[MAXN];
int Queue[MAXN],head,tail;
int Stack[MAXN],top=0;
bool vis[MAXN];
struct node{
	int Start,End;
	ll val;
	node() {Start=End=val=0;}
}arr[MAXN];
struct edge{
	int v;
	ll val;
	edge *nex;
	edge() {v=val=0;nex=NULL;}
}*con[MAXN],*new_con[MAXN];
void ins(int Start,int End,ll key,edge *a[]){
	edge *p=new(edge);
	p->v=End;p->val=key;
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
		++cnt;
		while(Stack[top+1]!=nv){
			vis[Stack[top]]=false;
			belong[Stack[top--]]=cnt;
			++sum[cnt];
		}
	}
}
void rebuild(){
	for(int i=1;i<=n;++i){
		for(edge *p=con[i];p;p=p->nex){
			if(belong[i]==belong[p->v]) continue;
			ins(belong[i],belong[p->v],p->val,new_con);
			++indu[belong[p->v]];
		}
	}
}
void top_sort(){
	head=1;tail=0;
	for(int i=1;i<=cnt;++i) if(indu[i]==0) Queue[++tail]=i;
	while(head!=tail+1){
		int nv=Queue[head++];
		for(edge *p=new_con[nv];p;p=p->nex)
			if(--indu[p->v]==0) Queue[++tail]=p->v;
	}
}
bool CMP(const node &a,const node &b){
	if(a.Start==b.Start){
		if(a.End==b.End) return a.val<b.val;
		else return a.End<b.End;
	}
	else return a.Start<b.Start;
}
template<typename T>
T read(){
	T x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read<int>();m=read<int>();
	for(int i=1;i<=m;++i) {arr[i].Start=read<int>();arr[i].End=read<int>();arr[i].val=read<ll>();}
	sort(arr+1,arr+m+1,CMP);
	for(int i=1;i<=m;++i){
		if(arr[i].Start==arr[i-1].Start&&arr[i].End==arr[i-1].End) continue;
		ins(arr[i].Start,arr[i].End,arr[i].val,con);
	}
	for(int i=1;i<=n;++i)
		if(dfn[i]==0) tarjan(i);
	rebuild();
	top_sort();
	for(int i=cnt;i>=1;--i){
		int nv=Queue[i];
		ans[nv]=0;len[nv]=0;
		for(edge *p=new_con[nv];p;p=p->nex){
			if(len[nv]<len[p->v]+1){
				len[nv]=len[p->v]+1;
				ans[nv]=(ans[p->v]*29%mod+p->val*29)%mod;
			}
		}
	}
	for(int i=1;i<=n;++i){
		if(sum[belong[i]]>1) printf("Infinity\n");
		else printf("%lld\n",ans[belong[i]]);
	}
	return  0;
}
