#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
int n,m,k,u,v,visit=0;
int first[MAXN],last[MAXN],arr[MAXN<<1];
int ans[MAXN],tot=0;
struct node{
	int Left,Right;
	node() {Left=Right=0;}
}data[MAXN*3];
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
void dfs(int nv){
	arr[++visit]=nv;
	first[nv]=visit;
	last[nv]=visit;
	for(edge *p=con[nv];p;p=p->nex){
		dfs(p->v);
		arr[++visit]=nv;
		last[nv]=visit;
	}
}
bool CMP(const node &a,const node &b){
	if(a.Left==b.Left) return a.Right>b.Right;
	else return a.Left<b.Left;
}
int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	freopen("ping.in","r",stdin);
	n=read();m=read();
	while(m--){
		u=read();v=read();
		if(v<u) swap(u,v);
		ins(u,v);
	}
	dfs(1);
//	for(int i=1;i<=visit;++i) cout<<arr[i]<<" ";cout<<endl;
//	for(int i=1;i<=n;++i) cout<<first[i]<<" ";cout<<endl;
//	for(int i=1;i<=n;++i) cout<<last[i]<<" ";cout<<endl;
	k=read();
	for(int i=1;i<=k;++i){
		data[i].Left=first[read()];data[i].Right=last[read()];
		if(data[i].Left>data[i].Right) swap(data[i].Left,data[i].Right);
	}
	sort(data+1,data+k+1,CMP);
//	for(int i=1;i<=k;++i){
//		cout<<data[i].Left<<" "<<data[i].Right<<endl;
//	}
	int now=0;
	for(int i=1;i<=k;++i){
		if(data[i].Left<now) continue;
		ans[++tot]=arr[data[i].Right];
		now=data[i].Right;
	}
	printf("%d\n",tot);
	for(int i=1;i<=tot;++i) printf("%d ",ans[i]);
	return 0;
}
