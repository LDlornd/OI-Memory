#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int MAXN1=301;
const int MAXN2=1e5+1;
int n,H,W,D,Q,key,Start,End;
struct place{
	int I,J;
	place(int ii=0,int jj=0) {I=ii;J=jj;}
}num[MAXN1*MAXN1];
int dp[MAXN1*MAXN1];
inline int getdist(int x,int y)
{
	return abs(num[x].I-num[y].I)+abs(num[x].J-num[y].J);
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
	memset(dp,0,sizeof(dp));
	H=read();W=read();n=H*W;
	D=read();
	for(int i=1;i<=H;++i)
		for(int j=1;j<=W;++j)
			{key=read();num[key]=place(i,j);}
	Q=read();
	for(int i=1;i<=n;++i){
		if(i<=D) dp[i]=getdist(0,i);
		else dp[i]=dp[i-D]+getdist(i-D,i);
	}
	for(int i=1;i<=Q;++i){
		Start=read();End=read();
		printf("%d\n",dp[End]-dp[Start]);
	}
	return 0;
}
