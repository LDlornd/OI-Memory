#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int MAXN=100005;
const int MOD=99999997;
struct height
{
	int data,rank;
	height() {data=rank=0;}
}A[MAXN],B[MAXN],resa[MAXN];
int resb[MAXN],temp[MAXN];
int n,ans=0,val[MAXN];
inline void modify(int place,int k)
{
	for(;place<=n;place+=(place&-place))
		val[place]+=k;
}
inline int query(int place)
{
	int tot=0;
	for(;place;place-=(place&-place))
		(tot+=val[place])%=MOD;
	return tot;
}
inline bool CMP(const height &a,const height &b)
{
	return a.data<b.data;
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
	memset(val,0,sizeof(val));
	n=read();
	for(int i=1;i<=n;++i) {A[i].data=read();A[i].rank=i;}
	for(int i=1;i<=n;++i) {B[i].data=read();B[i].rank=i;}
	sort(A+1,A+n+1,CMP);sort(B+1,B+n+1,CMP);
	for(int i=1;i<=n;++i) {resa[A[i].rank].data=i;resa[i].rank=i;}
	for(int i=1;i<=n;++i) {resb[B[i].rank]=i;}
	sort(resa+1,resa+n+1,CMP);
	for(int i=1;i<=n;++i) resb[i]=resa[resb[i]].rank;
	for(int i=n;i>=1;--i)
	{
		(ans+=query(resb[i]))%=MOD;
		modify(resb[i]+1,1);
	}
	printf("%d",ans);
	return 0;
}
