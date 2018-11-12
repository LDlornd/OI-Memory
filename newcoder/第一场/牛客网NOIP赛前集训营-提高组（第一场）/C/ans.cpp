#include <cstdio>
#include <cstring>
#include<iostream>
#include <algorithm>
using namespace std;
#define N 200010
int n,m,q,tot=0,num=0,Len=0,owo=0,in[N],out[N],h[N],lg[N],fa[N][20],dep[N],root[N],id[N];
struct node{int to,next;}edge[N<<1];
struct node1{int l,r,sum;}tree[N*200];
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0' || ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while('0'<=ch && ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
inline void insert(int x,int y){
    edge[++num].to=y;edge[num].next=h[x];h[x]=num;
}
void dfs(int x){
    in[x]=++tot;id[tot]=x;
    for(int i=1;i<=lg[n];i++){
        if(!fa[x][i-1]) break;
        fa[x][i]=fa[fa[x][i-1]][i-1];
    }
    for(int i=h[x];i;i=edge[i].next){
        int y=edge[i].to;if(y==fa[x][0]) continue;
        dep[y]=dep[x]+1;fa[y][0]=x;
        Len=max(Len,dep[y]);
		dfs(y);
    }
	out[x]=tot;
}
inline int lca(int x,int y){
    if(dep[x]<dep[y]) swap(x,y);
    int len=dep[x]-dep[y];
    for(int i=0;i<=lg[len];i++){
        if((len>>i)&1) x=fa[x][i];
    }
    if(x==y) return x;
    for(int i=lg[n];i>=0;i--){
        if(fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
    }
    return fa[x][0];
}
void add(int &p,int l,int r,int x){
    tree[++owo]=tree[p];
	p=owo;
	tree[owo].sum++;
    if(l==r) return;
    int mid=(l+r)>>1;
    if(x<=mid) add(tree[p].l,l,mid,x);
    else add(tree[p].r,mid+1,r,x);
}
int query(int p,int v,int l,int r,int k){
    if(tree[v].sum-tree[p].sum<k) return 0;
    if(l==r) return l;
    int mid=(l+r)>>1,t=tree[tree[v].l].sum-tree[tree[p].l].sum;
    if(t>=k) return query(tree[p].l,tree[v].l,l,mid,k);
    else return query(tree[p].r,tree[v].r,mid+1,r,k-t);
}
inline int solve(int x,int k){
    int y=query(root[in[x]-1],root[out[x]],1,Len,k);
    cout<<y<<"fuck"<<endl;
    if(!y) return 0;
    return max(0,dep[x]-y);
}
int main(){
	freopen("testdata.in","r",stdin);
    n=read();m=read();
    lg[0]=-1;for(int i=1;i<N;i++) lg[i]=lg[i>>1]+1;
    for(int i=1;i<n;i++){
        int x=read(),y=read();
        insert(x,y);insert(y,x);
    }dep[1]=1;dfs(1);
    num=0;memset(h,0,sizeof(h));
    for(int i=1;i<=m;i++){
        int x=read(),y=read(),z=lca(x,y);
        insert(x,dep[z]),insert(y,dep[z]);
    }
    for(int i=1;i<=n;i++){
        root[i]=root[i-1];
        for(int j=h[id[i]];j;j=edge[j].next)
            add(root[i],1,Len,edge[j].to);
    }
    for(int i=1;i<=n;i++){
        for(int j=h[id[i]];j;j=edge[j].next)
            cout<<edge[j].to<<" ";
        cout<<endl;
    }
    for(int i=1;i<n;++i) cout<<in[i]<<" "<<out[i]<<" "<<id[i]<<endl;
    q=read();
    for(int i=1;i<=q;i++){
        int x=read(),y=read();
        solve(x,y);
        printf("%d\n",solve(x,y));
    }
    return 0;
}
