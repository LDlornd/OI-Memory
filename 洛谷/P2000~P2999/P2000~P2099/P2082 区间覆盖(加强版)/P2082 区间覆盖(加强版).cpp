#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100001;
struct range
{
	int head,tail;
}a[MAXN];
inline bool CMP(const range &x,const range &y)
{
	return x.head<y.head;
}
inline int read()
{
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
	return x;
}
int main()
{
	int n=read();
	for(int i=1;i<=n;++i)
		{a[i].head=read();a[i].tail=read();}
	sort(a+1,a+n+1,CMP);
	int nlen=0,nstart=a[1].head,nend=a[1].tail;
	for(int i=2;i<=n;++i)
	{
		if(a[i].head>nend)
		{
			nlen+=(nend-nstart+1);
			nstart=a[i].head;
			nend=a[i].tail;
		}
		else if(a[i].tail>nend) nend=a[i].tail;
	}
	nlen+=(nend-nstart+1);
	printf("%d",nlen);
	return 0;
}
