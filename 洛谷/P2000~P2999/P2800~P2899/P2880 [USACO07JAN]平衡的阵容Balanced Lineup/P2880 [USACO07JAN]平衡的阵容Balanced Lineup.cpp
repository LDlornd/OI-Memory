#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int MAXN=50001;
int height[MAXN];
struct segtree
{
	segtree *leftson,*rightson;
	int start,end,maxval,minval;
	segtree()
	{
		leftson=rightson=NULL;
		start=end=maxval=minval=0;
	}
	inline void update()
	{
		maxval=max(leftson->maxval,rightson->maxval);
		minval=min(leftson->minval,rightson->minval);
	}
	inline void build(int nstart,int nend)
	{
		start=nstart;end=nend;
		if(nstart==nend) {maxval=minval=height[nstart];return;}
		int mid=(nstart+nend)>>1;
		(leftson=new(segtree))->build(nstart,mid);
		(rightson=new(segtree))->build(mid+1,nend);
		update();
	}
	inline int query_max(int nstart,int nend)
	{
		if(start==nstart&&end==nend) return maxval;
		int mid=(start+end)>>1;
		if(nend<=mid) return leftson->query_max(nstart,nend);
		else if(nstart>mid) return rightson->query_max(nstart,nend);
		else return max(leftson->query_max(nstart,mid),rightson->query_max(mid+1,nend));
	}
	inline int query_min(int nstart,int nend)
	{
		if(start==nstart&&end==nend) return minval;
		int mid=(start+end)>>1;
		if(nend<=mid) return leftson->query_min(nstart,nend);
		else if(nstart>mid) return rightson->query_min(nstart,nend);
		else return min(leftson->query_min(nstart,mid),rightson->query_min(mid+1,nend));
	}
}*root;
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
	int n=read(),q=read();
	for(int i=1;i<=n;++i)
		height[i]=read();
	(root=new(segtree))->build(1,n);
	while(q--)
	{
		int x=read(),y=read();
		printf("%d\n",root->query_max(x,y)-root->query_min(x,y));
	}
	return 0;
}
