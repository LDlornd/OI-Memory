#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
const int INF=2147483647;
const int MAXN=100001;
int n,m,A,B,k,ans=0;
int dist[MAXN],rudu[MAXN],tot[MAXN];
int Queue[MAXN],head,tail;
bool vis[MAXN],flag1=true,flag2=false;
struct edge{
	int v,val;
	edge *nex;
	edge() {v=val=0;nex=NULL;}
}*con[MAXN];
inline void ins(int Start,int End,int key){
	edge *p=new(edge);
	p->v=End;p->val=key;
	p->nex=con[Start];con[Start]=p;
	++rudu[End];
}
inline void spfa(int key){
	for(int i=0;i<=n;++i) dist[i]=-INF;
	dist[key]=0;tot[key]=1;
	Queue[head=tail=1]=key;vis[key]=true;
	while((head-1)!=tail%(MAXN-1)){
		int nv=Queue[head];
		//cout<<nv<<" ";
		//system("pause");
		for(edge *p=con[nv];p;p=p->nex){
			int vv=p->v;
			if(dist[vv]<dist[nv]+p->val){
				dist[vv]=dist[nv]+p->val;
				if(vv==n) continue;
				if(vis[vv]==false){
					tail=(tail==MAXN-1)?1:(tail+1);
					Queue[tail]=vv;
					vis[vv]=true;++tot[vv];
					if(tot[vv]>rudu[vv]){
						flag1=false;
						return;
					}
				}
				//cout<<" "<<vv<<"="<<dist[vv]<<" ";
			}
		}
		//cout<<endl;
		//system("pause");
		head=(head==MAXN-1)?1:(head+1);
		vis[nv]=false;
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
		k=read();A=read();B=read();
		if(k==1) {ins(A,B,0);ins(B,A,0);}
		if(k==2) ins(A,B,1);
		if(k==3) ins(B,A,0);
		if(k==4) ins(B,A,1);
		if(k==5) ins(A,B,0);
	}
	for(int i=1;i<=n;++i)
		if(rudu[i]==0) ins(0,i,0);
	spfa(0);
//	for(int i=1;i<=n;++i)
//		printf("%d ",dist[i]);
	if(flag1==false) ans=-1;
	else{
		for(int i=1;i<=n;++i){
			ans+=dist[i];
			if(dist[i]==0) flag2=true;
		}
		if(flag2) ans+=n;
	}
	printf("%d",ans);
	return 0;
}
