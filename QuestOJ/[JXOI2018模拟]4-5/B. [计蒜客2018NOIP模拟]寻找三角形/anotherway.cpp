#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN=100001;
int n,m,u,v,visit=0,tot=0;
int ans1,ans2,ans3;
int fa[MAXN];
int No[MAXN];
bool vis[MAXN];
struct edge{
	int v;
	edge *Next;
	edge() {v=0;Next=NULL;}
}*con[MAXN],*newcon[MAXN];
inline void ins(int Start,int End,edge *a[]){
	edge *p=new(edge);
	p->v=End;
	p->Next=a[Start];
	a[Start]=p;
}
inline void rebuild(int nv,int last){
	No[nv]=++visit;
	for(edge *p=con[nv];p;p=p->Next){
		int vv=p->v;
		if(vv!=last&&No[vv]<No[nv]) ins(nv,vv,newcon);
		if(No[vv]==0) rebuild(vv,nv);
	}
}
inline bool judge(int Start,int End){
	if(fa[fa[Start]]==End) return true;
	else return false;
}
inline bool dfs(int nv,int last){
	bool flag=false;
	vis[nv]=true;fa[nv]=last;
	for(edge *p=newcon[nv];p;p=p->Next){
		int vv=p->v;
		if(vis[vv]==false) flag=dfs(vv,nv);
		else if(judge(nv,vv)){
			ans1=nv;ans2=vv;ans3=fa[nv];
			return true;
		}
		if(flag) return true;
	}
	return false;
}
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read();m=read();
	while(m--){
		u=read();v=read();
		ins(u,v,con);ins(v,u,con);
	}
	for(int i=1;i<=n;++i)
		if(No[i]==0) rebuild(i,0);
	for(int i=1;i<=n;++i)
		if(vis[i]==false) dfs(i,0);
	if(ans1>ans2) swap(ans1,ans2);
	if(ans1>ans3) swap(ans1,ans3);
	if(ans2>ans3) swap(ans2,ans3);
	printf("%d %d %d",ans1,ans2,ans3);
	return 0;
}
