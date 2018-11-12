#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=200005;
struct NUM
{
	int num,rank;
	NUM() {num=rank=0;}
}con[MAXN];
int T,n,tot=0,res[MAXN];
int fa[MAXN],size[MAXN];
bool flag[MAXN],judge;
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
inline bool CMP(const NUM &a,const NUM &b)
{
	return a.num<b.num;
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
	T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<=n;++i)
		{
			con[2*i-1].num=read();con[2*i-1].rank=2*i-1;
			con[2*i].num=read();con[2*i].rank=2*i;
			flag[i]=read();
		}
		sort(con+1,con+2*n+1,CMP);
		tot=0;
		res[con[1].rank]=++tot;
		for(int i=2;i<=2*n;++i)
		{
			if(con[i].num==con[i-1].num) res[con[i].rank]=tot;
			else res[con[i].rank]=++tot;
		}
		judge=true;
		for(int i=1;i<=tot;++i) {fa[i]=i;size[i]=1;}
		for(int i=1;i<=n;++i) if(flag[i]==1&&getfa(res[2*i-1])!=getfa(res[2*i])) Merge(res[2*i-1],res[2*i]);
		for(int i=1;i<=n;++i) if(flag[i]==0&&getfa(res[2*i-1])==getfa(res[2*i])) {judge=false;break;}
		if(judge) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
