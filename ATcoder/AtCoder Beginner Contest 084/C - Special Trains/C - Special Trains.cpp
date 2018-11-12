#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=501;
int n,dp[MAXN][MAXN];
int C[MAXN],S[MAXN],F[MAXN];
inline int read()
{
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
	return x*f;
}
int main()
{
	n=read();
	for(int i=1;i<n;++i)
		{C[i]=read();S[i]=read();F[i]=read();}
	for(int i=1;i<n;++i)
	{
		int ans=0;
		for(int j=i;j<n;++j)
		{
			int temp=0;
			while(ans>S[j]+F[j]*temp) ++temp;
			ans=S[j]+F[j]*temp;
			ans+=C[j];
		}
		printf("%d\n",ans);
	}
	printf("0");
	return 0;
}
