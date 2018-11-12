#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN1=1001; 
const int MAXN2=100001;
struct road
{
	int start,end,day;
}con[MAXN2];
int fa[MAXN1],size[MAXN1];
inline bool CMP(const road &a,const road &b)
{
	return a.day<b.day;
}
inline bool judge(int x)
{
	int tot=0;
	for(int i=1;i<=x;++i)
		if(fa[i]==i) ++tot;
	if(tot>1) return false;
	else return true;
}
inline int getfa(int x)
{
	if(fa[x]==x) return x;
	else return fa[x]=getfa(fa[x]);
}
inline void Merge(int x,int y)
{
	int nx=getfa(x),ny=getfa(y);
	if(size[nx]<size[ny]) swap(nx,ny);
	fa[ny]=nx;size[nx]+=size[ny];
}
int main()
{
	int n,m,num=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
		scanf("%d%d%d",&con[i].start,&con[i].end,&con[i].day);
	sort(con+1,con+m+1,CMP);
	for(int i=1;i<=n;++i) {fa[i]=i;size[i]=1;}
	while(judge(n)==false&&num<=m)
	{
		++num;
		Merge(con[num].start,con[num].end);
	}
	if(num>m) printf("-1");
	else printf("%d",con[num].day);
	return 0;
}
