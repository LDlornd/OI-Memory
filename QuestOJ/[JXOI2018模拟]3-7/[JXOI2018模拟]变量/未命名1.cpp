#include <bits/stdc++.h>
#define LL long long
using namespace std;

int n, sum, a[10], mp[5][5];
bool vis[10], vmap[5][5];

void print()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++) printf("%d ", mp[i][j]);
        printf("\n");
    }
}

bool check(int cnt)
{
    int ch=0, flag=0;
    if(cnt<=n+1) return true;
    for(int i=1; i<=n; i++)
    {
        ch=0, flag=0;
        for(int j=1; j<=n; j++)
        {
            if(vmap[i][j]==0) {flag=1; break;}
            ch+=mp[i][j];
        }
        if(ch!=sum && flag==0) return false;
    }
    for(int j=1; j<=n; j++)
    {
        ch=0, flag=0;
        for(int i=1; i<=n; i++)
        {
            if(vmap[i][j]==0) {flag=1; break;}
            ch+=mp[i][j];
        }
        if(ch!=sum && flag==0) return false;
    }
    ch=0, flag=0;
    for(int i=1; i<=n; i++)
    {
        if(vmap[i][i]==0) {flag=1; break;}
        ch+=mp[i][i];
    }
    if(ch!=sum && flag==0) return false;
    ch=0, flag=0;
    for(int i=1; i<=n; i++)
    {
        int j=n+1-i;
        if(vmap[i][j]==0) {flag=1; break;}
        ch+=mp[i][j];
    }
    if(ch!=sum && flag==0) return false;
    return true;
}

void dfs(int x, int y, int cnt)
{
    if(!check(cnt)) return;
    if(cnt==n*n+1)
    {
        LL ans=0;
        for(int i=1; i<=n; i++) ans+=mp[i][1];
        printf("%lld\n", ans);
        print();
        exit(0);
    }
    for(int i=1; i<=n*n; i++) if(!vis[i])
    {
        vis[i]=1;
        mp[x][y]=a[i];
        vmap[x][y]=1;
        if(y==n) dfs(x+1, 1, cnt+1);
        else dfs(x, y+1, cnt+1);
        vmap[x][y]=0;
        mp[x][y]=0;
        vis[i]=0;
    }
}

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n*n; i++) scanf("%d", &a[i]), sum+=a[i]; 
    sum/=n;
    sort(a+1, a+n*n+1);
    dfs(1, 1, 1);
}
