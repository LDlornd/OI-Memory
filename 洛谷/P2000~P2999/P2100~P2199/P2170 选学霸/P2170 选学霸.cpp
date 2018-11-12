#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<map>
using namespace std;
const int MAXN=20005;
int n,m,k,u,v,tot=0,ans1,ans2;
int fa[MAXN],Size[MAXN];
int val[MAXN];
bool dp[MAXN<<1],vis[MAXN];
int getfa(int a){
	if(fa[a]==a) return a;
	else return fa[a]=getfa(fa[a]);
}
void Merge(int a,int b){
	a=getfa(a);b=getfa(b);
	if(Size[a]<Size[b]) swap(a,b);
	fa[b]=a;Size[a]+=Size[b];
}
int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	freopen("testdata.in","r",stdin);
	n=read();m=read();k=read();
	for(int i=1;i<=n;++i) {fa[i]=i;Size[i]=1;}
	while(k--){
		u=read();v=read();
		if(getfa(u)!=getfa(v)) Merge(u,v);
	}
	for(int i=1;i<=n;++i)
		if(getfa(i)==i&&vis[i]==false) val[++tot]=Size[i];
	dp[0]=true;ans1=0;ans2=m<<1;
	for(int i=1;i<=tot;++i)
		for(int j=(m<<1);j>=val[i];--j)
			dp[j]=dp[j]|dp[j-val[i]];
	for(int i=m;i>=0;--i)
		if(dp[i]) {ans1=i;break;}
	for(int i=m;i<=(m<<1);++i)
		if(dp[i]) {ans2=i;break;}
	if(ans2-m<m-ans1) ans1=ans2;
	printf("%d",ans1);
	return 0;
}
