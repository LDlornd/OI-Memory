#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN1=101;
const int MAXN2=10001;
struct edge
{
	int start,end,len;
}con[MAXN2];
int fa[MAXN1],size[MAXN1];
inline bool CMP(const edge &a,const edge &b)
{
	return a.len<b.len;
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
	int n,k,ans=0,num=0;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
		{
			scanf("%d",&k);
			if(j<=i) continue;
			++num;
			con[num].start=i;
			con[num].end=j;
			con[num].len=k;
		}
	sort(con+1,con+num+1,CMP);
	for(int i=1;i<=n;++i) {fa[i]=i;size[i]=1;}
	for(int i=1;i<=num;++i)
		if(getfa(con[i].start)!=getfa(con[i].end))
			{ans+=con[i].len;Merge(con[i].start,con[i].end);}
	printf("%d",ans);
	return 0;
}
