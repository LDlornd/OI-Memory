#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN=105;
int n,m,u,v,l,q;
int dfn[MAXN];
bool flag[MAXN][MAXN];
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
bool dfs(int nv,int cnt){
	if(cnt==l){
		if(nv==v) return true;
		else return false;
	}
	if(flag[nv][v]==false) return false;
	for(edge *p=con[nv];p;p=p->nex){
		if(dfs(p->v,cnt+1)) return true;
	}
	return false;
}
int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	freopen("cave.in","r",stdin);
	freopen("tle.out","w",stdout);
	n=read();m=read();
	while(m--){
		u=read();v=read();
		ins(u,v);
		flag[u][v]=true;
	}
	for(int i=1;i<=n;++i) flag[i][i]=true;
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				flag[i][j]=flag[i][j]||(flag[i][k]&&flag[k][j]);
	q=read();
	while(q--){
		l=read();u=read();v=read();
		if(dfs(u,0)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
