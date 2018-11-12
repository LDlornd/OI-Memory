#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int MAXN=1001;
int sugar[MAXN];
int main()
{
	memset(sugar,0,sizeof(sugar));
	int n,m,opt,x;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&x);
		++sugar[x];
	}
	for(int i=0;i<m;++i)
	{
		scanf("%d%d",&opt,&x);
		if(opt==1)
		{
			if(x>n) continue;
			else --sugar[x];
		}
		if(opt==2) 
		{
			if(x>n) printf("0\n");
			else printf("%d\n",sugar[x]);
		}
	}
	return 0;
}
