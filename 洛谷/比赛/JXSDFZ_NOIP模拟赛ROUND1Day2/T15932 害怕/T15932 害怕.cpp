#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int MAXN=1001;
const int INF=2147483647;
struct edge
{
    int data,p;
}up[MAXN],down[MAXN];
int ans=2147483647;
int MAP[MAXN][MAXN];
int maxans1[MAXN][MAXN],minans1[MAXN][MAXN];
int maxans[MAXN][MAXN],minans[MAXN][MAXN];
int main()
{
    int a,b,n;
    scanf("%d%d%d",&a,&b,&n);
    for(int i=1;i<=a;++i)
        for(int j=1;j<=b;++j)
            scanf("%d",&MAP[i][j]);
    for(int i=1;i<=a;++i)
    {
        int head=1,tail=2;
        for(int w=1;w<=n;++w) up[w].data=0;
        for(int j=1;j<=b;++j)
        {
            while(head<tail&&up[tail-1].data<MAP[i][j]) --tail;
            up[tail].data=MAP[i][j];
            up[tail++].p=j;
            if(j-up[head].p>=n) ++head;
            if(j>=n) maxans1[i][j]=up[head].data;
        }
        head=1;tail=2;
        for(int w=1;w<=n;++w) down[w].data=INF;
        for(int j=1;j<=b;++j)
        {
            while(head<tail&&down[tail-1].data>MAP[i][j]) --tail;
            down[tail].data=MAP[i][j];
            down[tail++].p=j;
            if(j-down[head].p>=n) ++head;
            if(j>=n) minans1[i][j]=down[head].data;
        }
    }
	for(int i=1;i<=b;++i)
	{
		for(int w=1;w<=MAXN;++w) {up[w].data=0;down[w].data=INF;}
		int head=1,tail=2;
		for(int j=1;j<=a;++j)
		{
			while(head<tail&&up[tail-1].data<maxans1[j][i]) --tail;
			up[tail].data=maxans1[j][i];
			up[tail++].p=j;
			if(j-up[head].p>=n) ++head;
			if(j>=n) maxans[j][i]=up[head].data;
		}
		head=1;tail=2;
		for(int j=1;j<=a;++j)
		{
			while(head<tail&&down[tail-1].data>minans1[j][i]) --tail;
			down[tail].data=minans1[j][i];
			down[tail++].p=j;
			if(j-down[head].p>=n) ++head;
			if(j>=n) minans[j][i]=down[head].data;
		}
	}
	for(int i=n;i<=a;++i)
		for(int j=n;j<=b;++j)
			ans=min(ans,maxans[i][j]-minans[i][j]);
    printf("%d",ans);
    return 0;
}

