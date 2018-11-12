#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=2001;
const int INF=2147483647;
int a,m,n,l,r,ans=INF;
int dp[MAXN][MAXN];
bool flag[MAXN];
struct node{
	int place,val;
	node() {place=val=0;}
}arr[MAXN];
inline bool CMP(const node &x,const node &y){
	return x.place<y.place;
}
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	a=read();n=read();m=read();
	while(n--){
		l=read();r=read();
		for(int i=l+1;i<=r;++i) flag[i]=true;
	}
	for(int i=1;i<=m;++i)
		{arr[i].place=read();arr[i].val=read();}
	sort(arr+1,arr+m+1,CMP);
	for(int i=1;i<=a;++i)
		for(int j=0;j<=m;++j)
			dp[i][j]=INF;
	for(int i=1;i<=a;++i){
		if(flag[i]==false){
			for(int j=0;j<=m;++j)
				if(arr[j].place>=i) break;
				else dp[i][0]=min(dp[i][0],dp[i-1][j]);
		}
		for(int j=1;j<=m;++j){
			if(arr[j].place>=i) break;
			if(arr[j].place!=i-1&&dp[i-1][j]!=INF) dp[i][j]=min(dp[i][j],dp[i-1][j]+arr[j].val);
			else{
				for(int k=0;k<j;++k)
					if(dp[i-1][k]==INF) continue;
					else dp[i][j]=min(dp[i][j],dp[i-1][k]+arr[j].val);
			}
		}
	}
	for(int i=0;i<=m;++i)
		ans=min(ans,dp[a][i]);
	if(ans==INF) ans=-1;
	printf("%d",ans);
	return 0;
}
