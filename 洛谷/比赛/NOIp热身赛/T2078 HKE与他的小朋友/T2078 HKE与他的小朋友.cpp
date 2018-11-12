#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
using namespace std;
const int MAXN=100005;
int n,k,to;
int ans[MAXN],place[MAXN];
vector<int> Queue[MAXN];
bool vis[MAXN];
struct edge{
	int v;
	edge *nex;
	edge() {v=0;nex=NULL;}
}*con[MAXN];
void ins(int Start,int End){
	edge *p=new(edge);
	p->v=End;
	p->nex=con[Start];con[Start]=p;
}
void dfs(int nv,int Start){
	Queue[Start].push_back(nv);
	vis[nv]=true;
	if(vis[con[nv]->v]==false) dfs(con[nv]->v,Start);
}
template<typename T>
T read(){
	T x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read<int>();k=read<int>();
	for(int i=1;i<=n;++i){
		to=read<int>();
		ins(i,to);
	}
	for(int i=1;i<=n;++i)
		if(vis[i]==false){
			Queue[i].push_back(0);
			dfs(i,i);
		}
	for(int i=1;i<=n;++i){
		int siz=Queue[i].size()-1;
		if(siz<=0) continue;
		int tmp=k%siz;
		for(int j=1;j<=siz;++j){
			int temp=j+tmp;
			if(temp>siz) temp-=siz;
			ans[Queue[i][j]]=Queue[i][temp];
		}
	}
	for(int i=1;i<=n;++i) place[ans[i]]=i;
	for(int i=1;i<=n;++i) printf("%d ",place[i]);
	return 0;
}
