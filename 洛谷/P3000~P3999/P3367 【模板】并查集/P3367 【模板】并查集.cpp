#include<cstdio>
#include<iostream>
using namespace std;
int fa[10001],size[10001];
inline int Find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=Find(fa[x]);
}
inline void merge(int x,int y)
{
	int nx=Find(x),ny=Find(y);
	if(size[nx]<size[ny]) swap(nx,ny);
	fa[ny]=nx;size[nx]+=size[ny];
}
int main()
{
	int n,m,caozuo,kx,ky;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		{fa[i]=i;size[i]=1;}
	for(int w=0;w<m;++w)
	{
		scanf("%d%d%d",&caozuo,&kx,&ky);
		if(caozuo==1) merge(kx,ky);
		if(caozuo==2)
		{
			if(Find(kx)==Find(ky)) printf("Y\n");
			else printf("N\n");
		}
	}
	return 0;
}
