#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int MAXN=40001;
bool flag[MAXN];
int prime[MAXN],zxsyz[MAXN],f[MAXN],num=0;
void getready()
{
	memset(flag,0,sizeof(flag));
	flag[0]=flag[1]=true;f[1]=1;
	for(int i=2;i<MAXN;++i)
	{
		if(flag[i]==false) {prime[++num]=i;f[i]=i-1;}
		for(int j=1;j<=num&&i*prime[j]<MAXN;++j)
		{
			int k=i*prime[j];
			flag[k]=false;
			if(i%prime[j]==0)
			{
				f[k]=f[i]*prime[j];
				break;
			}
			else f[k]=f[i]*f[prime[j]];
		}
	}
}
int main()
{
	int n,ans=0;
	scanf("%d",&n);
	getready();
	for(int i=1;i<=100;++i)
		printf("%d ",f[i]);
	//for(int i=1;i<n;++i) ans+=f[i];
	printf("%d",ans*2+1);
}
