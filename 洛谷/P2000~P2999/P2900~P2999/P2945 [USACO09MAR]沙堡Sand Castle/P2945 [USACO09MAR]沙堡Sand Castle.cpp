#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=25001;
int n,up,down,ans=0;
int height[MAXN],hope[MAXN];
inline bool CMP(int a,int b)
{
	return a<b;
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
	n=read();up=read();down=read();
	for(int i=1;i<=n;++i)
		{height[i]=read();hope[i]=read();}
	sort(height+1,height+n+1,CMP);
	sort(hope+1,hope+n+1,CMP);
	for(int i=1;i<=n;++i)
		if(height[i]>hope[i]) ans+=down*(height[i]-hope[i]);
		else if(height[i]<hope[i]) ans+=up*(hope[i]-height[i]);
	printf("%d",ans);
	return 0;
}
