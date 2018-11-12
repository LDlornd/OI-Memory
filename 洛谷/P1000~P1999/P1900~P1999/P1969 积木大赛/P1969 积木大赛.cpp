#include<cstdio>
#include<iostream>
using namespace std;
int h[100001];
int main()
{
	h[0]=0;
	int ans=0,n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&h[i]);
		if(h[i]>h[i-1]) ans+=(h[i]-h[i-1]);
	}
	printf("%d",ans);
	return 0;
}
