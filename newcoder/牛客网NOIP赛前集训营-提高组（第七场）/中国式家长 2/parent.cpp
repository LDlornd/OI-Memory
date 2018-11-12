#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=205;
int n,m,k,have,T,px,py,ans=0;
int arr[MAXN][MAXN];
bool flag[MAXN][MAXN],vis[MAXN][MAXN];
void explore(int kx,int ky){
	flag[max(0,kx-1)][max(0,ky-1)]=true;
	flag[max(0,kx-1)][ky]=true;
	flag[max(0,kx-1)][min(m,ky+1)]=true;
	flag[kx][max(0,ky-1)]=true;
	flag[kx][min(m,ky+1)]=true;
	flag[min(n,kx+1)][max(0,ky-1)]=true;
	flag[min(n,kx+1)][ky]=true;
	flag[min(n,kx+1)][min(m,ky+1)]=true;
}
int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read();m=read();have=k=read();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			arr[i][j]=read();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			flag[i][j]=read();
	T=read();
	while(T--){
		px=read();py=read();
		if(flag[px][py]==false||vis[px][py]||(arr[px][py]==0&&have<10)) {have=-1;ans=-1;break;}
		vis[px][py]=true;
		if(arr[px][py]==0) {have-=10;ans+=10;}
		else have=min(k,have+arr[px][py]);
		explore(px,py);
	}
	printf("%d %d",have,ans);
	return 0;
}
