#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=1000001;
const int INF=2147483647;
struct edge
{
	int data,p;
}up[MAXN],down[MAXN];
int num[MAXN];
int main()
{
	int n,k,head,tail;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)
		scanf("%d",&num[i]);
	for(int i=1;i<=n;++i) {up[i].data=0;down[i].data=INF;}
	head=tail=1;
	for(int i=1;i<=n;++i)
	{
		while(head<tail&&down[tail-1].data>num[i]) --tail;
		down[tail].data=num[i];
		down[tail++].p=i;
		if(i-down[head].p>=k) ++head;
		if(i>=k) printf("%d ",down[head].data);
	}
	printf("\n");
	head=tail=1;
	for(int i=1;i<=n;++i)
	{
		while(head<tail&&up[tail-1].data<num[i]) --tail;
		up[tail].data=num[i];
		up[tail++].p=i;
		if(i-up[head].p>=k) ++head;
		if(i>=k) printf("%d ",up[head].data);
	}
	return 0;
}
