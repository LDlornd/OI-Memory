#include<bits/stdc++.h>
using namespace std;
#define maxn 115
int mx[6]={0,0,0,1,-1};
int my[6]={0,1,-1,0,0};
int ans,vis[maxn][maxn],mark1[maxn][maxn],l[maxn][maxn],cnp=1,head[maxn][maxn],n,m;
struct node
{
    int x,y;
};
queue<node>q1,q2,q;
struct edge
{
    int x,y,tx,ty,last;
}E[2000000];
void add(int x,int y,int x1,int y1)
{
    E[cnp].last=head[x][y];
    E[cnp].tx=x1,E[cnp].ty=y1;
    head[x][y]=cnp++;
}
void search()
{
    while(!q.empty())
    {
        node tem=q.front();
        q.pop();
        for(int i=head[tem.x][tem.y];i;i=E[i].last)
        {
            int x=E[i].tx,y=E[i].ty;
            if(!l[x][y])l[x][y]=1,ans++;
        }
        for(int i=1;i<=4;i++)
        {
            int x=tem.x+mx[i],y=tem.y+my[i];
            node pre;pre.x=x,pre.y=y;
            if(x<1||x>n||y<1||y>n)continue;
            if(!l[x][y])
            {
                if(!mark1[x][y])
				{
					q1.push(pre);
					mark1[x][y]=1;
				}
            }
            else if(!vis[pre.x][pre.y])
			{
				q.push(pre);
				vis[pre.x][pre.y]=1;
			}
        }
    }
    while(!q1.empty())
    {
        node tem=q1.front();
        q1.pop();
        if(!vis[tem.x][tem.y]&&l[tem.x][tem.y])q.push(tem);
        else q2.push(tem);
    }
    while(!q2.empty())
    {
        node tem=q2.front();
        q2.pop(),q1.push(tem);
    }
    if(!q.empty())search();
}
int read()
{
    int x=0;
    char c;
    c=getchar();
    while(c<'0'||c>'9')c=getchar();
    while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();
    return x;
}
int main()
{
	freopen("testdatain.in","r",stdin);
	freopen("ac.out","w",stdout);
    n=read(),m=read();
    for(int i=1;i<=m;i++)
    {
        int x=read(),y=read(),x1=read(),y1=read();
        add(x,y,x1,y1);
    }
    l[1][1]=1;
    node st;st.x=1,st.y=1;
    vis[1][1]=1;
    q.push(st);
    search();
    printf("%d",ans+1);
    return 0;
}
