#include<cstdio>
using namespace std;
int main()
{
	int n,sum=0,ans=0;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;++i)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	sum/=n;
	for(int i=0;i<n;++i)
	{
		int k=a[i]-sum;
		if(k==0) continue;
		a[i+1]+=k;
		++ans;
	}
	printf("%d",ans);
	return 0;
}
