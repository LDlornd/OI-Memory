#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long int ll;
const int MAXN=100001;
ll cost[11]={0,1,3,5,7,9,10,11,14,15,17};
ll sell[11],maxsell[MAXN];
ll ans[MAXN];
inline ll read()
{
	ll x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
	return x;
}
int main()
{
	memset(maxsell,0,sizeof(maxsell));
	memset(sell,0,sizeof(sell));
	memset(ans,0,sizeof(ans));
	int n=read();
	for(int i=1;i<=10;++i)
		sell[i]=read();
	for(int i=1;i<=10;++i)
		for(int j=1;j<=i;++j)
			maxsell[i]=max(maxsell[i],maxsell[i-j]+sell[j]);
	for(int i=1;i<=10;++i)
		maxsell[i]-=cost[i];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=i&&j<=10;++j)
			ans[i]=max(ans[i],ans[i-j]+maxsell[j]);
	printf("%lld",ans[n]);
	return 0;
}
