#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN=100005;
int n,m,u,v;
int indu[MAXN],dp[MAXN];
int Queue[MAXN],head=1,tail=0;
struct edge{
	int v;
	edge *nex;
	edge() {v=0;nex=NULL;}
}*con[MAXN];
void ins(int Start,int End){
	edge *p=new(edge);
	p->v=End;
	p->nex=con[Start];con[Start]=p;
	++indu[End];
}
void top_sort(){
	for(int i=1;i<=n;++i)
		if(indu[i]==0) {dp[i]=1;Queue[++tail]=i;}
	while(head!=tail+1){
		int nv=Queue[head++];
		for(edge *p=con[nv];p;p=p->nex)
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
	n=read();m=read();
	while(m--){
		u=read();v=read();
		ins(u,v);
	}
	top_sort();
	for(int i=1;i<=n;++i){
		int nv=Queue[i];
		for(edge *p=con[nv];p;p=p->nex)
			dp[p->v]=max(dp[p->v],dp[nv]+1);
	}
	for(int i=1;i<=n;++i)
		printf("%d\n",dp[i]);
	return 0;
}
