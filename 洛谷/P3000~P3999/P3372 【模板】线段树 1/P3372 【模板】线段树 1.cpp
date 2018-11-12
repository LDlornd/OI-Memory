#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;
typedef long long int ll;
const int MAXN=100001;
ll a[MAXN];
struct segtree
{
	segtree *leftson,*rightson;
	int start,end;
	ll val,lazy;
	segtree()
	{
		leftson=rightson=NULL;
		start=end=val=lazy=0;
	}
	inline void update()
	{
		val=leftson->val+rightson->val;
	}
	inline void cal(ll num)
	{
		val+=(end-start+1)*num;
	}
	inline void pushdown()
	{
		leftson->cal(lazy);
		rightson->cal(lazy);
		leftson->lazy+=lazy;
		rightson->lazy+=lazy;
		lazy=0;
	}
	inline void build(int Left,int Right)
	{
		start=Left;end=Right;
		if(Left==Right) {val=a[Left];return;}
		int mid=(Left+Right)>>1;
		(leftson=new(segtree))->build(Left,mid);
		(rightson=new(segtree))->build(mid+1,Right);
		update();
	}
	inline void modify(int Left,int Right,ll add)
	{
		if(start==Left&&end==Right)
		{
			lazy+=add;
			cal(add);
			return;
		}
		pushdown();
		int mid=(start+end)>>1;
		if(Right<=mid) leftson->modify(Left,Right,add);
		else if(Left>mid) rightson->modify(Left,Right,add);
		else {leftson->modify(Left,mid,add);rightson->modify(mid+1,Right,add);}
		update();
	}
	inline ll query(int Left,int Right)
	{
		if(start==Left&&end==Right) return val;
		pushdown();
		int mid=(start+end)>>1;
		if(Right<=mid) return leftson->query(Left,Right);
		else if(Left>mid) return rightson->query(Left,Right);
		else return (leftson->query(Left,mid)+rightson->query(mid+1,Right));
	}
}*root;
template<typename T>
inline T read()
{
	T x=0,f=1;
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
	int n=read<int>(),m=read<int>();
	for(int i=1;i<=n;++i)
		a[i]=read<ll>();
	(root=new(segtree))->build(1,n);
	int opt,x,y;
	ll k;
	for(int i=1;i<=m;++i)
	{
		opt=read<int>();x=read<int>();y=read<int>();
		if(opt==1)
		{
			k=read<ll>();
			root->modify(x,y,k);
		}
		else printf("%lld\n",root->query(x,y));
	}
	return 0;
}
