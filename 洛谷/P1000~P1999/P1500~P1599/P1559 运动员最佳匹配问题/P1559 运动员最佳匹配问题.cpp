#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=21;
const int INF=2147483647;
int n,lack,ans=0;
int advan[MAXN][MAXN];
int lx[MAXN],ly[MAXN],flag[MAXN];
bool visx[MAXN],visy[MAXN];
inline bool Find(int placex)
{
	visx[placex]=true;
	for(int placey=1;placey<=n;++placey)
	{
		if(visy[placey]) continue;
		int t=lx[placex]+ly[placey]-advan[placex][placey];
		if(t<=0)
		{
			visy[placey]=true;
			if(flag[placey]==0||Find(flag[placey]))
			{
				flag[placey]=placex;
				return true;
			}
		}
		else lack=min(lack,t);
	}
	return false;
}
inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') c=getchar();
		c=getchar();
	}
	while(c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
	return x*f;
}
int main()
{
	memset(flag,0,sizeof(flag));
	n=read();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			advan[i][j]=read();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
		{
			advan[j][i]*=read();
			lx[j]=max(lx[j],advan[j][i]);
		}
	for(int w=1;w<=n;++w)
	{
		while(true)
		{
			memset(visx,0,sizeof(visx));
			memset(visy,0,sizeof(visy));
			lack=INF;
			if(Find(w)) break;
			for(int i=1;i<=n;++i)
			{
				if(visx[i]) lx[i]-=lack;
				if(visy[i]) ly[i]+=lack;
			}
		}
	}
	for(int i=1;i<=n;++i)
		ans+=(lx[i]+ly[i]);
	printf("%d",ans);
	return 0;
}
