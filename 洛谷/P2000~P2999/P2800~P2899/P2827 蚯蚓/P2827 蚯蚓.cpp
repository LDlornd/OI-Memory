#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100100;
int a[MAXN],q1[MAXN],q2[MAXN];
int n,m,q,u,v,t,na=1,nq1=1,nq2=1,lenq1=0,lenq2=0;
inline int read()
{
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
	return x;
}
inline void write(int x)
{
	if(x<0) {putchar('-');x=-x;}
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
inline bool CMP(int x,int y)
{
	return x>y;
}
inline int findmax(int now)
{
	int aa=-1,qq1=-1,qq2=-1,maxans;
	if(na<=n) aa=a[na]+(now-1)*q;
	if(nq1<=lenq1) qq1=q1[nq1]+(now-1)*q;
	if(nq2<=lenq2) qq2=q2[nq2]+(now-1)*q;
	maxans=max(aa,max(qq1,qq2));
	if(maxans==aa) ++na;
	if(maxans==qq1) ++nq1;
	if(maxans==qq2) ++nq2;
	return maxans;
}
int main()
{
	n=read();m=read();q=read();
	u=read();v=read();t=read();
	for(int i=1;i<=n;++i)
		a[i]=read();
	sort(a+1,a+n+1,CMP);
	for(int i=1;i<=m;++i)
	{
		int k=findmax(i);
		if(i%t==0) {write(k);putchar(' ');}
		int k1=k*u/v,k2=min(k1,k-k1);
		k1=k-k2;
		q1[++lenq1]=k1-i*q;
		q2[++lenq2]=k2-i*q;
	}
	putchar('\n');
	na=nq1=nq2=1;
	for(int i=1;i<=n+m;++i)
	{
		int k=findmax(i);
		if(i%t==0) {write(k);putchar(' ');}
	}
	return 0;
}
