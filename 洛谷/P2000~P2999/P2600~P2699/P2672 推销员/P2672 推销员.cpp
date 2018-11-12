#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int MAXN=100001;
int dis[MAXN],tired[MAXN];

struct maxnum
{
	int data,place;
	maxnum(int kk=0,int kkk=0) {data=kk;place=kkk;}
};
inline maxnum MAX(const maxnum,const maxnum);
inline int read();
struct segtree
{
	segtree *leftson,*rightson;
	int start,end;
	maxnum flag;
	segtree()
	{
		leftson=rightson=NULL;
		start=end=0;
	}
	inline void update()
	{
		//val=max(leftson->val,rightson->val);
		int ml=leftson->flag.data,mr=rightson->flag.data;
		if(ml>mr)
		{
			flag.data=ml;flag.place=leftson->flag.place;
		}
		else
		{
			flag.data=mr;flag.place=rightson->flag.place;
		}
	}
	inline void build(int nstart,int nend)
	{
		start=nstart;end=nend;
		if(nstart==nend)
		{
			flag.data=tired[nstart];flag.place=nstart;return;
		}
		int mid=(nstart+nend)>>1;
		(leftson=new(segtree))->build(nstart,mid);
		(rightson=new(segtree))->build(mid+1,nend);
		update();
	}
	inline void modify(int nstart,int nend,int k)
	{
		if(nstart==start&&nend==end) {flag.data=k;return;}
		int mid=(start+end)>>1;
		if(nend<=mid) leftson->modify(nstart,nend,k);
		else if(nstart>mid) rightson->modify(nstart,nend,k);
		update(); 
	}
	inline maxnum query(int nstart,int nend)
	{
		if(start==nstart&&end==nend) return flag;
		int mid=(start+end)>>1;
		if(nend<=mid) return leftson->query(nstart,nend);
		else if(nstart>mid) return rightson->query(nstart,end);
		else return MAX(leftson->query(nstart,mid),rightson->query(mid+1,nend));
	}
}*root;
inline maxnum MAX(const maxnum &a,const maxnum &b)
{
	if(a.data>b.data) return a;
	else return b;
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
	int n=read();
	for(int i=1;i<=n;++i) dis[i]=read();
	for(int i=1;i<=n;++i) tired[i]=read();
	(root=new(segtree))->build(1,n);
	for(int i=1;i<=n;++i)
	{
		maxnum leftmax,rightmax;
		if(i==1) leftmax.data=leftmax.place=0;
		else leftmax=root->query(1,n);
		
	}
	return 0;
}
