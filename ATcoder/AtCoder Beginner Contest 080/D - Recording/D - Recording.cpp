#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=100001;
struct record
{
	int start,end,c;
}arr[MAXN];
int flag[50],last[50];
inline bool CMP(const record &a,const record &b)
{
	if(a.start<b.start) return true;
	if(a.start>b.start) return false;
	return a.c<b.c;
}
inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
	return x*f;
}
int main()
{
	memset(flag,0,sizeof(flag));
	memset(last,0,sizeof(last));
	int n=read(),channel=read();
	for(int i=1;i<=n;++i)
		{arr[i].start=read();arr[i].end=read();arr[i].c=read();}
	sort(arr+1,arr+n+1,CMP);
	for(int i=1;i<=n;++i)
		for(int j=1;j<50;++j)
			if(flag[j]<arr[i].start||(last[j]==arr[i].c&&flag[j]==arr[i].start))
				{flag[j]=arr[i].end;last[j]=arr[i].c;break;}
	for(int i=1;i<=n;++i)
		if(flag[i+1]==0)
		{printf("%d",i);break;}
	return 0;
}
