#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=1001;
int fa[MAXN],size[MAXN];
inline int getfa(int a)
{
	if(fa[a]==a) return a;
	else return fa[a]=getfa(fa[a]);
}
inline void merge(int a,int b)
{
	int na=getfa(a),nb=getfa(b);
	if(size[na]<size[nb]) swap(na,nb);
	fa[nb]=na;size[na]+=size[nb];
}
int main()
{
	int n,m,x,y,num=-1;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		{fa[i]=i;size[i]=1;}
	for(int i=0;i<m;++i)
	{
		scanf("%d%d",&x,&y);
		merge(x,y);
	}
	for(int i=1;i<=n;++i)
		if(fa[i]==i) ++num;
	printf("%d",num);
	return 0;
}
