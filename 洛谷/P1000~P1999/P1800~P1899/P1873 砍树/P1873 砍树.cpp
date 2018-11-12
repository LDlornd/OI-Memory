#include<cstdio>
#include<iostream>
using namespace std;
long long int wood[1000000];
long long int n,m,Left=0,Right=0,ans;
bool judge(int x)
{
	long long int sum=0;
	for(long long int i=0;i<n;++i)
		if(wood[i]>x) sum+=(wood[i]-x);
	if(sum>=m) return true;
	else return false;
}
int main()
{
	cin>>n>>m;
	for(long long int i=0;i<n;++i)
	{
		scanf("%lld",&wood[i]);
		if(wood[i]>Right) Right=wood[i];
	}
	while(Left<Right)
	{
		int mid=(Left+Right)>>1;
		if(judge(mid))
		{
			ans=mid;
			Left=mid+1;
		}
		else Right=mid;
	}
	if(judge(Left)) ans=Left;
	cout<<ans;
	return 0;
}
