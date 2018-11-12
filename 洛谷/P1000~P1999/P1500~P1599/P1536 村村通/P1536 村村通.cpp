#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN1=1001;
int fa[MAXN1],size[MAXN1];
inline int getfa(int x)
{
	if(fa[x]==x) return x;
	else return fa[x]=getfa(fa[x]);
}
inline void Merge(int x,int y)
{
	int nx=getfa(x),ny=getfa(y);
	if(size[nx]<size[ny]) swap(nx,ny);
	fa[ny]=nx;size[nx]+=size[ny];
}
int main()
{
	int m,n,num,Left,Right;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0) return 0;
		num=-1;
		scanf("%d",&m);
		for(int i=1;i<=n;++i) {fa[i]=i;size[i]=1;}
		for(int i=1;i<=m;++i)
		{
			scanf("%d%d",&Left,&Right);
			if(getfa(Left)!=getfa(Right)) Merge(Left,Right);
		}
		for(int i=1;i<=n;++i)
			if(fa[i]==i) ++num;
		printf("%d\n",num);
	}
	return 0;
}
