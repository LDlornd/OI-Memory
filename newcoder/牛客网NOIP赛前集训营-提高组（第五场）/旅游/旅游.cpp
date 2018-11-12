#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
typedef long long int ll;
const int mod=998244353;
const int MAXN=5e5+5;
ll ans=0;
int n,m,u,v;
int du[MAXN];
int res[MAXN],cnt=0;
int fa[MAXN],Size[MAXN];
struct node{
	int Left,Right,val;
	node(int ll=0,int rr=0,int vv=0) {Left=ll;Right=rr;val=vv;}
}arr[MAXN];
struct edge{
	int v,val;
	edge *nex;
	edge() {v=val=0;nex=NULL;}
}*con[MAXN];
void ins(int Start,int End,int key){
	edge *p=new(edge);
	p->v=End;p->val=key;
	p->nex=con[Start];con[Start]=p;
}
int getfa(int a){
	if(fa[a]==a) return a;
	else return fa[a]=getfa(fa[a]);
}
void Merge(int a,int b){
	a=getfa(a);b=getfa(b);
	if(Size[a]<Size[b]) swap(a,b);
	fa[b]=a;Size[a]+=Size[b];
}
void kruskal(){
	int tot=1;
	for(int i=1;i<=n;++i) {fa[i]=i;Size[i]=1;}
	for(int i=1;i<=m&&tot!=n;++i){
		if(getfa(arr[i].Left)==getfa(arr[i].Right)) continue;
		Merge(arr[i].Left,arr[i].Right);
		++tot;
		ins(arr[i].Left,arr[i].Right,arr[i].val);
		ins(arr[i].Right,arr[i].Left,arr[i].val);
	}
}
void dfs(int nv,int father){
	int temp;
	for(edge *p=con[nv];p;p=p->nex){
		if(p->v==father) {temp=p->val;continue;}
		dfs(p->v,nv);
	}
	if(du[nv]&1){
		++du[nv];++du[father];
		res[++cnt]=temp;
	}
}
ll quick_mi(ll base,ll index){
	ll temp=1;
	while(index){
		if(index&1) temp=temp*base%mod;
		base=base*base%mod;
		index>>=1;
	}
	return temp;
}
int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read();m=read();
	for(int i=1;i<=m;++i){
		u=read();v=read();
		++du[u];++du[v];
		arr[i]=node(u,v,i);
		ans=(ans+quick_mi(2,i));
	}
	kruskal();
	dfs(1,0);
	for(int i=1;i<=cnt;++i)
		ans=(ans+quick_mi(2,res[i]))%mod;
	printf("%lld",ans);
	return 0;
}
