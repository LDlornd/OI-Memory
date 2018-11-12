#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<bitset>
using namespace std;
const int MAXN=1005;
int n,m,q,u,v,cnt,place,len;
int dist[MAXN];
int Queue[MAXN],head,tail;
bool link[MAXN][MAXN];
bitset<MAXN> dp[MAXN][MAXN],can;
struct edge{
	int v;
	edge *nex;
	edge() {v=0;nex=NULL;}
}*con[MAXN];
void ins(int Start,int End){
	edge *p=new(edge);
	p->v=End;
	p->nex=con[Start];con[Start]=p;
	link[Start][End]=true;
}
int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	freopen("center.in","r",stdin);
	freopen("center.out","w",stdout);
	n=read();m=read();q=read();
	while(m--){
		u=read();v=read();
		if(link[u][v]||u==v) continue;
		ins(u,v);ins(v,u);
	}
	for(int i=1;i<=n;++i){
		memset(dist,-1,sizeof(dist));
		Queue[head=tail=1]=i;
		dp[i][0][i]=1;dist[i]=0;
		while(head<=tail){
			int nv=Queue[head++];
			dp[i][dist[nv]][nv]=1;
			for(edge *p=con[nv];p;p=p->nex){
				if(dist[p->v]==-1){
					dist[p->v]=dist[nv]+1;
					Queue[++tail]=p->v;
				}
			}
		}
		for(int j=1;j<=n;++j) dp[i][j]|=dp[i][j-1];
	}
	while(q--){
		cnt=read();
		can.reset();
		while(cnt--){
			place=read();len=read();
			can|=dp[place][min(n,len)];
		}
		printf("%llu\n",can.count());
	}
	return 0;
}
