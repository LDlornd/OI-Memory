#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxx=205,inf=0x3f3f3f3f;
int n,m,pre[maxx][maxx];
int mp[maxx][maxx];
bool vis[maxx][maxx];                 //????????
void getint(int &x){
    x=0; char c=' ';
    while(c<'0' || c>'9') c=getchar();
    while(c<='9' && c>='0'){ x=x*10+c-'0'; c=getchar();} 
}
int main()
{
	freopen("city.in","r",stdin);
	freopen("ans.out","w",stdout);
    int x,y,z;
    getint(n); getint(m);
    memset(pre,0,sizeof(pre)); memset(vis,0,sizeof(vis));
    memset(mp,0x3f,sizeof(mp));
    for(int i=1;i<=n;++i) mp[i][i]=0;
    for(int i=1;i<=m;++i){
        getint(x); getint(y); getint(z);
        mp[x][y]=mp[y][x]=z;
    }

    for(int k=1;k<=n;++k){                                //Floyd
        for(int i=1;i<=n;++i) if(k!=i){
            for(int j=1;j<=n;++j) if(k!=j && i!=j){
                if(mp[i][j]>mp[i][k]+mp[k][j]){
                    mp[i][j]=mp[i][k]+mp[k][j];
                    vis[i][j]=false;
                    pre[i][j]=k;
                }else if(mp[i][j]==mp[i][k]+mp[k][j]) vis[i][j]=true;
            } 
        }
    }

    int q[maxx],top=0;          //?????
    bool inq[maxx];                 //???????????????????
    memset(inq,0,sizeof(inq));     // ????????
    for(int i=1;i<=n;++i){                    //????
        for(int j=1;j<=n;++j){
            if(i!=j && !vis[i][j] && pre[i][j] && !inq[pre[i][j]]){
                q[++top]=pre[i][j]; inq[q[top]]=true;
            }
        }
    }
    sort(q+1,q+top+1);        //?
    for(int i=1;i<=top;++i) printf("%d ",q[i]);
    if(!top) printf("No important cities.");
    printf("\n");
    return 0;
}
