#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
const int INF=2147483647;
const int MAXN=105;
int T,n,m,u,v,cnt,ans1,ans2;
int fa[MAXN],Size[MAXN];
int maxlen[MAXN][MAXN];
bool vis[MAXN*MAXN];
struct link{
	int Left,Right,len;
	link() {Left=Right=len=0;}
}arr[MAXN*MAXN];
struct edge{
	int v,val;
	edge *nex;
	edge() {v=val=0;nex=NULL;}
}*con[MAXN];
void ins(int Start,int End,int key){
	edge *p=new(edge);
	p->v=End;p->val=key;
	p->nex=con[Start];con[Start]=p;
}
int getfa(int a){
	if(fa[a]==a) return a;
	else return fa[a]=getfa(fa[a]);
}
void Merge(int a,int b){
	a=getfa(a);b=getfa(b);
	if(Size[a]<Size[b]) swap(a,b);
	fa[b]=a;Size[a]+=Size[b];
}
void get_MST(){
	memset(con,0,sizeof(con));
	for(int i=1;i<=n;++i) {fa[i]=i;Size[i]=1;}
	cnt=1;ans1=0;
	for(int i=1;i<=m;++i){
		int nl=arr[i].Left,nr=arr[i].Right,nlen=arr[i].len;
		if(getfa(nl)!=getfa(nr)){
			vis[i]=true;
			Merge(nl,nr);
			ans1+=nlen;
			ins(nl,nr,nlen);ins(nr,nl,nlen);
			if(++cnt==n) break;
		}
	}
	if(cnt!=n) ans1=0;
}
void get_SST(){
	ans2=INF;
	for(int i=1;i<=m;++i){
		if(vis[i]==false)
			ans2=min(ans2,ans1-maxlen[arr[i].Left][arr[i].Right]+arr[i].len);
	}
}
void dfs(int root,int nv,int father,int key){
	if(nv!=root) maxlen[root][nv]=maxlen[nv][root]=key;
	for(edge *p=con[nv];p;p=p->nex){
		if(p->v==father) continue;
		dfs(root,p->v,nv,max(key,p->val));
	}
}
bool CMP(const link &a,const link &b){
	return a.len<b.len;
} 
int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	T=read();
	while(T--){
		n=read();m=read();
		for(int i=1;i<=m;++i)
			{arr[i].Left=read();arr[i].Right=read();arr[i].len=read();}
		sort(arr+1,arr+m+1,CMP);
		get_MST();
		if(ans1==0){
			printf("0\n");
			continue;
		}
		for(int i=1;i<=n;++i)
			dfs(i,i,0,0);
		get_SST();
		if(ans2==ans1) printf("Not Unique!\n");
		else printf("%d\n",ans1);
	}
	return 0;
}
