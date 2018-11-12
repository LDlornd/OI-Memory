#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
typedef long long int ll;
char opt,s[10];
int q,tot=0;
ll ans=0,num,mod;
struct segtree
{
	ll val;
	int start,end;
	segtree *leftson,*rightson;
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
		if(nstart==nend) {val=-999999999;return;}
		int mid=(nstart+nend)>>1;
		(leftson=new(segtree))->build(nstart,mid);
		(rightson=new(segtree))->build(mid+1,nend);
		update();
	}
	inline void modify(int place,ll k)
	{
		if(start==place&&end==place)
			{val=k;return;}
		int mid=(start+end)>>1;
		if(mid>=place) leftson->modify(place,k);
		else rightson->modify(place,k);
		update();
	}
	inline ll query(int nstart,int nend)
	{
		if(start==nstart&&end==nend) return val;
		int mid=(start+end)>>1;
		if(mid>=nend) return leftson->query(nstart,nend);
		else if(mid<nstart) return rightson->query(nstart,nend);
		else return max(leftson->query(nstart,mid),rightson->query(mid+1,nend));
	}
}*root;
int main()
{
	scanf("%d%lld\n",&q,&mod);
	(root=new(segtree))->build(1,q);
	while(q--)
	{
		scanf("%s",s);scanf("%lld",&num);
		int len=strlen(s);
		for(int i=0;i<len;++i)
			if(s[i]=='A'||s[i]=='Q') {opt=s[i];break;}
		if(opt=='A') root->modify(++tot,(num+ans)%mod);
		else if(opt=='Q')
		{
			if(tot==0||num==0)
			{
				ans=0;
				printf("%lld\n",ans);
				continue;
			}
			ans=root->query(tot-num+1,tot);
			printf("%lld\n",ans);
		}
	}
	return 0;
}
