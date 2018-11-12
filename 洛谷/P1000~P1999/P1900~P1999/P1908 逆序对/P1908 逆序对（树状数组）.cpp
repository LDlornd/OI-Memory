#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=40005;
struct num
{
	int val,rank;
	num() {val=rank=0;}
}NUM[MAXN];
int res[MAXN],treearray[MAXN];
int n,ans=0;
inline void modify(int place,int k)
{
	for(;place<=n;place+=(place&-place))
		treearray[place]+=k;
}
inline int query(int place)
{
	int tot=0;
	for(;place;place-=(place&-place))
		tot+=treearray[place];
	return tot;
}
inline bool CMP(const num &a,const num &b)
{
	return a.val<b.val;
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
	memset(treearray,0,sizeof(treearray));
	n=read();
	for(int  i=1;i<=n;++i)
		{NUM[i].val=read();NUM[i].rank=i;}
	sort(NUM+1,NUM+n+1,CMP);
	for(int i=1;i<=n;++i)
		res[NUM[i].rank]=i;
	for(int i=n;i>=1;--i)
	{
		ans+=query(res[i]);
		modify(res[i]+1,1);
	}
	printf("%d",ans);
	return 0;
}
