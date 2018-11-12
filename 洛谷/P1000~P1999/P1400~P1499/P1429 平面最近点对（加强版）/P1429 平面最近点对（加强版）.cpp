#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cmath>
using namespace std;
struct point
{
	double x,y;
};
point P[200000];
int flag[200000];
double dis(int a,int b)
{
	return (P[a].x-P[b].x)*(P[a].x-P[b].x)+(P[a].y-P[b].y)*(P[a].y-P[b].y);
}
int CMP(const point &a,const point &b)
{
	if(a.x==b.x) return a.y<b.y;
	return a.x<b.x;
}
int CMPy(int a,int b)
{
	return P[a].y<P[b].y;
}
double Merge(int Left,int Right)
{
	double d=2e9;
	if(Left==Right) return d;
	if(Right-Left==1) return dis(Left,Right);
	int mid=(Left+Right)>>1;
	double d1=Merge(Left,mid),d2=Merge(mid+1,Right);
	d=min(d1,d2);
	int k=0;
	for(int i=Left;i<=Right;++i)
		if(abs(P[mid].x-P[i].x)<=d) flag[k++]=i;
	sort(flag,flag+k,CMPy);
	for(int i=0;i<k;++i)
	{
		for(int j=i+1;j<k&&P[flag[j]].y-P[flag[i]].y<d;++j)
		{
			double distance=dis(flag[i],flag[j]);
			if(distance<d) d=distance;
		}
	}
	return d;
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;++i)
		scanf("%lf%lf",&P[i].x,&P[i].y);
	sort(P,P+n,CMP);
	double ans=Merge(0,n-1);
	ans=sqrt(ans);
	printf("%.4lf",ans);
	return 0;
}
