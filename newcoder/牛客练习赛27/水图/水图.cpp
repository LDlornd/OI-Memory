#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
typedef long long int ll;
const int MAXN=50005;
int n,u,v,now;
ll w,ans,maxdepth=0;
struct edge{
	int v;
	ll val;
	edge *nex;
	edge() {v=val=0;nex=NULL;}
}*con[MAXN];
void ins(int Start,int End,ll key){
	edge *p=new(edge);
	p->v=End;p->val=key;
	p->nex=con[Start];con[Start]=p;
}
void dfs(int nv,int father,ll cnt){
	bool flag=false;
	for(edge *p=con[nv];p;p=p->nex){
		if(p->v==father) continue;
		flag=true;ans+=p->val;
		dfs(p->v,nv,cnt+p->val);
	}
	if(flag==false)
		maxdepth=max(maxdepth,cnt);
}
template<typename T>
T read(){
	T x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read<int>();now=read<int>();
	for(int i=1;i<n;++i){
		u=read<int>();v=read<int>();w=read<ll>();
		ins(u,v,w);ins(v,u,w);
	}
	dfs(now,0,0);
	printf("%lld",(ans<<1)-maxdepth);
	return 0;
}
