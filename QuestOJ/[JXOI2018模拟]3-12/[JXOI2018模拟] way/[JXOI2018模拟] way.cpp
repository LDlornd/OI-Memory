#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long int ll;
const int MAXN=5001;
const int MAXN2=1e5+1;
struct que{
	int Root,Limit,ID;
	que() {Root=Limit=ID=0;}
}Q[MAXN2];
struct edge{
	int v;
	edge *Next;
	edge() {v=0;Next=NULL;}
}*con[MAXN],*root[MAXN];
int n,q,u,v;
int res[MAXN],tot;
ll W[MAXN],A[MAXN];
ll dp[MAXN],ans[MAXN2];
bool flag=true,vis[MAXN];
inline void ins(int Start,int End,edge *a[]){
	edge *p=new(edge);
	p->v=End;
	p->Next=a[Start];
	a[Start]=p;
}
inline void getready(int nowroot){
	vis[nowroot]=true;
	for(edge *p=con[nowroot];p;p=p->Next){
		int nv=p->v;
		if(vis[nv]==false){
			ins(nowroot,nv,root);
			getready(nv);
		}
	}
}
inline void dfs(int nv){
	res[++tot]=nv;
	for(edge *p=root[nv];p;p=p->Next)
		dfs(p->v);
}
inline bool CMP(const que &a,const que &b){
	if(a.Root==b.Root) return a.Limit>b.Limit;
	return a.Root<b.Root;
}
int main(){
	ios::sync_with_stdio(false);
	memset(vis,0,sizeof(vis));
	cin>>n;
	for(int i=1;i<n;++i){
		cin>>u>>v;
		if(u!=v+1&&v!=u+1) flag=false;
		ins(u,v,con);ins(v,u,con);
	}
	for(int i=1;i<=n;++i) cin>>W[i]>>A[i];
	getready(1);
	cin>>q;
	for(int i=1;i<=q;++i){
		cin>>Q[i].Root>>Q[i].Limit;
		Q[i].ID=i;
	}
	sort(Q+1,Q+q+1,CMP);
	for(int w=1;w<=q;++w){
		tot=0;
		dfs(Q[w].Root);
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=tot;++i){
			int now=res[i];
			for(int k=Q[w].Limit;k>=A[now];--k)
				dp[k]=max(dp[k],dp[k-A[now]]+W[now]);
		}
		int j;
		for(j=w;j<=q;++j){
			if(Q[j].Root==Q[w].Root) ans[Q[j].ID]=dp[Q[j].Limit];
			else break;
		}
		w=j-1;
	}
	for(int i=1;i<=q;++i) cout<<ans[i]<<endl;
	return 0;
}
