#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
typedef long long int ll;
const int MAXN=1002;
int q,n,m;
ll val[MAXN][MAXN];
template<typename T>
inline T read()
{
	T x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') f=1;c=getchar();}
	while(c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
	return x*f;
}
int main()
{
	q=read<int>();
	while(q--)
	{
		memset(val,0,sizeof(val));
		n=read<int>();m=read<int>();
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				val[i][j]=read<ll>();
		for(int i=n;i>=1;--i)
			for(int j=1;j<=m;++j)
				val[i][j]=max(val[i][j]+val[i+1][j-1],max(val[i][j-1],val[i+1][j]));
		printf("%lld\n",val[1][m]);
	}
	return 0;
}
