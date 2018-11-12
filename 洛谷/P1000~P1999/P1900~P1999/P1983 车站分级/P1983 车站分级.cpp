#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN=1005;
int n,m,cnt,ans=0;
int stop[MAXN];
int indu[MAXN],rk[MAXN];
int Queue[MAXN],head,tail;
bool flag[MAXN],link[MAXN][MAXN];
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
	++indu[End];
}
void top_sort(){
	head=1;tail=0;
	for(int i=1;i<=n;++i)
		if(indu[i]==0) {Queue[++tail]=i;rk[i]=1;}
	while(head<=tail){
		int nv=Queue[head++];
		for(edge *p=con[nv];p;p=p->nex)
			if(--indu[p->v]==0){
				ans=max(ans,rk[p->v]=rk[nv]+1);
				Queue[++tail]=p->v;
			}
	}
}
int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read();m=read();
	while(m--){
		memset(flag,0,sizeof(flag));
		cnt=read();
		for(int i=1;i<=cnt;++i) flag[stop[i]=read()]=true;
		for(int i=stop[1];i<=stop[cnt];++i){
			if(flag[i]) continue;
			for(int j=1;j<=cnt;++j) if(link[i][stop[j]]==false) ins(i,stop[j]);
		}
	}
	top_sort();
	printf("%d",ans);
	return 0;
}
