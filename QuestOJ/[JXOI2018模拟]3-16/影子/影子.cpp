#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
typedef long long int ll;
const int MAXN=10001;
int T,n,u,v,key;
int w[MAXN],Log[MAXN],depth[MAXN];
int fa[MAXN][17],minw[MAXN][17];
ll dist[MAXN][17];
bool vis[MAXN];
struct edge{
	int v,val;
	edge *Next;
	edge() {v=val=0;Next=NULL;}
}*con[MAXN];
inline void ins(int Start,int End,int len){
	edge *p=new(edge);
	p->v=End;
	p->val=len;
	p->Next=con[Start];
	con[Start]=p;
}
inline void gettree(int nv,int deep){
	vis[nv]=true;depth[nv]=deep;
	for(edge *p=con[nv];p;p=p->Next){
		int vv=p->v,nlen=p->val;
		if(vis[vv]==false){
			fa[vv][0]=nv;
			dist[vv][0]=nlen;
			minw[vv][0]=min(w[nv],w[nv]);
			gettree(vv,deep+1);
		}
	}
}
inline ll lca(int a,int b){
	int MINW=2147483647,Dist=0;
	if(depth[a]<depth[b]) swap(a,b);
	while(depth[a]>depth[b]){
		int temp=Log[depth[a]-depth[b]];
		MINW=min(MINW,minw[a][temp]);
		Dist+=dist[a][temp];
		a=fa[a][temp];
	}
	if(a==b) return MINW*Dist;
	for(int i=Log[depth[a]]+1;i>=0;--i){
		if(fa[a][i]==fa[b][i]) continue;
		MINW=min(MINW,min(minw[a][i],minw[b][i]));
		Dist+=(dist[a][i]+dist[b][i]);
		a=fa[a][i];b=fa[b][i];
	}
	MINW=min(MINW,min(minw[a][0],minw[b][0]));
	Dist+=(dist[a][0]+dist[b][0]);
	return MINW*Dist;
}
int main(){
	ios::sync_with_stdio(false);
	Log[1]=0;
	for(int i=2;i<MAXN;++i) Log[i]=Log[i-1]+(1<<(Log[i-1]+1)==i);
	cin>>T;
	while(T--){
		memset(con,0,sizeof(con));
		cin>>n;
		for(int i=1;i<=n;++i) cin>>w[i];
		for(int i=1;i<n;++i){
			cin>>u>>v>>key;
			ins(u,v,key);ins(v,u,key);
		}
		cout<<"fuck";
		for(int i=1;i<=n;++i)
			for(int j=0;j<17;++j)
				minw[i][j]=200000;
		cout<<"fuck"<<endl;
		fa[1][0]=dist[1][0]=0;
		minw[1][0]=w[1];
		gettree(1,0);
		cout<<"fuck"<<endl;
		//for(int i=1;i<=n;++i) cout<<fa[i][0]<<" "<<minw[i][0]<<" "<<dist[i][0]<<endl;
		for(int i=1;i<=n;++i){
			for(int j=1;j<17;++j){
				if(fa[i][j-1]==0) break;
				fa[i][j]=fa[fa[i][j-1]][j-1];
				minw[i][j]=min(minw[i][j-1],minw[fa[i][j-1]][j-1]);
				dist[i][j]=dist[i][j-1]+dist[fa[i][j-1]][j-1];
			}
		}
		/*for(int i=1;i<=n;++i){
			for(int j=0;j<=17;++j){
				cout<<i<<" "<<j<<" "<<fa[i][j]<<" "<<minw[i][j]<<" "<<dist[i][j]<<endl;
				if(fa[i][j]==0) break;
			}
		}*/
		//for(int i=1;i<=n;++i) cout<<depth[i]<<" ";
		ll ans=0;
		for(int i=1;i<=n;++i)
			for(int j=i+1;j<=n;++j)
				//ans=max(ans,lca(i,j));
				ans=1;
		cout<<ans;
	}
	return 0;
}
