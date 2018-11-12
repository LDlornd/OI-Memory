#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN=200001;
char opt;
int n,m,u,v;
int grade[MAXN];
struct segtree
{
	segtree *leftson,*rightson;
	int val,start,end;
	segtree()
	{
		leftson=rightson=NULL;
		val=start=end=0;
	}
	inline void update()
	{
		val=max(leftson->val,rightson->val);
	}
	inline void build(int nstart,int nend)
	{
		start=nstart;end=nend;
		if(nstart==nend) {val=grade[nstart];return;}
		int mid=(nstart+nend)>>1;
		(leftson=new(segtree))->build(nstart,mid);
		(rightson=new(segtree))->build(mid+1,nend);
		update();
	}
	inline void modify(int place,int k)
	{
		if(start==place&&end==place) {val=k;return;}
		int mid=(start+end)>>1;
		if(place<=mid) leftson->modify(place,k);
		else rightson->modify(place,k);
		update();
	}
	inline int query(int nstart,int nend)
	{
		if(start==nstart&&end==nend) return val;
		int mid=(start+end)>>1;
		if(nend<=mid) return leftson->query(nstart,nend);
		else if(nstart>mid) return rightson->query(nstart,nend);
		else return max(leftson->query(nstart,mid),rightson->query(mid+1,nend));
	}
}*root;
inline int read()
{
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
	return x*f;
}
int main()
{
	n=read();m=read();
	for(int i=1;i<=n;++i) grade[i]=read();
	(root=new(segtree))->build(1,n);
	while(m--)
	{
		opt=0;while(opt!='Q'&&opt!='U') opt=getchar();
		u=read();v=read();
		if(opt=='Q') printf("%d\n",root->query(u,v));
		else if(grade[u]<v) root->modify(u,grade[u]=v);
	}
	return 0;
}
