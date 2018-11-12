#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;
struct node
{
	int k,h;
	int ans;
}a[201];
int n,A,B;
void search()
{
	queue<node> q;
	a[A].ans=0;
	q.push(a[A]);
	while(!q.empty())
	{
		int nh=q.front().h,nk=q.front().k,nans=q.front().ans;
		int p1=nh-nk,p2=nh+nk;
		if(p1>0)
		{
			if(a[p1].ans>nans+1) {a[p1].ans=nans+1;q.push(a[p1]);}
			if(p1==B) return;
		}
		if(p2<=n)
		{
			if(a[p2].ans>nans+1) {a[p2].ans=nans+1;q.push(a[p2]);}
			if(p2==B) return;
		}
		q.pop();
	}
}
int main()
{
	scanf("%d%d%d",&n,&A,&B);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i].k);
		a[i].h=i;a[i].ans=9999;
	}
	search();
	if(a[B].ans!=9999) printf("%d",a[B].ans);
	else printf("-1");
	return 0;
}
