#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int MAXN=102;
struct edge
{
	int x,y,opt,tot;
	edge() {x=0;y=0;opt=-1;tot=0;}
}zhan[10000];
char MAP[MAXN][MAXN];
bool vis[MAXN][MAXN],flag=true;
int n,sx,sy,ex,ey,ans=9999999;
int tox[4]={-1,0,1,0};
int toy[4]={0,1,0,-1};
inline void dfs(int top)
{
	if(zhan[top].x==ex&&zhan[top].y==ey)
	{
		if(ans>zhan[top].tot) ans=zhan[top].tot;
		flag=false;
		return;
	}
	int nx=zhan[top].x,ny=zhan[top].y;
	for(int i=0;i<4;++i)
	{
		int tx=nx+tox[i],ty=ny+toy[i];
		if(MAP[tx][ty]=='x'||vis[tx][ty]) continue;
		zhan[top+1].x=tx;
		zhan[top+1].y=ty;
		zhan[top+1].opt=i;
		if(zhan[top].opt%2==i%2||zhan[top].opt==-1) zhan[top+1].tot=zhan[top].tot;
		else zhan[top+1].tot=zhan[top].tot+1;
		if(zhan[top+1].tot>ans) continue;
		vis[tx][ty]=true;
		dfs(top+1);
		vis[tx][ty]=false;
	}
}
int main()
{
	memset(vis,0,sizeof(vis));
	memset(MAP,'x',sizeof(MAP));
	scanf("%d\n",&n);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			if(j==n) scanf("%c \n",&MAP[i][j]);
			else scanf("%c ",&MAP[i][j]);
			if(MAP[i][j]=='A') {sx=i;sy=j;}
			if(MAP[i][j]=='B') {ex=i;ey=j;}
		}
	}
	zhan[1].x=sx;zhan[1].y=sy;
	dfs(1);
	if(flag) printf("-1");
	else printf("%d",ans);
	return 0;
}
