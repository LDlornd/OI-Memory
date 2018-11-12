#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
const int MAXN=30001;
int fa[MAXN],size[MAXN],len[MAXN];
inline int getfa(int x)
{
	if(fa[x]==x) return x;
	int fax=getfa(fa[x]);
	len[x]+=len[fa[x]];
	return fa[x]=fax;
}
inline void Merge(int x,int y)
{
	int nx=getfa(x),ny=getfa(y);
	fa[nx]=ny;
	len[nx]+=size[ny];
	size[ny]+=size[nx];
}
int main()
{
	for(int i=1;i<MAXN;++i) {fa[i]=i;size[i]=1;len[i]=0;}
	char c;
	int T,a,b;
	//scanf("%d",&T);
	cin>>T;
	for(int w=0;w<T;++w)
	{
		//scanf("\n%c %d %d",&c,&a,&b);
		cin>>c>>a>>b;
		if(c=='M') Merge(a,b);
		if(c=='C')
		{
			int faa=getfa(a),fab=getfa(b);
			if(faa!=fab) cout<<"-1"<<endl;//printf("-1\n");
			else cout<<abs(len[a]-len[b])-1<<endl;//printf("%d\n",abs(len[a]-len[b])-1);
		}
	}
	return 0;
}
