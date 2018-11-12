#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=1000001;
int a[MAXN],sum[MAXN];
int qmin[MAXN],hmin[MAXN];
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
	int tot=0,ans=0;
	int n=read();
	qmin[0]=0;
	for(int i=1;i<=n;++i)
	{
		a[i]=read();
		tot+=a[i];
		qmin[i]=min(qmin[i-1],tot);
	}
	sum[n]=a[n];hmin[n]=a[n];
	for(int i=n-1;i>=1;--i)
	{
		sum[i]=sum[i+1]+a[i];
		hmin[i]=min(a[i],hmin[i+1]+a[i]);
	}
	for(int i=1;i<=n;++i)
		if(hmin[i]>=0&&qmin[i-1]+sum[i]>=0) ++ans;
	printf("%d",ans);
	return 0;
}
