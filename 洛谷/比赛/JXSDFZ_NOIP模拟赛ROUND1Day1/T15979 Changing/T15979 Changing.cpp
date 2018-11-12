#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int jihe[20];
int cx[100],cy[100];
inline void change(int k,int c[])
{
	int num=0;
	while(k!=0)
	{
		c[++num]=k%2;
		k/=2;
	}
}
int main()
{
	int n,q,x,y;
	scanf("%d%d",&n,&q);
	for(int i=0;i<n;++i)
		scanf("%d",&jihe[i]);
	for(int w=0;w<q;++w)
	{
		int ans=0;
		scanf("%d%d",&x,&y);
		memset(cx,0,sizeof(cx));
		memset(cy,0,sizeof(cy));
		change(x,cx);change(y,cy);
		for(int i=1;i<100;++i)
			if(cx[i]!=cy[i]) ++ans;
		printf("%d\n",ans);
	}
	return 0;
}
