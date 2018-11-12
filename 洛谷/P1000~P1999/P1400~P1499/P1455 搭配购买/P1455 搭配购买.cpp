#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=10001;
int n,m,u,v,money;
int cost[MAXN],value[MAXN],ans[MAXN];
int fa[MAXN],size[MAXN];
struct need
{
	int pay,val;
	need() {pay=0;val=0;}
}arr[MAXN];
struct edge
{
	int start,end;
	edge(int ss=0,int ee=0) {start=ss;end=ee;}
};
inline int getfa(int x)
{
	if(fa[x]==x) return x;
	else return getfa(fa[x]);
}
inline void Merge(int x,int y)
{
	int nx=getfa(x),ny=getfa(y);
	if(size[nx]<size[ny]) swap(nx,ny);
	fa[ny]=nx;size[nx]+=size[ny];
}
inline bool CMP(const need &x,const need &y)
{
	return x.val>y.val;
}
inline int read()
{
	int x=0,f=1;
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
	memset(ans,0,sizeof(ans));
	n=read();m=read();money=read();
	for(int i=1;i<=n;++i)
	{
		fa[i]=i;size[i]=1;
		cost[i]=read();value[i]=read();
	}
	while(m--)
	{
		u=read();v=read();
		if(getfa(u)!=getfa(v)) Merge(u,v);
	}
	for(int i=1;i<=n;++i)
	{
		int nv=getfa(i);
		arr[nv].pay+=cost[i];
		arr[nv].val+=value[i];
	}
	sort(arr+1,arr+n+1,CMP);
	for(int i=1;i<=n&&arr[i].val!=0;++i)
		for(int j=money;j>=arr[i].pay;--j)
			ans[j]=max(ans[j],ans[j-arr[i].pay]+arr[i].val);
	printf("%d",ans[money]);
	return 0;
}
