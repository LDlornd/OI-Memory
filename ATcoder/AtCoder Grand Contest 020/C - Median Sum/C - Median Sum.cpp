#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int MAXN1=2001;
const int MAXN2=4000001;
int n,tot=0,sum=0;
int a[MAXN1],canget[MAXN2];
bool flag[MAXN2];
inline int read()
{
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
	return x*f;
}
int main()
{
	freopen("testdata.in","r",stdin);
	memset(flag,0,sizeof(flag));
	n=read();
	for(int i=1;i<=n;++i) sum+=(a[i]=read());
	if(sum&1) ++sum;sum/=2;
	flag[0]=true;canget[++tot]=0;
	for(int i=1;i<=n;++i)
	{
		int temp=tot;
		for(int j=1;j<=temp;++j)
		{
			int k=a[i]+canget[j];
			if(flag[k]==false)
			{
				flag[k]=true;
				if(k<sum) canget[++tot]=k;
			}
		}
	}
	for(int i=sum;i<MAXN2;++i)
		if(flag[i])
		{
			printf("%d",i);
			return 0;
		}
}
