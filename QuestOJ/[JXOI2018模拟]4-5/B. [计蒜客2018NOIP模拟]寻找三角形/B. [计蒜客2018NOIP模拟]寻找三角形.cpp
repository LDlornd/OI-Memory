#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN=100001;
int n,m,u,v,visit=0,tot=0;
int ans1,ans2,ans3;
int dfn[MAXN],low[MAXN],belong[MAXN],sum[MAXN];
int Stack[MAXN],top=0;
int No[MAXN];
bool instack[MAXN];
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
inline void tarjan(int nv){
	int place;
	dfn[nv]=low[nv]=++visit;
	Stack[++top]=nv;instack[nv]=true;
	for(edge *p=newcon[nv];p;p=p->Next){
		int vv=p->v;
		if(dfn[vv]==0){
			tarjan(vv);
			low[nv]=min(low[nv],low[vv]);
		}
		else if(instack[vv]) low[nv]=min(low[nv],dfn[vv]);
	}
	if(dfn[nv]==low[nv]){
		++tot;
		do{
			place=Stack[top--];
			instack[place]=false;
			belong[place]=tot;
			++sum[tot];
		}while(place!=nv);
	}
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
	visit=0;
	for(int i=1;i<=n;++i)
		if(dfn[i]==0) tarjan(i);
	for(int i=1;i<=n;++i){
		printf("%d sons: ",i);
		for(edge *p=newcon[i];p;p=p->Next) cout<<p->v<<" ";cout<<endl;
	}
	cout<<"dfn: ";for(int i=1;i<=n;++i) cout<<dfn[i]<<" ";cout<<endl;
	cout<<"low: ";for(int i=1;i<=n;++i) cout<<low[i]<<" ";cout<<endl;
	cout<<"bel: ";for(int i=1;i<=n;++i) cout<<belong[dfn[i]]<<" ";cout<<endl;
	cout<<tot<<endl;
	for(int i=1;i<=tot;++i) cout<<sum[i]<<" ";cout<<endl;
	return 0;
}
