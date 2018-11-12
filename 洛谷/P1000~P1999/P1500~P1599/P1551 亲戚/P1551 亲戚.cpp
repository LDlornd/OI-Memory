#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=5001;
int fa[MAXN],size[MAXN];
inline int getfather(int a)
{
	if(fa[a]==a) return a;
	else return fa[a]=getfather(fa[a]);
}
inline void merge(int a,int b)
{
	int na=getfather(a),nb=getfather(b);
	if(size[na]<size[nb]) swap(na,nb);
	fa[nb]=na;size[na]+=size[nb];
}
int main()
{
	int n,m,q,x,y;
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;++i)
		{fa[i]=i;size[i]=1;}
	for(int i=0;i<m;++i)
	{
		scanf("%d%d",&x,&y);
		merge(x,y);
	}
	for(int i=0;i<q;++i)
	{
		scanf("%d%d",&x,&y);
		if(getfather(x)==getfather(y)) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
