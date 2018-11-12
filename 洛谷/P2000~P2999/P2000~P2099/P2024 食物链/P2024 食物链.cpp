#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN=150001;
int n,k,opt,x,y,ans=0;
int fa[MAXN],size[MAXN];
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
	n=read();k=read();
	for(int i=1;i<=3*n;++i) {fa[i]=i;size[i]=1;}
	while(k--)
	{
		opt=read();x=read();y=read();
		if(x>n||y>n) ++ans;
		else if(opt==1)
		{
			if(getfa(x+n)==getfa(y)||getfa(x+2*n)==getfa(y)) ++ans;
			else {Merge(x,y);Merge(x+n,y+n);Merge(x+2*n,y+2*n);}
		}
		else
		{
			if(getfa(x)==getfa(y)||getfa(x+2*n)==getfa(y)) ++ans;
			else {Merge(x+n,y);Merge(x+2*n,y+n);Merge(x,y+2*n);}
		}
	}
	printf("%d",ans);
	return 0;
}
