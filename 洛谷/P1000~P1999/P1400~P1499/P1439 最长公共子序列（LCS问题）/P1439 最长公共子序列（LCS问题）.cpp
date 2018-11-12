#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int MAXN=100001;
int a[MAXN],b[MAXN];
int ans[MAXN];
int main()
{
	memset(ans,0,sizeof(ans));
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)
		scanf("%d",&b[i]);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			if(a[i]==b[j]) ans[j]=ans[j-1]+1;
			ans[j]=max(ans[j],ans[j-1]);
		}
	}
	printf("%d",ans[n]);
	return 0;
}
