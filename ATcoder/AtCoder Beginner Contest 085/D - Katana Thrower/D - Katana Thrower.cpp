#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100001;
struct edge
{
	int a,b;
}con[MAXN];
inline bool cmp1(const edge &x,const edge &y)
{
	return x.b>y.b;
}
int main()
{
	int n,total,tot=0,ans=0,maxa=0;
	scanf("%d%d",&n,&total);
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d",&con[i].a,&con[i].b);
		maxa=max(maxa,con[i].a);
	}
	sort(con+1,con+n+1,cmp1);
	for(int i=n;i>=1;--i)
		if(con[i].b<=maxa) --n;
		else break;
	for(int i=1;i<=n;++i)
	{
		tot+=con[i].b;++ans;
		if(tot>=total) break;
	}
	if(tot>=total) printf("%d",ans);
	else
	{
		int k=total-tot;
		if(k%maxa==0) ans+=k/maxa;
		else ans+=(k/maxa+1);
		printf("%d",ans);
	}
	return 0;
}
