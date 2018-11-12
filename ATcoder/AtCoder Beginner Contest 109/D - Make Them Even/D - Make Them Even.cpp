#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN=505;
int n,m,k,cnt=0;
int mp[MAXN][MAXN],add[MAXN][MAXN];
struct ans{
	int sx,sy,ex,ey;
	ans(int ssx=0,int ssy=0,int eex=0,int eey=0){
		sx=ssx;sy=ssy;ex=eex;ey=eey;
	}
}arr[MAXN];
int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read();m=read();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			mp[i][j]=read();
	for(int i=1;i<n;++i)
		for(int j=1;j<=m;++j)
			if(mp[i][j]&1){
				mp[i+1][j]+=mp[i][j];
				arr[++cnt]=ans(i,j,i+1,j);
			}
	for(int i=1;i<m;++i)
		if(mp[n][i]&1){
			mp[n][i+1]+=mp[n][i];
			arr[++cnt]=ans(n,i,n,i+1);
		}
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;++i)
		printf("%d %d %d %d\n",arr[i].sx,arr[i].sy,arr[i].ex,arr[i].ey);
	return 0;
}
