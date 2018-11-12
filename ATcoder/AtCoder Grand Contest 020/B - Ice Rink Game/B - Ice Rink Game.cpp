#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=100001;
int k,Left=1,Right=3e9+1;
int array[MAXN];
int maxn,minn=-1;
inline bool judge(int num)
{
	for(int i=1;i<k;++i)
	{
		num-=(num%array[i]);
		if(num==0) return false;
	}
	num-=(num%array[k]);
	if(num==2) return true;
	else return false;
}
inline int read()
{
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
	return x*f;
}
int main()
{
	k=read();
	for(int i=1;i<=k;++i) array[i]=read();
	while(Left<Right)
	{
		int mid=(Left+Right)>>1;
		if(judge(mid))
		{
			minn=mid;
			Right=mid;
		}
		else Left=mid+1;
	}
	if(judge(Left)) minn=Left;
	maxn=minn+array[1]-1;
	if(minn!=-1) printf("%d %d",minn,maxn);
	else printf("-1");
	return 0;
}
