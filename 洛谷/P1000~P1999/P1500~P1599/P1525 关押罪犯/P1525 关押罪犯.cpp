#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN1=20001;
const int MAXN2=100001;
struct edge
{
	int Left,Right,length;
}con[MAXN2];
int n,m;
int fa[MAXN1],size[MAXN1],e[MAXN1];
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
inline bool CMP(const edge &a,const edge &b)
{
	return a.length>b.length;
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
	n=read();m=read();
	for(int i=1;i<=m;++i)
		{con[i].Left=read();con[i].Right=read();con[i].length=read();}
	sort(con+1,con+m+1,CMP);
	for(int i=1;i<=n;++i) {fa[i]=i;size[i]=1;e[i]=0;}
	for(int i=1;i<=m;++i)
	{
		int ll=con[i].Left,rr=con[i].Right,nl=getfa(ll),nr=getfa(rr);
		if(nl==nr) {printf("%d",con[i].length);return 0;}
		else if(e[ll]!=0&&e[rr]!=0) {Merge(ll,e[rr]);Merge(rr,e[ll]);}
		else if(e[ll]==0&&e[rr]!=0) {e[ll]=rr;Merge(ll,e[rr]);}
		else if(e[ll]!=0&&e[rr]==0) {e[rr]=ll;Merge(rr,e[ll]);}
		else if(e[ll]==0&&e[rr]==0) {e[rr]=ll;e[ll]=rr;}
	}
	printf("0");
	return 0;
}
