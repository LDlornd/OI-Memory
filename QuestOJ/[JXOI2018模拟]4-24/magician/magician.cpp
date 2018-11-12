#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN=300100;
int T,n,m,u,v,c,src,dst,endplace,temp=0;
int mag[101],magtot=0;
int depth[MAXN];
int Queue[MAXN],head,tail;
struct edge{
	int v,remain;
	edge *nex,*rev;
	edge() {v=remain=0;nex=rev=NULL;}
}*con[MAXN],*now[MAXN];
inline void ins(int Start,int End){
	edge *p=new(edge);
	p->v=End;p->remain=1;
	p->nex=con[Start];con[Start]=p;
	p=new(edge);
	p->v=Start;p->remain=1;
	p->nex=con[End];con[End]=p;
	con[Start]->rev=con[End];
	con[End]->rev=con[Start];
}
inline bool bfs(int Start){
	memset(depth,-1,sizeof(depth));
	Queue[head=tail=1]=Start;
	depth[Start]=1;
	while(head<=tail){
		int nv=Queue[head++];
		for(edge *p=con[nv];p;p=p->nex){
			if(depth[p->v]==-1&&p->remain>0){
				depth[p->v]=depth[nv]+1;
				Queue[++tail]=p->v;
			}
		}
	}
	return depth[endplace]!=-1;
}
inline int dfs(int nv,int maxflow){
	int nowflow=0,totflow=0;
	if(depth[nv]==-1||maxflow<=0) return 0;
	if(nv==endplace) return maxflow;
	for(edge *p=now[nv];p;p=p->nex){
		now[nv]=p;
		if(depth[p->v]==depth[nv]+1&&p->remain>0){
			nowflow=dfs(p->v,min(maxflow-totflow,p->remain));
//			if(nowflow!=0) cout<<nv<<" "<<p->v<<" "<<nowflow<<endl;;
			p->remain-=nowflow;
			p->rev->remain+=nowflow;
			totflow+=nowflow;
		}
		if(totflow>=maxflow) break;
	}
	if(totflow==0) depth[nv]=-1;
	return totflow;
}
inline void dinic(int Start){
	int flow;
	while(bfs(Start)){
		for(int i=1;i<=endplace;++i) now[i]=con[i];
		while(flow=dfs(Start,2147483647))
			temp+=flow;
	}
}
inline void getready(){
	temp=0;
	for(int i=1;i<=endplace;++i)
		for(edge *p=con[i];p;p=p->nex)
			p->remain=1;
}
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	freopen("testdata.in","r",stdin);
	freopen("gaojibaoli.out","w",stdout);
	T=read();
	while(T--){
		memset(con,0,sizeof(con));
		magtot=0;
		n=read();m=read();
		while(m--){
			u=read();v=read();c=read();
			if(c==1){
				++magtot;
				mag[magtot]=n+magtot;
				ins(u,n+magtot);
				ins(n+magtot,v);
			}
			else ins(u,v);
		}
		src=read();dst=read();
		if(magtot>20) printf("YES\n");
		else{
			endplace=n+magtot+1;
			ins(src,endplace);ins(dst,endplace);
//			for(int i=1;i<=endplace;++i){
//				cout<<i<<"sons ";
//				for(edge *p=con[i];p;p=p->nex) cout<<p->v<<" ";
//				cout<<endl;
//			}
			for(int w=1;w<=magtot;++w){
				getready();
				dinic(mag[w]);
				if(temp==2) break;
			}
			if(temp==2) printf("YES\n");
			else printf("NO\n");
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
