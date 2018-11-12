#include <cstdio>
#include <algorithm>
#include <cmath>
#define MAXN 200005
#define ls (root<<1)
#define rs (root<<1|1)
#define mid (l+r>>1)
using namespace std;
int n, m, r, p, opt, x, y, z, cnt, w[MAXN], sum[MAXN*4], add[MAXN*4], head[MAXN];
int  Index, son[MAXN], id[MAXN], size[MAXN], dep[MAXN], top[MAXN], f[MAXN], val[MAXN];
struct Edge {int to, next;} edge[MAXN];
void addedge(int from, int to){
    edge[++cnt].next=head[from];
    edge[cnt].to=to;
    head[from]=cnt;
}
void up(int root){
    sum[root]=(sum[ls]+sum[rs])%p;
}
void down(int root, int l, int r){
    if(!add[root]) return;
    add[ls]=(add[ls]+add[root])%p;
    add[rs]=(add[rs]+add[root])%p;
    sum[ls]=(sum[ls]+add[root]*(mid-l+1))%p;
    sum[rs]=(sum[rs]+add[root]*(r-mid));
    add[root]=0;
}
void build(int root, int l, int r){
    if(l==r) {sum[root]=val[l]%p; return;}
    build(ls, l, mid);
    build(rs, mid+1, r);
    up(root);
}
void update(int root, int l, int r, int x, int y, int z){
    if(x>r || y<l) return ;
    if(x<=l && y>=r){
        sum[root]=(sum[root]+z*(r-l+1))%p;
        add[root]=(add[root]+z)%p;
        return ;
    }
    down(root, l, r);
    update(ls, l, mid, x, y, z);
    update(rs, mid+1, r, x, y, z);
    up(root);
}
int query(int root, int l, int r, int x, int y){
    if (l>y || r<x) return 0;
    if(x<=l && y>=r) return sum[root];
    down(root, l, r);
    return (query(rs, mid+1, r, x, y)+query(ls, l, mid, x, y))%p;
}
void dfs1(int x, int fa, int deep){
    dep[x]=deep; f[x]=fa; size[x]=1;
    int maxson=-1;
    for(int i=head[x]; i; i=edge[i].next){
        int to=edge[i].to;
        if(to==fa) continue;
        dfs1(to, x, deep+1);
        size[x]+=size[to];
        if(size[to]>maxson) son[x]=to, maxson=size[to];
    }
}
void dfs2(int x, int topf){
    id[x]= ++Index; val[Index]=w[x]; top[x]=topf;
    if(!son[x]) return;
    dfs2(son[x], topf);
    for(int i=head[x]; i; i=edge[i].next){
        int to=edge[i].to;
        if(to!=f[x] && to!=son[x]) dfs2(to, to);
    }
}
int query1(int x, int y){
    int ans=0;
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]]) swap(x, y);
        ans=(ans+query(1, 1, n, id[top[x]], id[x]))%p;
        x=f[top[x]];
    }
    if(dep[x]>dep[y]) swap(x, y);
    ans=(ans+query(1, 1, n, id[x], id[y]))%p;
    return ans;
}
void update1(int x, int y, int k){
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]]) swap(x, y);
        update(1, 1, n, id[top[x]], id[x], k%p);
        x=f[top[x]];
    }
    if(dep[x]>dep[y]) swap(x, y);
    update(1, 1, n, id[x], id[y], k);
}
int main(){
    scanf("%d%d%d%d", &n, &m, &r, &p);
    for(int i=1; i<=n; i++) scanf("%d", &w[i]);
    for(int i=1; i<n; i++){
        scanf("%d%d", &x, &y);
        addedge(x, y); addedge(y, x);
    }
    dfs1(r, -1, 1);
    dfs2(r, r);
    build(1, 1, n);
    for(int i=1; i<=m; i++){
        scanf("%d", &opt);
        if(opt==1){
            scanf("%d%d%d", &x, &y, &z);
            update1(x, y, z);
        }
        if(opt==2){
            scanf("%d%d", &x, &y);
            printf("%d\n", query1(x, y));
        }
        if(opt==3){
            scanf("%d%d", &x, &y);
            update(1, 1, n, id[x], id[x]+size[x]-1, y);
        }
        if(opt==4){
            scanf("%d", &x);
            printf("%d\n", query(1, 1, n, id[x], id[x]+size[x]-1));
        }
    }
}
