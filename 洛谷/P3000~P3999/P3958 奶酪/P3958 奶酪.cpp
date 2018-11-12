#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long int ll;
const int MAXN=1005;
ll rx[MAXN],ry[MAXN],rz[MAXN];
int fa[MAXN],size[MAXN];
inline ll getdis(int pa,int pb)
{
	return (rx[pa]-rx[pb])*(rx[pa]-rx[pb])+(ry[pa]-ry[pb])*(ry[pa]-ry[pb])+(rz[pa]-rz[pb])*(rz[pa]-rz[pb]);
}
inline int getfa(int a)
{
	if(fa[a]==a) return a;
	else return fa[a]=getfa(fa[a]);
}
inline void Merge(int a,int b)
{
	int na=getfa(a),nb=getfa(b);
	if(size[na]<size[nb]) swap(na,nb);
	fa[nb]=na;size[na]+=size[nb];
}
template<typename T>
inline T read()
{
	T x=0,f=1;
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
	freopen("cheese5.in","r",stdin);
	int T=read<int>();
	for(int w=1;w<=T;++w)
	{
		int n=read<int>();
		ll h=read<ll>(),r=read<ll>();
		for(int i=0;i<=n+1;++i) {fa[i]=i;size[i]=1;}
		for(int i=1;i<=n;++i)
		{
			rx[i]=read<ll>();ry[i]=read<ll>();rz[i]=read<ll>();
			if(rz[i]<=r&&getfa(i)!=getfa(0)) Merge(i,0);
			if(rz[i]+r>=h&&getfa(i)!=getfa(n+1)) Merge(i,n+1);
		}
		for(int i=1;i<=n;++i)
			for(int j=1;j<i;++j)
				if(getdis(i,j)<=4*r*r&&getfa(i)!=getfa(j)) Merge(i,j);
		if(getfa(0)==getfa(n+1)) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
