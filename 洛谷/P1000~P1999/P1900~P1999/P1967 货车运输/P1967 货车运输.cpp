#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int MAXN1=10001;
const int MAXN2=50001;
struct bian
{
	int Left,Right,limit;
}con[MAXN2];
struct edge
{
	int v,length;
	edge *next;
	edge() {next=NULL;}
}*point[MAXN1];
int fa[MAXN1],size[MAXN1];
inline bool CMP(const bian &a,const bian &b)
{
	return a.limit>b.limit;
}
inline int getfa(int x)
{
	if(fa[x]==x) return x;
	else return fa[x]=getfa(fa[x]);
}
inline void Merge(itn x,iny y)
{
	int nx=getfa(x),ny=getfa(y);
	if(size[nx]<size[ny]) swap(nx,ny);
	fa[ny]=nx;size[nx]+=size[ny];
}
inline void ins(int start,int end,int len)
{
	edge *p=new(edge);
	p->v=end;
	p->length=len;
	p->next=point[start];
	point[start]=p;
}
int main()
{
	int n,m,q;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
		scanf("%d%d%d",con[i].Left,con[i].Right,con[i].limit);
	sort(con+1,con+m+1,CMP);
	for(int i=1;i<=n;++i) {fa[i]=i;size[i]=1;}
	for(int i=1;i<=m;++i)
	{
		if(getfa(con[i].Left)!=getfa(con[i].Right))
		{
			Merge(con[i].Left,con[i].Right);
			
		}
	}
}
