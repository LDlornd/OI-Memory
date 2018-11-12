#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN=25;
int n,k,ans=0,place;
int arr[MAXN],dp[MAXN],fa[MAXN];
int indu[MAXN];
int Queue[MAXN],head,tail;
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
	head=1;tail=0;
	for(int i=1;i<=n;++i) if(indu[i]==0) Queue[++tail]=i;
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
	n=read();
	for(int i=1;i<=n;++i) arr[i]=read();
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			k=read();
			if(k==1) ins(i,j);
		}
	}
	top_sort();
	for(int i=n;i;--i){
		int nv=Queue[i];
		dp[nv]=arr[nv];fa[nv]=0;
		for(edge *p=con[nv];p;p=p->nex){
			if(dp[nv]>dp[p->v]+arr[nv]) continue;
			dp[nv]=max(dp[nv],dp[p->v]+arr[nv]);
			fa[nv]=p->v;
		}
	}
	for(int i=1;i<=n;++i){
		if(ans>dp[i]) continue;
		ans=dp[i];
		place=i;
	}
	for(;place;place=fa[place]) printf("%d ",place);
	printf("\n%d",ans);
	return 0;
}
