#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<vector>
using namespace std;
const int MAXN=200001;
const int mod=10007; 
vector<int> G[MAXN];
vector<int> son[MAXN];
int wi[MAXN];
inline int read()
{
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
	return x;
}
void gettree(int nowroot,int father)
{
	int s=G[nowroot].size();
	for(int i=0;i<s;++i)
	{
		int nv=G[nowroot][i];
		son[nowroot].push_back(nv);
		if(nv!=father) gettree(nv,nowroot);
	}
}
int main()
{
	int x,y,ans=0,maxw=0,n=read();
	for(int i=1;i<n;++i)
	{
		x=read();y=read();
		G[x].push_back(y);
		G[y].push_back(x);
	}
	wi[0]=0;
	for(int i=1;i<=n;++i)
		wi[i]=read();
	gettree(1,0);
	for(int i=1;i<=n;++i)
	{
		int s=G[i].size();
		int sum=0,tot=0,maxnum=0,second=0;
		for(int h=0;h<s;++h)
		{
			if(wi[son[i][h]]>maxnum) {second=maxnum;maxnum=wi[son[i][h]];}
			else if(wi[son[i][h]]>second) {second=wi[son[i][h]];}
			sum+=wi[son[i][h]];sum%=mod;
			tot+=wi[son[i][h]]*wi[son[i][h]];tot%=mod;
		}
		maxnum*=second;
		if(maxw<maxnum) maxw=maxnum;
		sum=sum*sum-tot;sum%=mod;
		ans+=sum;ans%=mod;
	}
	printf("%d %d",maxw,ans);
	return 0;
}
