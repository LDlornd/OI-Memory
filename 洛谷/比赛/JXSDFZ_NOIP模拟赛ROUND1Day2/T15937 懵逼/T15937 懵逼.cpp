#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=20001;
struct point
{
	int x,y;
}con[MAXN];
bool flag[MAXN];
int n,minx=2000000001,miny=minx,maxx=-2000000001,maxy=maxx;
int pmix,pmax,pmiy,pmay;
inline bool CMP(const point &a,const point &b)
{
	if(a.x<b.x) return 1;
	if(a.x>b.x) return 0;
	return a.y<b.y;
}
inline bool check()
{
	for(int i=1;i<=n;++i)
		if(flag[i]==false) return false;
	return true;
}
inline bool judge(int k,int deep)//k是正方形的边长 
{
	for(int )
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d",&con[i].x,&con[i].y);
		if(minx>con[i].x) {minx=con[i].x;pmix=i;}
		if(miny>con[i].y) {miny=con[i].y;pmiy=i;}
		if(maxx<con[i].x) {maxx=con[i].x;pmax=i;}
		if(maxy<con[i].y) {maxy=con[i].y;pmay=i;}
	}
	sort(con+1,con+n+1,CMP);
	int l=1,r=max(maxx-minx,maxy-miny),ans;
	while(l<r)
	{
		memset(flag,0,sizeof(flag));
		int mid=(l+r)>>1;
		if(judge(mid,1,minx,miny)||judge(mid,1,minx,))
		{
			ans=mid;
			r=mid;
		}
		else l=mid+1;
	}
	if(judge(l)) ans=l;
	printf("%d",ans);
	return 0;
}
