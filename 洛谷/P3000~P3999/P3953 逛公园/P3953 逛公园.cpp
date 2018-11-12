#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
typedef long long int ll;
const int MAXN=100005;
const ll INF=0x3f3f3f3f3f3f3f3f;
int T,n,m,k,mod,u,v;
ll l;
ll dist[MAXN],dp[MAXN][55];
int Queue[MAXN],head,tail;
bool vis[MAXN],flag[MAXN][55];
struct edge{
	int v;
	ll len;
	edge *nex;
	edge() {v=len=0;nex=NULL;}
}*con[MAXN],*gra[MAXN];
void ins(int Start,int End,ll key,edge *a[]){
	edge *p=new(edge);
	p->v=End;p->len=key;
	p->nex=a[Start];a[Start]=p;
}
void spfa(){
	for(int i=1;i<n;++i) dist[i]=INF;
	Queue[head=tail=1]=n;vis[n]=true;
	while(head<=tail){
		int nv=Queue[head%MAXN];
		for(edge *p=gra[nv];p;p=p->nex){
			if(dist[p->v]>dist[nv]+p->len){
				dist[p->v]=dist[nv]+p->len;
				if(vis[p->v]==false){
					++tail;vis[p->v]=true;
					Queue[tail%MAXN]=p->v;
				}
			}
		}
		++head;vis[nv]=false;
	}
}
ll dfs(int nv,int limit){
	//cout<<nv<<" "<<limit<<"fuck"<<endl;
	if(flag[nv][limit]) return -1;
	if(dp[nv][limit]) return dp[nv][limit];
	flag[nv][limit]=true;
	if(nv==n) dp[nv][limit]=1;
	for(edge *p=con[nv];p;p=p->nex){
		//cout<<nv<<" "<<p->v<<" "<<dist[nv]<<" "<<dist[p->v]<<" "<<p->len<<endl;
		if(dist[nv]+limit>=dist[p->v]+p->len){
			ll tmp=dfs(p->v,limit+dist[nv]-dist[p->v]-p->len);
			if(tmp==-1) return dp[nv][limit]=-1;
			dp[nv][limit]=(dp[nv][limit]+tmp)%mod;
		}
	}
	flag[nv][limit]=false;
	return dp[nv][limit];
}
void init(){
	memset(con,0,sizeof(con));
	memset(gra,0,sizeof(gra));
	memset(flag,0,sizeof(flag));
	memset(vis,0,sizeof(vis));
	memset(dp,0,sizeof(dp));
}
template<typename T>
T read(){
	T x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	freopen("testdata (2).in","r",stdin);
	T=read<int>();
	while(T--){
		init();
		n=read<int>();m=read<int>();k=read<int>();mod=read<int>();
		while(m--){
			u=read<int>();v=read<int>();l=read<ll>();
			ins(u,v,l,con);ins(v,u,l,gra);
		}
		spfa();
//		for(int i=1;i<=n;++i) cout<<dist[i]<<" ";cout<<endl;
		printf("%lld\n",dfs(1,k));
//		for(int i=1;i<=n;++i){
//			for(int j=0;j<=k;++j)
//				cout<<dp[i][j]<<" ";
//			cout<<endl;
//		}
	}
	return 0;
}
