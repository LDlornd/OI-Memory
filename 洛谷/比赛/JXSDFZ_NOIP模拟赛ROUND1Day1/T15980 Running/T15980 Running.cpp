#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int MAXN=505;
struct edge
{
    int x,y;
}dl[10000000];
char MAP[MAXN][MAXN];
int tox[2]={0,1};
int toy[2]={1,0};
inline bool bfs(int endx,int endy)
{
    int head=1,tail=1;
    while(head-1!=tail%(MAXN-1))
    {
        int nx=dl[head].x,ny=dl[head].y;
        for(int i=0;i<2;++i)
        {
            int nnx=nx+tox[i],nny=ny+toy[i];
            if(MAP[nnx][nny]=='1') continue;
            if(nnx==endx&&nny==endy) return true;
            if(tail==MAXN-1) tail=1;
            else ++tail;
            dl[tail].x=nnx;dl[tail].y=nny;
        }
        if(head==MAXN-1) head=1;
        else ++head;
    }
    return false;
}
int main()
{
    memset(MAP,'1',sizeof(MAP));
    int n,m,q,sx,sy,ex,ey;
    scanf("%d%d\n",&n,&m);
    for(int i=1;i<=n;++i)
        scanf("%s",MAP[i]+1);
    scanf("%d",&q);
    for(int w=0;w<q;++w)
    {
        scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
        dl[1].x=sx;dl[1].y=sy;
        if(bfs(ex,ey)) printf("Safe\n");
        else printf("Dangerous\n");
    }
    return 0;
}

