#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN1=5000;
const int MAXN2=200000;
struct edge
{
	int start,end,length;
}con[MAXN2];
int fa[MAXN1],size[MAXN1];
inline int getfa(int a)
{
	if(fa[a]==a) return a;
	else return fa[a]=getfa(fa[a]);
}
inline void merge(int a,int b)
{
	int na=getfa(a),nb=getfa(b);
	if(size[na]<size[nb]) swap(na,na);
	fa[nb]=na;size[na]+=size[nb];
}
inline bool CMP(const edge &a,const edge &b)
{
	return a.length<b.length;
}
int main()
{
	int n,m,flag=1,ans=0;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;++i)
		scanf("%d%d%d",&con[i].start,&con[i].end,&con[i].length);
	for(int i=0;i<n;++i) {fa[i]=i;size[i]=1;}
	sort(con,con+m,CMP);
	for(int i=0;i<m;++i)
	{
		if(getfa(con[i].start)!=getfa(con[i].end))
		{
			merge(con[i].start,con[i].end);
			++flag;
			ans+=con[i].length;
		}
		if(flag==n) break;
	}
	if(flag!=n) printf("orz");
	else printf("%d",ans);
	return 0;
}
