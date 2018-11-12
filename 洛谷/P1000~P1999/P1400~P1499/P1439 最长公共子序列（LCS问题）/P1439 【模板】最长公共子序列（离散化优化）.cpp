#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100001;
int n,u,array[MAXN];
int uplen=0,up[MAXN],best[MAXN];
struct num
{
	int val,place;
	num(int vv=0,int pp=0) {val=vv;place=pp;}
}con[MAXN];
inline int Search(int nowlen,int key)
{
	if(nowlen==0) return 1;
	int Left=1,Right=nowlen+1,tempans;
	while(Left<Right)
	{
		int mid=(Left+Right)>>1;
		if(best[mid]>key||best[mid]==0)
		{
			tempans=mid;
			Right=mid;
		}
		else Left=mid+1;
	}
	if(best[Left]>key||best[Left]==0) tempans=Left;
	return tempans;
}
inline bool CMP(const num &a,const num &b)
{
	return a.val<b.val;
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
	memset(up,0,sizeof(up));
	memset(best,0,sizeof(best));
	n=read();
	for(int i=1;i<=n;++i) {u=read();con[i]=num(u,i);}
	for(int i=1;i<=n;++i) array[i]=read();
	sort(con+1,con+n+1,CMP);
	for(int i=1;i<=n;++i) array[i]=con[array[i]].place;
	for(int i=1;i<=n;++i)
	{
		int temp=Search(uplen,array[i]);
		best[temp]=array[i];
		if(temp>uplen) ++uplen;
	}
	printf("%d",uplen);
	return 0;
}
