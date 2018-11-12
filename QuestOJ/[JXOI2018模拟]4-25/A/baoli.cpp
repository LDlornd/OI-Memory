#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long int ll;
const int MAXN=2501;
const int mod=1e9+7;
ll ans=0;
int n,m,T,u,v,l;
int dist[MAXN],num[MAXN],Size[MAXN];
int Queue[MAXN<<3],head,tail;
bool inq[MAXN];
struct edge{
	int v,len;
	edge *nex;
	edge() {v=len=0;nex=NULL;}
}*con[MAXN];
inline void ins(int Start,int End,int key){
	edge *p=new(edge);
	p->v=End;p->len=key;
	p->nex=con[Start];con[Start]=p;
	p=new(edge);
	p->v=Start;p->len=key;
	p->nex=con[End];con[End]=p;
}
inline void spfa(int key){
	for(int i=2;i<=n;++i) dist[i]=2147483647;
	dist[1]=num[1]=0;inq[1]=true;
	Queue[head=tail=1]=1;
	while(head<=tail){
		int nv=Queue[head++];
		for(edge *p=con[nv];p;p=p->nex){
			int vv=p->v;
			if(dist[vv]>dist[nv]+p->len+key){
				dist[vv]=dist[nv]+p->len+key;
				num[vv]=num[nv]+1;
				++Size[vv];
				if(inq[vv]==false){
					Queue[++tail]=vv;
					inq[vv]=true;
				}
			}
		}
		inq[nv]=false;
	}
}
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	freopen("testdata.in","r",stdin);
	freopen("baoli.out","w",stdout);
	n=read();m=read();T=read();
	while(m--){
		u=read();v=read();l=read();
		ins(u,v,l);
	}
	for(int i=0;i<=T;++i){
		spfa(i);
		for(int i=1;i<=n;++i) (ans+=dist[i])%=mod;
	}
	printf("%lld",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}
