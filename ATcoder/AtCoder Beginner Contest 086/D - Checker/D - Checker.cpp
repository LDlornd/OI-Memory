#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int MAXN=1010;
char color;
int n,k,k2,x,y,ans=0;
int black[MAXN][MAXN],white[MAXN][MAXN];
inline int getblack(int startx,int starty,int endx,int endy)
{
	return black[endx][endy]-black[startx-1][endy]-black[endx][starty-1]+black[startx-1][starty-1];
}
inline int getwhite(int startx,int starty,int endx,int endy)
{
	return white[endx][endy]-white[startx-1][endy]-white[endx][starty-1]+white[startx-1][starty-1];
}
inline int read()
{
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
	return x*f;
}
inline char getcolor()
{
	char c=getchar();
	while(c!='B'&&c!='W') c=getchar();
	return c;
}
int main()
{
	memset(black,0,sizeof(black));
	memset(while,0,sizeof(white));
	n=read();k=read();k2=2*k;
	for(int i=1;i<=k;++i)
	{
		x=read();y=read();opt=getcolor();
		x=(x%k2)+1;y=(y%k2)+1;
		if(opt=='B') ++black[x][y];
		else ++white[x][y];
	}
	for(int i=1;i<=k2+1;++i)
		for(int j=1;j<=k2+1;++j)
		{
			black[i][j]=black[i][j]+black[i][j-1]+black[i-1][j]-black[i-1][j-1];
			white[i][j]=white[i][j]+white[i][j-1]+white[i-1][j]-white[i-1][j-1];
		}
	for(int i=1;i<=k;++i)
	{
		for(int j=1;j<=k;++j)
		{
			if(i>k&&j>k) break;
			int tempans=getblack(1,1,i,j)+getblack(i+1,j+1,i+k,j+k)+getblack(1,y+k+1,);
			ans=max(ans,max(tempans,n-tempans));
		}
	}
	printf("%d",ans);
	return 0;
}
now=black(1,1,x,y)+black(x+1,y+1,x+K,y+K)+black(1,y+K+1,x,2*K)+black(x+K+1,1,2*K,y)+black(x+K+1,y+K+1,2*K,2*K)+white(1,y+1,x,y+K)+white(x+1,1,x+K,y)+white(x+1,y+K+1,x+K,2*K)+white(x+K+1,y+1,2*K,y+K);
