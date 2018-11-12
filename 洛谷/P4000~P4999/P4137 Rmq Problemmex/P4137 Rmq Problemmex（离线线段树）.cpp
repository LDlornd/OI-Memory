#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=200010;
int n,m,now=1;
int array[MAXN],mex[MAXN];
int last[MAXN],NEXT[MAXN];
int ans[MAXN];
bool vis[MAXN];
struct que
{
	int ql,qr,id;
	que() {ql=0;qr=0;id=0;}
}Q[MAXN];
struct segtree
{
	segtree *leftson,*rightson;
	int start,end;
	int val;
	segtree()
	{
		leftson=rightson=NULL;
		start=end=0;
		val=MAXN;
	}
	inline void pushdown()
	{
		if(start==end) return;
		if(leftson) leftson->val=min(leftson->val,val);
		if(rightson) rightson->val=min(rightson->val,val);
	}
	inline void build(int nstart,int nend)
	{
		start=nstart;end=nend;
		if(nstart==nend) {val=mex[start];return;}
		int mid=(nstart+nend)>>1;
		(leftson=new(segtree))->build(nstart,mid);
		(rightson=new(segtree))->build(mid+1,nend);
	}
	inline void modify(int nstart,int nend,int key)
	{
		if(start==nstart&&end==nend)
		{
			val=min(val,key);
			pushdown();
			return;
		}
		int mid=(start+end)>>1;
		if(nend<=mid) leftson->modify(nstart,nend,key);
		else if(nstart>mid) rightson->modify(nstart,nend,key);
		else {leftson->modify(nstart,mid,key);rightson->modify(mid+1,nend,key);}
	}
	inline int query(int place)
	{
		if(start==place&&end==place) return val;
		pushdown();
		int mid=(start+end)>>1;
		if(place<=mid) return leftson->query(place);
		else return rightson->query(place);
	}
	/*inline void bianli()
	{
		if(start==end) cout<<start<<" "<<end<<" "<<val<<endl;
		if(leftson) leftson->bianli();
		if(rightson) rightson->bianli();
	}*/
}*root;
inline bool CMP(const que &a,const que &b)
{
	return a.ql<b.ql;
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
	for(int i=1;i<=n;++i)
	{
		array[i]=read();
		array[i]=min(array[i],n+1);
		vis[array[i]]=true;
		if(now==array[i])
			while(vis[now]) ++now;
		mex[i]=now;last[i]=n+1;
	}
	last[0]=n+1;
	(root=new(segtree))->build(1,n);
	//root->bianli();
	for(int i=n;i>=1;--i)
		{NEXT[i]=last[array[i]];last[array[i]]=i;}
	for(int i=1;i<=m;++i)
		{Q[i].ql=read();Q[i].qr=read();Q[i].id=i;}
	sort(Q+1,Q+m+1,CMP);
	now=1;
	for(int i=1;i<=m;++i)
	{
		int nl=Q[i].ql,nr=Q[i].qr;
		while(now<nl)
		{
			root->modify(now,NEXT[now]-1,array[now]);
			++now;
		}
		//cout<<"#################"<<Q[i].ql<<" "<<Q[i].qr<<" "<<Q[i].id<<endl;
		//root->bianli();
		ans[Q[i].id]=root->query(nr);
	}
	for(int i=1;i<=m;++i)
		printf("%d\n",ans[i]);
	return 0;
}
