#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
typedef long long int ll;
const int MAXN=1e5+5;
ll ans=0;
int n,m,u,v,k;
int Left[MAXN],Right[MAXN];
int lg[MAXN];
int depth[MAXN],fa[18][MAXN];
ll dist[18][MAXN];
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
void get_tree(int nv,int father,int key){
	depth[nv]=depth[father]+1;
	fa[0][nv]=father;dist[0][nv]=(ll)key;
	for(edge *p=con[nv];p;p=p->nex)
		if(p->v==father) continue;
		else get_tree(p->v,nv,p->val);
}
void getready(){
	for(int i=2;i<=n;++i) lg[i]=lg[i>>1]+1;
	get_tree(1,0,0);
	for(int i=1;i<18;++i)
		for(int j=1;j<=n;++j){
			fa[i][j]=fa[i-1][fa[i-1][j]];
			dist[i][j]=dist[i-1][j]+dist[i-1][fa[i-1][j]];
		}
}
ll get_dist(int l,int r){
	ll temp=0;
	if(depth[l]<depth[r]) swap(l,r);
	while(depth[l]>depth[r]){
		temp+=dist[lg[depth[l]-depth[r]]][l];
		l=fa[lg[depth[l]-depth[r]]][l];
	}
	if(l==r) return temp;
	for(int i=17;i>=0;--i){
		if(fa[i][l]!=fa[i][r]){
			temp+=(dist[i][l]+dist[i][r]);
			l=fa[i][l];r=fa[i][r];
		}
	}
	temp+=(dist[0][l]+dist[0][r]);
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
	for(int i=1;i<n;++i){
		u=read();v=read();k=read();
		ins(u,v,k);ins(v,u,k);
	}
	getready();
	for(int i=1;i<=m;++i)
		{Left[i]=read();Right[i]=read();}
	for(int i=1;i<=n;++i){
		ll tmp=0;
		for(int j=1;j<=m;++j)
			tmp+=get_dist(Left[j],i)+get_dist(Right[j],i);
		ans=(i==1)?tmp:min(ans,tmp);
	}
	printf("%lld",ans);
	return 0;
}
