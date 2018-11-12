#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN=150005;
int n,q,opt,u,v,w,k;
struct node{
	int val;
	node *nex,*rev;
	node() {val=0;nex=rev=NULL;}
}*head[MAXN],*tail[MAXN];
inline void ins(int id,int key){
	node *p=new(node);
	p->val=key;
	p->nex=tail[id];
	p->rev=tail[id]->rev;
	tail[id]->rev->nex=p;
	tail[id]->rev=p;
	++head[id]->val;
}
inline void del_front(int id){
	head[id]->nex=head[id]->nex->nex;
	delete(head[id]->nex->rev);
	head[id]->nex->rev=head[id];
}
inline void del_last(int id){
	tail[id]->rev=tail[id]->rev->rev;
	delete(tail[id]->rev->nex);
	tail[id]->rev->nex=tail[id];
}
inline void Merge1(int id1,int id2){
	tail[id1]->rev->nex=head[id2]->nex;
	head[id2]->nex->rev=tail[id1]->rev;
	tail[id2]->rev->nex=tail[id1];
	tail[id1]->rev=tail[id2]->rev;
}
inline void Merge2(int id1,int id2){
	
}
int read(){
	int x=0,f=1;char c=gethcar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	while(scanf("%d%d",&n,&q)!=EOF){
		
	}
}
for(int i=1;i<n;++i){
	reverse i;
	add i to i+1;
}

#include <bits/stdc++.h>
using namespace std;

const int N = 1.1e6;
int nxt[N], pre[N], val[N], tot;
int n, q;
struct node
{
    int f, b;
} lst[N][2];
node link(node a, node b)
{
    if (a.f == -1) return b;
    if (b.f == -1) return a;
    nxt[a.b] = b.f;
    pre[b.f] = a.b;
    return (node){a.f, b.b};
}
int main()
{
    while (scanf("%d%d", &n, &q) == 2)
    {
        for (int i = 1; i <= n; ++ i)
            for (int j = 0; j < 2; ++ j)
                lst[i][j].f = lst[i][j].b = -1;
        tot = 0;
        for (int i = 1; i <= q; ++ i)
        {
            int opt, u, v, w;
            scanf("%d", &opt);
            if (opt == 1)
            {
                scanf("%d%d%d", &u, &w, &v);
                node p;
                p.f = p.b = ++ tot; val[tot] = v;
                nxt[tot] = pre[tot] = -1;
                lst[u][w] = link(p, lst[u][w]);
                p.f = p.b = ++ tot; val[tot] = v;
                nxt[tot] = pre[tot] = -1;
                lst[u][!w] = link(lst[u][!w], p);
            }
            else if (opt == 2)
            {
                scanf("%d%d", &u, &w);
                if (lst[u][w].f == -1)
                    puts("-1");
                else printf("%d\n", val[lst[u][w].f]);
                if (lst[u][w].f == lst[u][w].b)
                    lst[u][w].f = lst[u][w].b = -1;
                else lst[u][w].f = nxt[lst[u][w].f];
                if (lst[u][!w].f == lst[u][!w].b)
                    lst[u][!w].f = lst[u][!w].b = -1;
                else lst[u][!w].b = pre[lst[u][!w].b];
            }
            else
            {
                scanf("%d%d%d", &u, &v, &w);
                if (w) swap(lst[v][w], lst[v][!w]);
                lst[u][0] = link(lst[u][0], lst[v][0]);
                lst[u][1] = link(lst[v][1], lst[u][1]);
                lst[v][0].f = lst[v][0].b = -1;
                lst[v][1].f = lst[v][1].b = -1;
            }
        }
    }
}
