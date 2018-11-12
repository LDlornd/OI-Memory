#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int MAXN1=51;
const int MAXN2=201;
const int INF=500;
int n,T,starttime,leftn,rightn,casenumber=0;
int Time[MAXN1];
bool left_train[MAXN2][MAXN1],right_train[MAXN2][MAXN1];
int dp[MAXN2][MAXN1];
inline void getready()
{
	memset(left_train,0,sizeof(left_train));
	memset(right_train,0,sizeof(right_train));
	for(int i=0;i<=T;++i) dp[i][0]=0;
	for(int i=0;i<=T;++i)
		for(int j=0;j<=n;++j)
			dp[i][j]=INF;
	dp[0][1]=0;
}
inline int read()
{
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
	return x*f;
}
int main()
{
	while(true)
	{
		n=read();
		if(n==0) return 0;
		T=read();getready();
		for(int i=1;i<n;++i) Time[i]=read();
		leftn=read();
		while(leftn--)
		{
			starttime=read();
			for(int i=1;i<=n;++i)
			{
				left_train[starttime][i]=true;
				starttime+=Time[i];
				if(starttime>T) break;
			}
		}
		rightn=read();
		while(rightn--)
		{
			starttime=read();
			for(int i=n;i>=1;--i)
			{
				right_train[starttime][i]=true;
				starttime+=Time[i-1];
				if(starttime>T) break;
			}
		}
		for(int i=1;i<=T;++i)
		{
			for(int j=1;j<=n;++j)
			{
				dp[i][j]=min(dp[i][j],dp[i-1][j]+1);
				if(left_train[i][j]&&i>=Time[j-1]&&j>1)
					dp[i][j]=min(dp[i][j],dp[i-Time[j-1]][j-1]);
				if(right_train[i][j]&&i>=Time[j]&&j<n)
					dp[i][j]=min(dp[i][j],dp[i-Time[j]][j+1]);
			}
		}
		printf("Case Number %d: ",++casenumber);
		if(dp[T][n]==INF) printf("impossible\n");
		else printf("%d\n",dp[T][n]);
	}
}
