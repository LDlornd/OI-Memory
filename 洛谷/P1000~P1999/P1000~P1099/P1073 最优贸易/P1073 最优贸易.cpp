#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
const int INF=1000;
const int MAXN=1e5+5;
int n,m,u,v,k,ans=0;
int val[MAXN],newval[2][MAXN],dp[2][MAXN];
int tmpdfn=0,dfn[MAXN],low[MAXN];
int cnt=0,belong[MAXN];
int indu[MAXN],Queue[MAXN],head,tail;
int Stack[MAXN],top;
bool vis[MAXN],flag[3][MAXN];
struct edge{
    int v;
    edge *nex;
    edge() {v=0;nex=NULL;}
}*con[MAXN],*newcon[MAXN];
void ins(int Start,int End,edge *a[]){
    edge *p=new(edge);
    p->v=End;
    p->nex=a[Start];a[Start]=p;
}
void addedge(int Start,int End,edge *a[]){
    ins(Start,End,a);ins(End,Start,a);
}
void tarjan(int nv){
    dfn[nv]=low[nv]=++tmpdfn;
    Stack[++top]=nv;vis[nv]=true;
    for(edge *p=con[nv];p;p=p->nex){
        if(dfn[p->v]==0){
            tarjan(p->v);
            low[nv]=min(low[nv],low[p->v]);
        }
        else if(vis[p->v]) low[nv]=min(low[nv],dfn[p->v]);
    }
    if(low[nv]==dfn[nv]){
        ++cnt;
        newval[0][cnt]=newval[1][cnt]=val[nv];
        while(Stack[top+1]!=nv){
            int place=Stack[top--];
            newval[0][cnt]=min(newval[0][cnt],val[place]);
            newval[1][cnt]=max(newval[1][cnt],val[place]);
            vis[place]=false;
            belong[place]=cnt;
        }
    }
}
void rebuild(){
    for(int i=1;i<=n;++i){
        for(edge *p=con[i];p;p=p->nex){
            if(belong[i]!=belong[p->v]){
                ins(belong[i],belong[p->v],newcon);
				++indu[belong[p->v]];
            }
        }
    }
}
void top_sort(){
    head=1;tail=0;
    for(int i=1;i<=cnt;++i) if(indu[i]==0) Queue[++tail]=i;
    while(head!=tail+1){
        int nv=Queue[head++];
        for(edge *p=newcon[nv];p;p=p->nex){
            if(--indu[p->v]==0) Queue[++tail]=p->v;
        }
    }
}
void dfs(int nv){
	vis[nv]=true;flag[1][nv]=true;
	if(nv!=belong[n]){
		for(edge *p=newcon[nv];p;p=p->nex){
			if(vis[p->v]==false) dfs(p->v);
			flag[2][nv]=flag[2][nv]|flag[2][p->v];
		}
	}
	flag[0][nv]=flag[1][nv]&flag[2][nv];
	dp[0][nv]=flag[0][nv]?newval[0][nv]:INF;
	dp[1][nv]=flag[0][nv]?newval[1][nv]:-INF;
}
int read(){
    int x=0,f=1;char c=getchar();
    for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
    for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
    return x*f;
}
int main(){
    n=read();m=read();
    for(int i=1;i<=n;++i) val[i]=read();
    while(m--){
        u=read();v=read();k=read();
        if(k==1) ins(u,v,con);
        else addedge(v,u,con);
    }
    for(int i=1;i<=n;++i)
        if(dfn[i]==0) tarjan(i);
    rebuild();top_sort();
    memset(vis,0,sizeof(vis));
    flag[2][belong[n]]=true;
    dfs(belong[1]);
    for(int i=1;i<=cnt;++i){
    	int nv=Queue[i];
    	if(flag[0][nv]==false) continue;
    	for(edge *p=newcon[nv];p;p=p->nex)
    		dp[0][p->v]=min(dp[0][p->v],dp[0][nv]);
	}
	for(int i=cnt;i>=cnt;--i){
    	int nv=Queue[i];
    	if(flag[0][nv]==false) continue;
    	for(edge *p=newcon[nv];p;p=p->nex)
    		dp[1][nv]=max(dp[1][nv],dp[1][p->v]);
	}
    for(int i=1;i<=cnt;++i)
        ans=max(ans,dp[1][i]-dp[0][i]);
    printf("%d",ans);
    return 0;
}
