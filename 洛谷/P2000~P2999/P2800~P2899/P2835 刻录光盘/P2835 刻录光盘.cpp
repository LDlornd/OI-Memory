#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int MAXN=201;
int fa[MAXN],size[MAXN];
bool vis[MAXN][MAXN],zuxian[MAXN];;
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
	memset(zuxian,0,sizeof(zuxian));
	memset(vis,0,sizeof(vis));
	int n,x,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		{fa[i]=i;size[i]=1;}
	for(int i=1;i<=n;++i)
	{
		bool flag=true;
		while(scanf("%d",&x)!=EOF)
		{
			if(x==0) break;
			merge(i,x);
			vis[i][x]=true;
			flag=false;
		}
		if(flag) zuxian[x]=true;
	}
	for(int i=1;i<=n;++i)
		if(fa[i]==i) {++ans;zuxian[i]=true;}
	for(int i=1;i<=n;++i)
		if(zuxian[i]==false)
		{
			bool flag=true;
			for(int j=1;j<=n;++j)
				if(vis[j][i])
				{
					flag=false;
					break;
				}
			if(flag) ++ans;
		}
	printf("%d",ans);
	return 0;
}
