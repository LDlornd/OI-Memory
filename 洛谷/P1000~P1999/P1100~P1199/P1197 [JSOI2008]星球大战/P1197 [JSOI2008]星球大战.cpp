#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN=400001;
int n,m,num,up,vp,tot=0;
int attack[MAXN],ans[MAXN];
int fa[MAXN],size[MAXN];
bool destory[MAXN];
struct edge
{
	int v;
	edge *NEXT;
	edge() {v=0;NEXT=NULL;}
}*con[MAXN];
inline void ins(int start,int end)
{
	edge *p=new(edge);
	p->v=end;
	p->NEXT=con[start];
	con[start]=p;
}
inline int getfa(int a)
{
	return (fa[a]==a)?(a):(getfa(fa[a]));
}
inline void Merge(int a,int b)
{
	int na=getfa(a),nb=getfa(b);
	if(size[na]<size[nb]) swap(na,nb);
	fa[nb]=na;size[na]+=size[nb];
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
	memset(destory,0,sizeof(destory));
	n=read();m=read();
	for(int i=1;i<=m;++i)
	{
		up=read()+1;vp=read()+1;
		ins(up,vp);ins(vp,up);
	}
	num=read();tot=n-num;
	for(int i=1;i<=num;++i) {attack[i]=read()+1;destory[attack[i]]=true;}
	for(int i=1;i<=n;++i) {fa[i]=i;size[i]=1;}
	for(int i=1;i<=n;++i)
	{
		if(destory[i]) continue;
		for(edge *p=con[i];p;p=p->NEXT)
		{
			int nv=p->v;
			if(destory[nv]) continue;
			if(getfa(i)!=getfa(nv))
			{
				Merge(i,nv);
				--tot;
			}
		}
	}
	ans[num]=tot;
	for(int i=num;i>=1;--i)
	{
		int nv=attack[i];
		++tot;destory[nv]=false;
		for(edge *p=con[nv];p;p=p->NEXT)
		{
			int vv=p->v;
			if(destory[vv]) continue;
			if(getfa(nv)!=getfa(vv))
			{
				--tot;
				Merge(nv,vv);
			}
		}
		ans[i-1]=tot;
	}
	for(int i=0;i<=num;++i)
		printf("%d\n",ans[i]);
	return 0;
}
