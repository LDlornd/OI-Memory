#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=10001;
int pay[MAXN],task[MAXN];
int main()
{
	int n,cost;
	long long int ans=0;
	scanf("%d%d",&n,&cost);
	scanf("%d%d",&pay[1],&task[1]);
	ans=pay[1]*task[1];
	for(int i=2;i<=n;++i)
	{
		scanf("%d%d",&pay[i],&task[i]);
		pay[i]=min(pay[i],pay[i-1]+cost);
		ans+=pay[i]*task[i];
	}
	printf("%lld",ans);
	return 0;
}
