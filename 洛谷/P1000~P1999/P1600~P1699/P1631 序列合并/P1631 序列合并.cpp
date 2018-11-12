#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=100001;
int n,tot=0;
int A[MAXN],B[MAXN];
struct num
{
	int val,nowb;
	num(int vv=0,int nn=0) {val=vv;nowb=nn;}
}Heap[MAXN];
inline void add(num key)
{
	Heap[++tot]=key;
	int now=tot;
	while(now>1)
	{
		int fa=now>>1;
		if(Heap[fa].val<=Heap[now].val) return;
		swap(Heap[fa],Heap[now]);
		now=fa;
	}
}
inline void delmin()
{
	int now=1;
	Heap[1]=Heap[tot--];
	while((now<<1)<=tot)
	{
		int son=now<<1;
		if(son<tot&&Heap[son].val>Heap[son+1].val) ++son;
		if(Heap[now].val<=Heap[son].val) return;
		swap(Heap[now],Heap[son]);
		now=son;
	}
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
	n=read();
	for(int i=1;i<=n;++i) A[i]=read();
	for(int i=1;i<=n;++i) B[i]=read();
	for(int i=1;i<=n;++i) add(num(A[i]+B[1],1));
	for(int i=1;i<=n;++i)
	{
		num p=num(Heap[1].val-B[Heap[1].nowb]+B[Heap[1].nowb+1],Heap[1].nowb+1);
		printf("%d ",Heap[1].val);
		delmin();add(p);
	}
	return 0;
}
