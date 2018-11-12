#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int MAXN=105;
int m,n,s,q,k,temp,maxnum=0;
int l[MAXN],r[MAXN];
int place[2][2][MAXN*MAXN];
int mp[2][MAXN][MAXN];
bool flag1=false,flag2=false;
int main(){
	scanf("%d%d%d%d",&n,&m,&s,&q);
	if(n>100){
		printf("Impossible!");
		return 0;
	}
	for(int i=1;i<=s;++i){
		scanf("%d%d",&l[i],&r[i]);
		maxnum=max(maxnum,max(l[i],r[i]));
	}
	temp=n*m;
	cout<<maxnum<<"fuck"<<endl;
	for(int i=1;i+maxnum-1<=temp;++i){
		if(flag1){
			if(flag2) break;
			else{
				memset(mp[1],0,sizeof(mp[1]));
				int x=i/m+1,y=i%m,sum=0;
				if(y==0) {y=m;--x;}
				for(int b=y;b<=m;++b){
					mp[1][x][b]=(++sum);
					place[1][0][sum]=x;
					place[1][1][sum]=b;
				}
				for(int a=x+1;a<=n;++a)
					for(int b=1;b<=m;++b){
						mp[1][a][b]=(++sum);
						place[1][0][sum]=a;
						place[1][1][sum]=b;
					}
				for(int a=1;a<=m;++a)
					if(place[1][0][l[a]]!=place[1][0][r[a]]) break;
					else if(a==m) flag2=true;
			}
		}
		else{
			int x=i/m+1,y=i%m,sum=0;
			if(y==0) {y=m;--x;}
			memset(mp[0],0,sizeof(mp[0]));
			for(int b=y;b<=m;++b){
				mp[0][x][b]=(++sum);
				place[0][0][sum]=x;
				place[0][1][sum]=b;
			}
			for(int a=x+1;a<=n;++a)
				for(int b=1;b<=m;++b){
					mp[0][a][b]=(++sum);
					place[0][0][sum]=a;
					place[0][1][sum]=b;
				}
			for(int a=1;a<=m;++a)
				if(place[0][0][l[a]]!=place[0][0][r[a]]) break;
				else if(a==m) flag1=true;
		}
	}
	if(flag1==false) printf("Impossible!");
	else if(flag2) printf("Uncertain!");
	else{
		int ans=0;
		while(q--){
			scanf("%d",&k);
			if(k>mp[0][n][m]) continue;
			ans^=place[0][0][k];
			ans^=place[0][1][k];
		}
		printf("%d",ans);
	}
	return 0;
}
