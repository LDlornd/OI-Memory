#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=200002;
int n,m,k,nl=1,nr=0,tempans=0;
int array[MAXN],ans[MAXN],vis[MAXN];
struct que
{
	int start,end,block,rank;
	que() {start=0;end=0;}
}Q[MAXN];
inline void add(int key)
{
	if(key>n+1) return;
	++vis[key];
	if(tempans==key)
		while(vis[tempans]) ++tempans;
}
inline void del(int key)
{
	if(key>n+1) return;
	--vis[key];
	if(vis[key]==0) tempans=min(tempans,key);
}
inline bool CMP(const que &a,const que &b)
{
	if(a.block==b.block) return a.end<b.end;
	return a.block<b.block;
}
inline int read()
{
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
	return x*f;
}
int main()
{
	memset(vis,0,sizeof(vis));
	n=read();m=read();
	k=sqrt(n);
	for(int i=1;i<=n;++i) array[i]=read();
	for(int i=1;i<=m;++i)
	{
		Q[i].start=read();Q[i].end=read();
		Q[i].block=Q[i].start/k+1;
		Q[i].rank=i;
	}
	sort(Q+1,Q+m+1,CMP);
	for(int i=1;i<=m;++i)
	{
		int nstart=Q[i].start,nend=Q[i].end;
		while(nl<nstart) del(array[nl++]);
		while(nl>nstart) add(array[--nl]);
		while(nr<nend) add(array[++nr]);
		while(nr>nend) del(array[nr--]);
		ans[Q[i].rank]=tempans;
	}
	for(int i=1;i<=m;++i)
		printf("%d\n",ans[i]);
	return 0;
}
