#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int ball[100];
int main()
{
	int n,k,ans=0;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;++i)
		scanf("%d",&ball[i]);
	for(int i=0;i<n;++i)
		ans+=min(k-ball[i],ball[i]);
	ans*=2;
	printf("%d",ans);
	return 0;
}
