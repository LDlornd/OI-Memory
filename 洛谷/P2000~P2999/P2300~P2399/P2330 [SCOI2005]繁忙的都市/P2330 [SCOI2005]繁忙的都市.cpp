#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN1=50001;
const int MAXN2=301;
struct edge
{
	int start,end,worth;
}con[MAXN1];
int fa[MAXN2],size[MAXN2];
inline bool CMP(const edge &a,const edge &b)
{
	return a.worth<b.worth;
}
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
	int n,m,ans=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
		scanf("%d%d%d",&con[i].start,&con[i].end,&con[i].worth);
	sort(con+1,con+m+1,CMP);
	for(int i=1;i<=n;++i) {fa[i]=i;size[i]=1;}
	for(int i=1;i<=m;++i)
	{
		if(getfa(con[i].start)==getfa(con[i].end)) continue;
		ans=con[i].worth;
		Merge(con[i].start,con[i].end);
	}
	printf("%d %d",n-1,ans);
	return 0;
}
