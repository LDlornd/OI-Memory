#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=51;
struct gun{
	int x,y,to;
	gun(int xx=0,int yy=0,int tt=0) {x=xx;y=yy;to=tt;}
}G[MAXN*MAXN];
int n,m,tot=0,ans=0;
int MAP[MAXN][MAXN];
bool num[MAXN][MAXN];
inline void dfs(int now,int sum){
	if(now==tot+1){
		ans=max(ans,sum);
		return;
	}
	dfs(now+1,sum);
	int nx=G[now].x,ny=G[now].y,nto=G[now].to;
	if(nto==-1){
		for(int i=nx-1;i>=1;--i){
			if(num[i][ny]){
				for(int j=i+1;j<nx;++j)
					num[j][ny]=false;
				return;
			}
			num[i][ny]=true;
			dfs(now+1,sum+MAP[i][ny]);
		}
		for(int i=1;i<nx;++i) num[i][ny]=false;
	}
	if(nto==-2){
		for(int i=nx+1;i<=n;++i){
			if(num[i][ny]){
				for(int j=i-1;j>nx;--j)
					num[j][ny]=false;
				return;
			}
			num[i][ny]=true;
			dfs(now+1,sum+MAP[i][ny]);
		}
		for(int i=n;i>ny;--i) num[i][ny]=false;
	}
	if(nto==-3){
		for(int i=ny-1;i>=1;--i){
			if(num[nx][i]){
				for(int j=i+1;j<ny;++j)
					num[nx][j]=false;
				return;
			}
			num[nx][i]=true;
			dfs(now+1,sum+MAP[nx][i]);
		}
		for(int i=1;i<ny;++i) num[nx][i]=false;
	}
	if(nto==-4){
		for(int i=ny+1;i<=m;++i){
			if(num[nx][i]){
				for(int j=i-1;j>ny;--j)
					num[nx][j]=false;
				return;
			}
			num[nx][i]=true;
			dfs(now+1,sum+MAP[nx][i]);
		}
		for(int i=m;i>ny;--i) num[nx][i]=false;
	}
}
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read();m=read();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j){
			MAP[i][j]=read();
			if(MAP[i][j]<0) G[++tot]=gun(i,j,MAP[i][j]);
		}
	dfs(1,0);
	printf("%d",ans);
	return 0;
}
