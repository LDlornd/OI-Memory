#include<cmath>
#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=10001;
int n,m,tot=0;
int A[MAXN],B[MAXN],C[MAXN];
double symmetry[MAXN];
bool flag[MAXN];
struct fval
{
	int x,y,rank;
	fval(int xx=0,int yy=0,int rr=0) {x=xx;y=yy;rank=rr;}
}arr[MAXN];
inline void ins(fval a)
{
	int now=(++tot);
	arr[tot]=a;
	while(now>1)
	{
		int fa=now>>1;
		if(arr[fa].y<=arr[now].y) return;
		swap(arr[fa],arr[now]);
		now=fa;
	}
}
inline void del()
{
	int now=1;
	swap(arr[1],arr[tot--]);
	while(now*2<=tot)
	{
		int son=now*2;
		if(son<tot&&arr[son+1].y<arr[son].y) ++son;
		if(arr[now].y<=arr[son].y) return;
		swap(arr[now],arr[son]);
		now=son;
	}
}
inline int getfval(int a,int num)
{
	return A[num]*a*a+B[num]*a+C[num];
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
	n=read();m=read();
	for(int i=1;i<=n;++i)
	{
		A[i]=read();B[i]=read();C[i]=read();
		fval k=fval(1,getfval(1,i),i);
		ins(k);
	}
	while(m--)
	{
		printf("%d ",arr[1].y);
		del();
		int nx=arr[tot+1].x+1,nr=arr[tot+1].rank;
		fval k=fval(nx,getfval(nx,nr),nr);
		ins(k);
	}
	return 0;
}
