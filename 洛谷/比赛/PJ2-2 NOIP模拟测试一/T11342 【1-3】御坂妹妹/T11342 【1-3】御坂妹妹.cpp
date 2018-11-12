#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=300001;
const int INF=2147483647;
struct edge
{
	int val,flag;
}dish[MAXN];
inline bool CMP(const edge &a,const edge &b)
{
	return a.val<b.val;
}
int main()
{
	long long int ans=0;
	int m,a,b,c,num=0;
	char k;
	scanf("%d%d%d%d",&a,&b,&c,&m);
	for(int i=0;i<m;++i)
	{
		scanf("%d %c",&dish[i].val,&k);
		if(k=='A') dish[i].flag=1;
		if(k=='B') dish[i].flag=2;
	}
	sort(dish,dish+m,CMP);
	for(int i=0;i<m;++i)
	{
		bool flag1=true,flag2=true;
		if(dish[i].flag==1&&a>0) {++num;ans+=dish[i].val;--a;flag1=false;}
		if(dish[i].flag==2&&b>0) {++num;ans+=dish[i].val;--b;flag2=false;}
		if(flag1&&flag2&&c>0) {++num;--c;ans+=dish[i].val;}
	}
	printf("%d %lld",num,ans);
	return 0;
}
