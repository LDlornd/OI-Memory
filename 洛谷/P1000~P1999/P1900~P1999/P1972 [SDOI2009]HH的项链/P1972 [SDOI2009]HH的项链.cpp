#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN1=50001;
const int MAXN2=200001;
const int MAXN3=1000001;
int n,q,u,v,len,start=1,end=0,temp=0;
int array[MAXN1],ans[MAXN2];
int num[MAXN3];
struct que
{
	int Left,Right,id,block;
	que(int ll=0,int rr=0,int bb=0,int ii=0) {Left=ll;Right=rr;block=bb;id=ii;}
}Q[MAXN2];
inline void add(int place)
{
	++num[place];
	if(num[place]==1) ++temp;
}
inline void del(int place)
{
	--num[place];
	if(num[place]==0) --temp;
}
inline bool CMP(const que &a,const que &b)
{
	if(a.block==b.block) return a.Right<b.Right;
	return a.block<b.block;
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
	memset(num,0,sizeof(num));
	n=read();len=(int)sqrt(n);
	for(int i=1;i<=n;++i) array[i]=read();
	q=read();
	for(int i=1;i<=q;++i)
		{u=read();v=read();Q[i]=que(u,v,u/len,i);}
	sort(Q+1,Q+q+1,CMP);
	for(int w=1;w<=q;++w)
	{
		int nl=Q[w].Left,nr=Q[w].Right;
		while(start<nl) {del(array[start]);++start;}
		while(start>nl) {--start;add(array[start]);}
		while(end<nr) {++end;add(array[end]);}
		while(end>nr) {del(array[end]);--end;}
		ans[Q[w].id]=temp;
	}
	for(int i=1;i<=q;++i) printf("%d\n",ans[i]);
	return 0;
}
