#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN=51;
int T,n,k,now;
int flag[MAXN];
bool school[MAXN],gohome[MAXN],vis[MAXN];
struct edge
{
    int v;
    edge *NEXT;
    edge() {v=0;NEXT=NULL;}
}*con[MAXN];
inline void ins(int start,int end)
{
    edge *p=new(edge);
    p->v=end;
    p->NEXT=con[start];
    con[start]=p;
}
inline bool Find(int place)
{
    for(edge *p=con[place];p;p=p->NEXT)
    {
        int nv=p->v;
        if(vis[nv]==false)
        {
            vis[nv]=true;
            if(flag[nv]==0||Find(flag[nv]))
            {
                flag[nv]=place;
                return true;
            }
        }
    }
    return false;
}
inline int read()
{
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
    return x*f;
}
int main()
{
    T=read();
    while(T--)
    {
        memset(flag,0,sizeof(flag));
        memset(con,0,sizeof(con));
        n=read();
        for(int i=1;i<=n;++i)
            school[i]=read();
        for(int i=1;i<=n;++i)
        {
            gohome[i]=read();
            if(school[i]==0) gohome[i]=0;
        }
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
            {
                k=read();
                if(i==j&&school[i]==1&&gohome[i]==0) ins(i,j); 
                else if(k==1&&school[i]==1&&gohome[j]==0) ins(j,i);
            }
        now=1;
        for(;now<=n;++now)
        {
            memset(vis,0,sizeof(vis));
            if(gohome[now]==0&&Find(now)==false) break;
        }
        if(now==n+1) printf("^_^\n");
        else printf("T_T\n");
    }
    return 0;
}
