#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
typedef unsigned long long int ull;
const int MAXN=505;
int n,m,u,v,casenum=0,visit,top;
int dfn[MAXN],low[MAXN],num[MAXN];
int root[MAXN],rootcnt;
int num1,num2,ans;
ull cnt;
bool vis[MAXN],used[MAXN];
struct node{
	int Left,Right;
	node(int ll=0,int rr=0) {Left=ll;Right=rr;}
	bool cmp(node &a){
		return (Left==a.Left&&Right==a.Right)||(Left==a.Right&&Right==a.Left);
	}
}Stack[MAXN];
struct edge{
	int v;
	bool flag;
	edge *nex,*rev;
	edge() {v=0;flag=false;nex=rev=NULL;}
}*con[MAXN];
void ins(int Start,int End){
	edge *p=new(edge);
	p->v=End;
	p->nex=con[Start];con[Start]=p;
}
void add(int Start,int End){
	ins(Start,End);ins(End,Start);
	con[Start]->rev=con[End];
	con[End]->rev=con[Start];
}
void tarjan(int nv,int father){
	dfn[nv]=low[nv]=(++visit);
	for(edge *p=con[nv];p;p=p->nex){
		if(dfn[p->v]==0){
			tarjan(p->v,nv);
			if(low[p->v]>=dfn[nv]) ++num[nv];
			low[nv]=min(low[nv],low[p->v]);
		}
		else if(p->v!=father) low[nv]=min(low[nv],dfn[p->v]);
	}
}
void deal(int key){
	if(used[key]) return;
	used[key]=true;
	if(num[key]) ++num2;
	else ++num1;
}
void dfs(int nv){
	vis[nv]=true;
	for(edge *p=con[nv];p;p=p->nex){
		if(p->flag) continue;
		p->rev->flag=p->flag=true;
		node tmp=node(nv,p->v);
		Stack[++top]=tmp;
		if(vis[p->v]==false){
			dfs(p->v);
			if(low[p->v]>=dfn[nv]){
				memset(used,0,sizeof(used));
				while(top>0){
					node k=Stack[top--];
					deal(k.Left);deal(k.Right);
					if(k.cmp(tmp)) break;
				}
				if(num2>=2) ans+=0;
				else if(num2==1) {++ans;cnt*=num1;}
				else {ans+=2;cnt*=(num1*(num1-1)/2);}
				num1=num2=0;
			}
		}
	}
}
void Init(){
	memset(con,0,sizeof(con));
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(vis,0,sizeof(vis));
	rootcnt=visit=top=n=0;
	ans=0;cnt=1;
}
int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	while((m=read())!=0){
		Init();
		while(m--){
			u=read();v=read();
			add(u,v);
			n=max(n,max(u,v));
		}
		for(int i=1;i<=n;++i){
			if(dfn[i]==0){
				root[++rootcnt]=i;
				tarjan(i,0);
				if(num[i]!=0) --num[i];
			}
		}
		for(int i=1;i<=n;++i){
			if(vis[i]==false){
				num1=0;num2=0;
				dfs(root[i]);
			}
		}
		printf("Case %d: %d %llu\n",++casenum,ans,cnt);
	}
	return 0;
}
