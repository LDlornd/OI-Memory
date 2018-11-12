#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int stone[50002];
int l,m,n,t,ans;
bool judge(int a)
{
	int sum=0,x=0,now=0;
	while(x<=m)
	{
		++x;
		if(stone[x]-stone[now]<a)
			++sum;
		else now=x;
	}
	if(sum>n) return false;
	else return true;
}
int main()
{
	cin>>l>>m>>n;
	if(m==0) {cout<<l;return 0;}
	for(int i=1;i<=m;++i)
		cin>>stone[i];
	stone[0]=0;stone[m+1]=l;
	int left=0,right=l,mid;
	while(left<right)
	{
		mid=(left+right)>>1;
		if(judge(mid))
		{
			left=mid+1;
			ans=mid;
		}
		else right=mid;
	}
	cout<<ans;
	return 0;
}
