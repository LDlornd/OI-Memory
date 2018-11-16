#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=10005;
int n,m,opt,x,y;
int fa[MAXN],siz[MAXN];
int getfa(int a){
	if(fa[a]==a) return a;
	else return fa[a]=getfa(fa[a]);
}
void Merge(int a,int b){
	a=getfa(a);b=getfa(b);
	if(a==b) return;
	if(siz[a]<siz[b]) swap(a,b);
	fa[b]=a;siz[a]+=siz[b];
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) {fa[i]=i;siz[i]=1;}
	while(m--){
		scanf("%d%d%d",&opt,&x,&y);
		if(opt==1) Merge(x,y);
		else{
			if(getfa(x)==getfa(y)) printf("Y\n");
			else printf("N\n");
		}
	}
	return 0;
}
