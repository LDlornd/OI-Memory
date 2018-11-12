#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
const int MAXN=105;
int n,m,u,v,k;
int indu[MAXN],outdu[MAXN];
int Queue[MAXN],head,tail;
bool flag=false;
struct node{
	int c,u;
	node() {c=u=0;}
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
void top_sort(){
	head=1;tail=0;
	for(int i=1;i<=n;++i) if(indu[i]==0){
		Queue[++tail]=i;arr[i].u=0;
	}
	while(head!=tail+1){
		int nv=Queue[head++];
		for(edge *p=con[nv];p;p=p->nex)
			if(--indu[p->v]==0) Queue[++tail]=p->v;
	}
}
void dfs(){
	for(int i=1;i<=n;++i){
		int nv=Queue[i];
		arr[nv].c-=arr[nv].u;
		if(arr[nv].c<=0) continue;
		for(edge *p=con[nv];p;p=p->nex){
			arr[p->v].c+=arr[nv].c*p->val;
		}
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
	for(int i=1;i<=n;++i){
		arr[i].c=read();arr[i].u=read();
	}
	while(m--){
		u=read();v=read();k=read();
		ins(u,v,k);
		++indu[v];++outdu[u];
	}
	top_sort();
	dfs();
	for(int i=1;i<=n;++i){
		if(outdu[i]!=0||arr[i].c<=0) continue;
		flag=true;
		printf("%d %d\n",i,arr[i].c);
	}
	if(flag==false) printf("NULL");
	return 0;
}
