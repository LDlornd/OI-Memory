#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int MAXN1=101;
const int MAXN2=100001;
int a[MAXN1],flag[MAXN1],ans[MAXN2];
inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
	return x*f;
}
int main()
{
	memset(flag,0,sizeof(flag));
	memset(ans,0,sizeof(ans));
	int n=read(),xishu=read(),now=1;
	for(int i=1;i<=n;++i)
		a[i]=read();
	ans[0]=1;
	while(now<=xishu)
	{
		int MIN=2147483647,place=0;
		for(int i=1;i<=n;++i)
		{
			int temp=a[i]*ans[flag[i]];
			if(temp<MIN)
				{MIN=temp;place=i;}
		}
		++flag[place];
		if(MIN!=ans[now-1]) ans[now++]=MIN;
	}
	printf("%d",ans[xishu]);
	return 0;
}
