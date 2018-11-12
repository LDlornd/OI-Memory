#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN=100005;
int T,n,k,u,ans=0;
int res[MAXN],tot;
bool vis[MAXN],flag[MAXN];
struct edge{
	int v;
	edge *Next;
	edge() {v=0;Next=NULL;}
}*con[MAXN];
inline void ins(int Start,int End){
	edge *p=new(edge);
	p->v=End;
	p->Next=con[Start];
	con[Start]=p;
}
inline void top_sort(int nv){
	flag[nv]=true;
	for(edge *p=con[nv];p;p=p->Next) if(flag[p->v]==false) top_sort(p->v);
	res[++tot]=nv;
}
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';
	return x*f;
}
int main(){
	T=read();
	while(T--){
		memset(con,0,sizeof(con));
		memset(vis,0,sizeof(vis));
		memset(flag,0,sizeof(flag));
		ans=0;vis[0]=true;
		n=read();k=read();
		for(int i=2;i<=n;++i){
			u=read();
			ins(i,u);ins(u,i);
		}
		tot=0;
		top_sort(1);
		for(int i=1;i<=n&&k>=2;++i){
			int nv=res[i];
			if(vis[nv]==false)
				for(edge *p=con[nv];p;p=p->Next)
					if(vis[p->v]==false){
						k-=2;++ans;
						vis[nv]=vis[p->v]=true;
						break;
					}
			
		}
		ans+=k;
		cout<<ans<<endl;
	}
}
