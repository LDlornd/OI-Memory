#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
const int MAXN=10001;
const int INF=2147483647;
struct edge
{
    int v,length;
    edge *next;
}*con[MAXN];
bool vis[MAXN];
int dis[MAXN],dl[MAXN];
int n,m,s,f,g,w,head=1,tail=1;
inline void ins(int start,int end,int len)
{
    edge *p=new(edge);
    p->length=len;
    p->v=end;
    p->next=con[start];
    con[start]=p;
}
void spfa()
{
    for(int i=1;i<=n;++i) dis[i]=INF;
    dis[s]=0;vis[s]=true;
    dl[head]=s;
    while((head-1)!=tail%(MAXN-1))
    {
        int v=dl[head];
        for(edge *p=con[v];p!=NULL;p=p->next)
        {
            int nv=p->v,nl=p->length;
            if(dis[nv]>dis[v]+nl)
            {
                dis[nv]=dis[v]+nl;
                if(!vis[nv])
                {
                    if(tail==MAXN-1) tail=1;
                    else ++tail;
                    dl[tail]=nv;
                    vis[nv]=true;
                }
            }
        }
        if(head==MAXN-1) head=1;
        else ++head;
        vis[v]=false;
    }
}
int main()
{
    memset(vis,0,sizeof(vis));
    scanf("%d%d%d",&n,&m,&s);
    for(int i=0;i<m;++i)
    {
        scanf("%d%d%d",&f,&g,&w);
        ins(f,g,w);
    }
    spfa();
    for(int i=1;i<=n;++i)
        printf("%d ",dis[i]);
    return 0;
}

