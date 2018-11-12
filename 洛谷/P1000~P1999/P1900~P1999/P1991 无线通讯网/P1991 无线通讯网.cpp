#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN1=501;
const int MAXN2=250001;
struct edge
{
	int Left,Right;
	double length;
};
edge con[MAXN2],bian[MAXN1];
double x[MAXN1],y[MAXN1];
int bianshu=0,num=0,fa[MAXN1],size[MAXN1];
inline void insdist(int start,int end)
{
	double dis=sqrt((x[start]-x[end])*(x[start]-x[end])+(y[start]-y[end])*(y[start]-y[end]));
	con[++num].Left=start;con[num].Right=end;
	con[num].length=dis;
}
inline bool CMP(const edge &a,const edge &b)
{
	return a.length<b.length;
}
inline int getfa(int a)
{
	if(fa[a]==a) return a;
	else return fa[a]=getfa(fa[a]);
}
inline void Merge(int a,int b)
{
	int na=getfa(a),nb=getfa(b);
	if(size[na]<size[nb]) swap(na,nb);
	fa[nb]=na;size[na]+=size[nb];
}
int main()
{
	int s,p;
	scanf("%d%d",&s,&p);
	for(int i=1;i<=p;++i) scanf("%lf%lf",&x[i],&y[i]);
	for(int i=1;i<=p;++i)
		for(int j=i+1;j<=p;++j)
			insdist(i,j);
	sort(con+1,con+num+1,CMP);
	for(int i=1;i<=p;++i) {fa[i]=i;size[i]=1;}
	for(int i=1;i<=num;++i)
	{
		if(getfa(con[i].Left)!=getfa(con[i].Right))
		{
			bian[++bianshu].length=con[i].length;
			bian[bianshu].Left=con[i].Left;bian[bianshu].Right=con[i].Right;
			Merge(con[i].Left,con[i].Right);
		}
	}
	printf("%.2lf",bian[bianshu-s+1].length);
	return 0;
}
