#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int MAXN=1000001;
bool flag[MAXN];
int prime[MAXN],ans[MAXN],num=0;
void getready()
{
	memset(flag,0,sizeof(flag));
	flag[0]=flag[1]=true;
	for(int i=2;i<MAXN;++i)
	{
		if(flag[i]==false)
			prime[++num]=i;
		for(int j=1;j<=num&&i*prime[j]<MAXN;++j)
		{
			flag[i*prime[j]]=true;
			if(i%prime[j]==0) break;
		}
	}
	ans[0]=0;
	for(int i=1;i<MAXN;++i)
	{
		if(flag[i]==false) ans[i]=ans[i-1]+1;
		else ans[i]=ans[i-1];
	}
}
int main()
{
	int n,m,x,y;
	scanf("%d%d",&n,&m);
	getready();
	for(int i=0;i<n;++i)
	{
		scanf("%d%d",&x,&y);
		if(x<1||x>m||y<1||y>m) printf("Crossing the line\n");
		else printf("%d\n",ans[y]-ans[x-1]);
	}
	return 0;
}
