#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int MAXN=55;
struct edge
{
	int x,y,num;
}dl[1000000];
bool MAP[MAXN][MAXN];
int tox[12]={-2,-2,-1,1,2,2,1,-1,-2,-2,2,2};
int toy[12]={-1,1,2,2,1,-1,-2,-2,-2,2,-2,2};
int bfs(int nx,int ny)
{
	memset(MAP,0,sizeof(MAP));
	int head=1,tail=1;
	dl[tail].x=nx;dl[tail].y=ny;
	dl[tail].num=0;
	MAP[nx][ny]=true;
	while(head-1!=tail%999999)
	{
		int xx=dl[head].x,yy=dl[head].y;
		for(int i=0;i<12;++i)
		{
			int xxx=xx+tox[i],yyy=yy+toy[i];
			if(xxx<1||xxx>50||yyy<1||yyy>50) continue;
			if(MAP[xxx][yyy]==true) continue;
			if(xxx==1&&yyy==1) return dl[head].num+1;
			MAP[xxx][yyy]=true;
			if(tail==999999) tail=1;
			else ++tail;
			dl[tail].x=xxx;dl[tail].y=yyy;
			dl[tail].num=dl[head].num+1;
		}
		if(head==999999) head=1;
		else ++head;
	}
	return 0;
}
int main()
{
	int x1,y1,x2,y2;
	scanf("%d%d",&x1,&y1);
	if(x1==1&&y1==1) printf("0\n");
	else printf("%d\n",bfs(x1,y1));
	scanf("%d%d",&x2,&y2);
	if(x2==1&&y2==1) printf("0");
	else printf("%d",bfs(x2,y2));
	return 0;
}
