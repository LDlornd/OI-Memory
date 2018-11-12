#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN=100001;
int n,s,u,v,tot=0,ans=0;
int val[MAXN];
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
inline void dfs(int nv){
	tot+=val[nv];
	if(tot==s){++ans;return;}
	if(tot>s) return;
	for(edge *p=con[nv];p;p=p->Next){
		int vv=p->v;
		dfs(vv);
		tot-=val[vv];
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>s;
	for(int i=1;i<=n;++i) cin>>val[i];
	for(int i=1;i<n;++i){
		cin>>u>>v;
		ins(u,v);
	}
	for(int i=1;i<=n;++i)
		{tot=0;dfs(i);}
	cout<<ans;
	return 0;
}
