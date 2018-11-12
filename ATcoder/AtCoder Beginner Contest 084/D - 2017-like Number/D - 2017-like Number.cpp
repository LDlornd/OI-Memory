#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int MAXN=100001;
int Q,L,R,primenum=0;
int prime[MAXN],ans[MAXN];
bool flag[MAXN];
inline void getready()
{
	memset(ans,0,sizeof(ans));
	memset(flag,0,sizeof(flag));
	flag[0]=flag[1]=true;
	for(int i=2;i<MAXN;++i)
	{
		if(flag[i]==false) prime[++primenum]=i;
		for(int j=1;j<=primenum&&i*prime[j]<MAXN;++j)
		{
			flag[i*prime[j]]=true;
			if(i%prime[j]==0) break;
		}
	}
	for(int i=1;i<MAXN;++i)
		if(flag[i]==false&&flag[(i+1)>>1]==false) ans[i]=1;
	for(int i=1;i<MAXN;++i)
		ans[i]+=ans[i-1];
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
	getready();
	Q=read();
	while(Q--)
	{
		L=read();R=read();
		printf("%d\n",ans[R]-ans[L-1]);
	}
	return 0;
}
