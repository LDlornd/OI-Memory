#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1005;
const int MAXM=10005;
int n,m,k,sum,ans;
int fa[MAXN],Size[MAXN];
struct edge{
	int Left,Right,val;
	edge() {Left=Right=val=0;}
}arr[MAXM];
int getfa(int a){
	return (fa[a]==a)?a:(fa[a]=getfa(fa[a]));
}
void Merge(int a,int b){
	a=getfa(a);b=getfa(b);
	if(Size[a]<Size[b]) swap(a,b);
	fa[b]=a;Size[a]+=Size[b];
}
bool CMP(const edge &a,const edge &b){
	return a.val<b.val;
}
int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	sum=n=read();m=read();k=read();
	ans=0;
	for(int i=1;i<=m;++i){
		arr[i].Left=read();arr[i].Right=read();arr[i].val=read();
	}
	sort(arr+1,arr+m+1,CMP);
	for(int i=1;i<=n;++i) {fa[i]=i;Size[i]=1;}
	for(int i=1;i<=m;++i){
		int nl=arr[i].Left,nr=arr[i].Right;
		if(getfa(nl)!=getfa(nr)){
			Merge(nl,nr);
			ans+=arr[i].val;
			--sum;
			if(sum==k) break;
		}
	}
	if(sum==k) printf("%d",ans);
	else printf("No Answer");
	return 0;
}
