#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;
typedef long long int ll;
const int MAXN=100001;
ll a[MAXN];
int n,m,mod;
struct segtree
{
	segtree *leftson,*rightson;
	int start,end;
	ll val,addlazy,multilazy;
	segtree()
	{
		leftson=rightson=NULL;
		start=end=val=addlazy=0;
		multilazy=1;
	}
	inline void calculate(ll add,ll multi)
	{
		multilazy=multilazy*multi%mod;
		addlazy=addlazy*multi%mod;
		addlazy=(addlazy+add)%mod;
		val=(val*multi%mod+add*(end-start+1)%mod)%mod;
	}
	inline void update()
	{
		val=(leftson->val+rightson->val)%mod;
	}
	inline void pushdown()
	{
		leftson->calculate(addlazy,multilazy);
		rightson->calculate(addlazy,multilazy);
		addlazy=0;multilazy=1;
	}
	inline void build(int nstart,int nend)
	{
		start=nstart;end=nend;
		if(nstart==nend) {val=a[nstart]%mod;return;}
		int mid=(nstart+nend)>>1;
		(leftson=new(segtree))->build(nstart,mid);
		(rightson=new(segtree))->build(mid+1,nend);
		update();
	}
	inline void modify(int nstart,int nend,ll add,ll multi)
	{
		if(start==nstart&&end==nend) {calculate(add,multi);return;}
		pushdown();
		int mid=(start+end)>>1;
		if(nend<=mid) leftson->modify(nstart,nend,add,multi);
		else if(nstart>mid) rightson->modify(nstart,nend,add,multi);
		else {leftson->modify(nstart,mid,add,multi);rightson->modify(mid+1,nend,add,multi);}
		update();
	}
	inline ll query(int nstart,int nend)
	{
		if(start==nstart&&end==nend) return val;
		pushdown();
		int mid=(start+end)>>1;
		if(nend<=mid) return leftson->query(nstart,nend);
		else if(nstart>mid) return rightson->query(nstart,nend);
		else return (leftson->query(nstart,mid)+rightson->query(mid+1,nend))%mod;
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
	n=read<int>(),m=read<int>(),mod=read<int>();
	for(int i=1;i<=n;++i)
		a[i]=read<ll>();
	(root=ne
	w(segtree))->build(1,n);
	int opt,x,y,k;
	for(int i=1;i<=m;++i)
	{
		opt=read<int>();x=read<int>();y=read<int>();
		if(opt==1) {k=read<ll>();root->modify(x,y,0,k);}
		else if(opt==2) {k=read<ll>();root->modify(x,y,k,1);}
		else if(opt==3) {printf("%lld\n",root->query(x,y));}
	}
	return 0;
}
