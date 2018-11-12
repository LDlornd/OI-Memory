#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=305;
int n,m;
int mp[MAXN][MAXN],ans[MAXN][MAXN];
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
	for(int w=0;w<=n;++w){
		bool flag=false;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				int tempi=i,tempj=j-1,tmp;
				tmp=mp[tempi][tempj];
				if(tmp>mp[i][j+1]) tmp=mp[tempi=i][tempj=j+1];
				if(tmp>mp[i-1][j]) tmp=mp[tempi=i+1][tempj=j];
				if(tmp>mp[i+1][j]) tmp=mp[tempi=i+1][tempj=j];
				tmp-=mp[i][j];
				if(tmp>0){
					flag=true;
					ans[i][j]+=tmp;
					mp[i][j]=mp[tempi][tempj];
				}
			}
		}
		if(flag==false) break;
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j)
			printf("%d ",ans[i][j]);
		printf("\n");
	}
	return 0;
}
