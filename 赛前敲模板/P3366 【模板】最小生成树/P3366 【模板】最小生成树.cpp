#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=5005;
const int MAXM=2e5+5;
int n,m,ans=0;
int fa[MAXN],siz[MAXN];
struct node{
	int Left,Right,val;
	node() {Left=Right=val=0;}
}arr[MAXM];
int getfa(int a){
	if(fa[a]==a) return a;
	else return fa[a]=getfa(fa[a]);
}
void Merge(int a,int b){
	a=getfa(a);b=getfa(b);
	if(siz[a]<siz[b]) swap(a,b);
	fa[b]=a;siz[a]+=siz[b];
}
bool kruskal(){
	int cnt=1;
	for(int i=1;i<=m;++i){
		int nl=arr[i].Left,nr=arr[i].Right;
		if(getfa(nl)==getfa(nr)) continue;
		Merge(nl,nr);
		ans+=arr[i].val;
		++cnt;
		if(cnt==n) break;
	}
	return cnt==n;
}
bool CMP(const node &a,const node &b){
	return a.val<b.val;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i) scanf("%d%d%d",&arr[i].Left,&arr[i].Right,&arr[i].val);
	sort(arr+1,arr+m+1,CMP);
	for(int i=1;i<=n;++i) {fa[i]=i;siz[i]=1;}
	if(kruskal()) printf("%d",ans);
	else printf("orz");
	return 0;
}
