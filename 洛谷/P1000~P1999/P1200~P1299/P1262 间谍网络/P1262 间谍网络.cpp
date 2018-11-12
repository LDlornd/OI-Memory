#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=3001;
int n,p,r,u,v,visit=0,ans=0,tot=0;
int pay[MAXN],newpay[MAXN];
int dfn[MAXN],low[MAXN],belong[MAXN];
int zhan[MAXN],top=0;
int rudu[MAXN];
bool flag[MAXN],zhanflag[MAXN];
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
inline void Catch(int nv)
{
	flag[nv]=true;
	for(edge *p=con[nv];p;p=p->NEXT)
	{
		int vv=p->v;
		if(flag[vv]==false)
			Catch(vv);
	}
}
inline void tarjan(int nv)
{
	int place;
	dfn[nv]=low[nv]=++visit;
	zhan[++top]=nv;zhanflag[nv]=true;
	for(edge *p=con[nv];p;p=p->NEXT)
	{
		int vv=p->v;
		if(dfn[vv]==0)
		{
			tarjan(vv);
			low[nv]=min(low[nv],low[vv]);
		}
		else if(zhanflag[vv]) low[nv]=min(low[nv],dfn[vv]);
	}
	if(dfn[nv]==low[nv])
	{
		++tot;
		do
		{
			place=zhan[top--];
			belong[place]=tot;
			zhanflag[place]=false;
		}while(place!=nv);
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
	memset(zhanflag,0,sizeof(zhanflag));
	memset(flag,0,sizeof(flag));
	memset(newpay,-1,sizeof(newpay));
	memset(pay,-1,sizeof(pay));
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(rudu,0,sizeof(rudu));
	n=read();p=read();
	for(int i=1;i<=p;++i) {u=read();pay[u]=read();}
	r=read();
	while(r--) {u=read();v=read();ins(u,v);}
	for(int i=1;i<=n;++i)
		if(flag[i]==false&&pay[i]!=-1) Catch(i);
	for(int i=1;i<=n;++i)
		if(flag[i]==false) {ans=i;break;}
	if(ans)
	{
		printf("NO\n%d",ans);
		return 0;
	}
	for(int i=1;i<=n;++i)
		if(dfn[i]==0) tarjan(i);
	for(int i=1;i<=n;++i)
	{
		if(pay[i]!=-1)
		{
			if(newpay[belong[i]]==-1) newpay[belong[i]]=pay[i];
			else newpay[belong[i]]=min(newpay[belong[i]],pay[i]);
		}
		for(edge *p=con[i];p;p=p->NEXT)
		{
			int nv=p->v;
			if(belong[i]!=belong[nv])
			{
				++rudu[belong[nv]];
			}
		}
	}
	for(int i=1;i<=tot;++i)
		if(rudu[i]==0) ans+=newpay[i];
	printf("YES\n%d",ans);
	return 0;
}
