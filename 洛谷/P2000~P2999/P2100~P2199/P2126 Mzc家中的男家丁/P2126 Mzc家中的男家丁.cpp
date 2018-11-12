#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;
const int MAXN1=2301;
const int MAXN2=400001;
struct edge
{
	int start,end,length;
}con[MAXN2];
int fa[MAXN1],size[MAXN1];
inline bool CMP(const edge &a,const edge &b)
{
	return a.length<b.length; 
}
inline int getfa(int x)
{
	if(fa[x]==x) return x;
	else return fa[x]=getfa(fa[x]);
}
inline void merge(int x,int y)
{
	int nx=getfa(x),ny=getfa(y);
	if(size[nx]<size[ny]) swap(nx,ny);
	fa[ny]=nx;size[nx]+=size[ny];
}
int main()
{
	int n,m,num=0,ans=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		{fa[i]=i;size[i]=1;}
	for(int i=1;i<=m;++i)
		scanf("%d%d%d",&con[i].start,&con[i].end,&con[i].length);
	sort(con+1,con+m+1,CMP);
	for(int i=0;i<=m;++i)
	{
		if(getfa(con[i].start)!=getfa(con[i].end))
		{
			merge(con[i].start,con[i].end);
			//fa[con[i].end]=getfa(con[i].start);
			ans+=con[i].length;
			++num;
		}
		if(num==n) break;
	}
	printf("%d",ans);
	return 0;
}
