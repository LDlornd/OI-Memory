#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN=5005;
int n,m,u,v,ans,cnt;
int dfn[MAXN],res[MAXN];
bool vis[MAXN];
struct Queue{
	int v,fa;
}q[MAXN];
struct edge{
	int v;
	edge *nex;
	edge() {v=0;nex=NULL;}
}*con[MAXN<<1];
void ins(int Start,int End){
	edge *p=new(edge);
	p->v=End;
	p->nex=con[Start];con[Start]=p;
}
void bfs(int key){
	memset(dfn,0,sizeof(dfn));
	int head=1,tail=1;
	q[1].fa=0;q[1].v=key;
	while(head-1!=tail){
		bool flag=false;
		int nv=q[head].v,nfa=q[head].fa;
		for(edge *p=con[nv];p;p=p->nex){
			if(p->v==nfa) continue;
			dfn[p->v]=dfn[nv]+1;
			q[++tail].v=p->v;
			q[tail].fa=head;
			if(p->v==key){
				if(dfn[key]<ans){
					ans=dfn[key];cnt=0;
					int now=nv;
					while(q[now].v!=key){
						res[++cnt]=q[now].v;
						now=q[now].fa;
					}
					res[++cnt]=q[now].v;
					flag=true;
				}
			}
		}
		++head;
		if(flag) break;
	}
}
void getready(){
	memset(con,0,sizeof(con));
	memset(vis,0,sizeof(vis));
}
int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	read();
	while(scanf("%d%d",&n,&m)!=EOF){
		if(n==0) break;
		getready();
		while(m--){
			u=read();v=read();
			ins((u<<1)-1,v<<1);ins(v<<1,(u<<1)-1);
		}
		ans=MAXN;
		for(int i=1;i<=n;++i)
			if(vis[i]==false) bfs(i);
		if(ans==MAXN) ans=-1;
		printf("%d\n",ans);
		for(int i=1;i<=cnt;++i) printf("%d ",res[i]);
		printf("\n");
	}
	return 0;
}
