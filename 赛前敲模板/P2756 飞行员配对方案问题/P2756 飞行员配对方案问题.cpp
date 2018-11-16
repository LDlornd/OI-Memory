#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN=205;
int n,m,u,v,ans=0;
int  get[MAXN];
bool vis[MAXN];
struct edge{
	int v;
	edge *nex;
}*con[MAXN];
void ins(int Start,int End){
	edge *p=new(edge);
	p->v=End;
	p->nex=con[Start];con[Start]=p;
}
bool match(int nv){
	for(edge *p=con[nv];p;p=p->nex){
		if(vis[p->v]) continue;
		vis[p->v]=true;
		if(get[p->v]==0||match(get[p->v])){
			get[p->v]=nv;get[nv]=p->v;
			return true;
		}
	}
	return false;
}
int main(){
	scanf("%d%d",&m,&n);
	while(scanf("%d%d",&u,&v)!=EOF){
		if(u==-1&&v==-1) break;
		ins(u,v);
	}
	for(int i=1;i<=m;++i){
		memset(vis,0,sizeof(vis));
		if(match(i)) ++ans;
	}
	if(ans==0){
		printf("No Solution!");
		return 0;
	}
	printf("%d\n",ans);
	for(int i=1;i<=m;++i)
		if(get[i]!=0) printf("%d %d\n",i,get[i]);
	return 0;
}
