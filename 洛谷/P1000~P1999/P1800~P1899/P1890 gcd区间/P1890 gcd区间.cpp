#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;
const int MAXN=1001;
int a[MAXN];
inline int gcd(int,int);
inline int read();
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
		val=gcd(leftson->val,rightson->val);
	}
	inline void build(int nstart,int nend)
	{
		start=nstart;end=nend;
		if(nstart==nend) {val=a[nstart];return;}
		int mid=(nstart+nend)>>1;
		(leftson=new(segtree))->build(nstart,mid);
		(rightson=new(segtree))->build(mid+1,nend);
		update();
	}
	inline int query(int nstart,int nend)
	{
		if(start==nstart&&end==nend) return val;
		int mid=(start+end)>>1;
		if(nend<=mid) return leftson->query(nstart,nend);
		else if(nstart>mid) return rightson->query(nstart,nend);
		else return gcd(leftson->query(nstart,mid),rightson->query(mid+1,nend));
	}
}*root;
inline int gcd(int x,int y)
{
	if(y==0) return x;
	else return gcd(y,x%y);
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
	int n=read(),m=read();
	for(int i=1;i<=n;++i)
		a[i]=read();
	(root=new(segtree))->build(1,n);
	while(m--)
	{
		int fx=read(),fy=read();
		printf("%d\n",root->query(fx,fy));
	}
	return 0;
}
