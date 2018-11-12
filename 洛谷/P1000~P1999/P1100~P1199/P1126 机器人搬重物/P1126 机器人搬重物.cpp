#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
struct point
{
	int x,y;
	int num;
	bool k;
	char c;
};
int m,n,sx,sy,ex,ey;
char to;
int MAP[50][50];
point flag[51][51];
void search()
{
	queue<point> q;
	flag[sx][sy].k=true;
	flag[sx][sy].c=to;
	q.push(flag[sx][sy]);
	while(!q.empty())
	{
		int nx=q.front().x,ny=q.front().y;
		if(nx>=1&&flag[nx-1][ny].k==false)
		{
			if(nx>=2&&flag[nx-2][ny].k==false)
			{
				if(nx>=3&&flag[nx-3][ny].k==false)
				{
					flag[nx-3][ny].k=true;
					if((flag[nx][ny].c=='E'||flag[nx][ny].c=='W')&&flag[nx][ny]+2<flag[nx-3][ny]) 
						{flag[nx-3][ny].num=flag[nx][ny].num+2;flag[nx-3][ny].c='N';}
					if(flag[nx][ny].c=='S'&&flag[nx][ny]+3<flag[nx-3][ny])
						{flag[nx-3][ny].num=flag[nx][ny].num+3;flag[nx-3][ny].c='N';}
					if(flag[nx][ny].c=='N'&&flag[nx][ny]+1<flag[nx-3][ny]) 
						{flag[nx-3][ny].num=flag[nx][ny].num+1;flag[nx-3][ny].c='N';}
					q.push(flag[nx-3][ny]);
				}
				flag[nx-2][ny].k=true;
				if((flag[nx][ny].c=='E'||flag[nx][ny].c=='W')&&flag[nx][ny]+2<flag[nx-2][ny])
					{flag[nx-2][ny].num=flag[nx][ny].num+2;flag[nx-2][ny].c='N';}
				if(flag[nx][ny].c=='S'&&flag[nx][ny]+3<flag[nx-2][ny])
					{flag[nx-2][ny].num=flag[nx][ny].num+3;flag[nx-2][ny].c='N';}
				if(flag[nx][ny].c=='N'&&flag[nx][ny]+1<flag[nx-2][ny])
					{flag[nx-2][ny].num=flag[nx][ny].num+1;flag[nx-2][ny].c='N';}
				q.push(flag[nx-2][ny]);
			}
			flag[nx-1][ny].k=true;
			if((flag[nx][ny].c=='E'||flag[nx][ny].c=='W')&&flag[nx][ny]+2<flag[nx-1][ny])
				{flag[nx-1][ny].num=flag[nx][ny].num+2;flag[nx-1][ny].c='N';}
			if(flag[nx][ny].c=='S'&&flag[nx][ny]+3<flag[nx-1][ny])
				{flag[nx-1][ny].num=flag[nx][ny].num+3;flag[nx-1][ny].c='N';}
			if(flag[nx][ny].c=='N'&&flag[nx][ny]+1<flag[nx-1][ny]
				{flag[nx-1][ny].num=flag[nx][ny].num+1;flag[nx-1][ny].c='N';}
			q.push(flag[nx-1][ny]);
		}
		if(ny>=1&&flag[nx][ny-1].k==false)
		{
			if(ny>=2&&flag[nx][ny-2].k==false)
			{
				if(ny>=3&&flag[nx][ny-3].k==false)
				{
					flag[nx][ny-3].k=true;
					if((flag[nx][ny].c=='N'||flag[nx][ny].c=='S')&&flag[nx][ny].num+2<flag[nx][ny-3])
						{flag[nx][ny-3].num=flag[nx][ny].num+2;flag[nx][ny-3].c='W';}
					if(flag[nx][ny].c=='E'&&flag[nx][ny].num+3<flag[nx][ny-3])
						{flag[nx][ny-3].num=flag[nx][ny].num+3;flag[nx][ny-3].c='W';}
					if(flag[nx][ny].c=='W'&&flag[nx][ny].num+1<flag[nx][ny-3])
						{flag[nx][ny-3].num=flag[nx][ny].num+1;flag[nx][ny-3].c='W';}
					q.push(flag[nx][ny-3]);
				}
				flag[nx][ny-2].k=true;
				if((flag[nx][ny].c=='N'||flag[nx][ny].c=='S')&&flag[nx][ny].num+2<flag[nx][ny-2])
					{flag[nx][ny-2].num=flag[nx][ny].num+2;flag[nx][ny-2].c='W';}
				if(flag[nx][ny].c=='E'&&flag[nx][ny].num+3<flag[nx][ny-2])
					{flag[nx][ny-2].num=flag[nx][ny].num+3;flag[nx][ny-2].c='W';}
				if(flag[nx][ny].c=='W'&&flag[nx][ny].num+1<flag[nx][ny-2])
				{flag[nx][ny-2].num=flag[nx][ny].num+1;flag[nx][ny-2].c='W';}
				q.push(flag[nx][ny-2]);
			}
			flag[nx][ny-1].k=true;
			if((flag[nx][ny].c=='N'||flag[nx][ny].c=='S')&&flag[nx][ny].num+2<flag[nx][ny-1])
				{flag[nx][ny-1].num=flag[nx][ny].num+2;flag[nx][ny-1].c='W';}
			if(flag[nx][ny].c=='E'&&flag[nx][ny].num+3<flag[nx][ny-1])
				{flag[nx][ny-1].num=flag[nx][ny].num+3;flag[nx][ny-1].c='W';}
			if(flag[nx][ny].c=='W'&&flag[nx][ny].num+1<flag[nx][ny-1])
				{flag[nx][ny-1].num=flag[nx][ny].num+1;flag[nx][ny-1].c='W';}
			q.push(flag[nx][ny-1]);
		}
		if(nx<=m-1&&flag[nx+1][ny].k==false)
		{
			if(nx<=m-2&&flag[nx+2][ny].k==false)
			{
				if(nx<=m-3&&flag[nx+3][ny].k==false)
				{
					flag[nx+3][ny].k=true;
					if(flag[nx][ny].c=='E'||flag[nx][ny].c=='W') {flag[nx+3][ny].num=flag[nx][ny].num+2;flag[nx+3][ny].c='S';}
					if(flag[nx][ny].c=='N') {flag[nx+3][ny].num=flag[nx][ny].num+3;flag[nx+3][ny].c='S';}
					if(flag[nx][ny].c=='S') {flag[nx+3][ny].num=flag[nx][ny].num+1;flag[nx+3][ny].c='S';}
					q.push(flag[nx+3][ny]);
				}
				flag[nx+2][ny].k=true;
				if(flag[nx][ny].c=='E'||flag[nx][ny].c=='W') {flag[nx+2][ny].num=flag[nx][ny].num+2;flag[nx+2][ny].c='S';}
				if(flag[nx][ny].c=='N') {flag[nx+2][ny].num=flag[nx][ny].num+3;flag[nx+2][ny].c='S';}
				if(flag[nx][ny].c=='S') {flag[nx+2][ny].num=flag[nx][ny].num+1;flag[nx+2][ny].c='S';}
				q.push(flag[nx+2][ny]);
			}
			flag[nx+1][ny].k=true;
			if(flag[nx][ny].c=='E'||flag[nx][ny].c=='W') {flag[nx+1][ny].num=flag[nx][ny].num+2;flag[nx+1][ny].c='S';}
			if(flag[nx][ny].c=='N') {flag[nx+1][ny].num=flag[nx][ny].num+3;flag[nx+1][ny].c='S';}
			if(flag[nx][ny].c=='S') {flag[nx+1][ny].num=flag[nx][ny].num+1;flag[nx+1][ny].c='S';}
			q.push(flag[nx+1][ny]);
		}
		if(ny<=n-1&&flag[nx][ny+1].k==false)
		{
			if(ny<=n-2&&flag[nx][ny+2].k==false)
			{
				if(ny<=n-3&&flag[nx][ny+3].k==false)
				{
					flag[nx][ny+3].k=true;
					if(flag[nx][ny].c=='N'||flag[nx][ny].c=='S') {flag[nx][ny+3].num=flag[nx][ny].num+2;flag[nx][ny+3].c='E';}
					if(flag[nx][ny].c=='W') {flag[nx][ny+3].num=flag[nx][ny].num+3;flag[nx][ny+3].c='E';}
					if(flag[nx][ny].c=='E') {flag[nx][ny+3].num=flag[nx][ny].num+1;flag[nx][ny+3].c='E';}
					q.push(flag[nx][ny+3]);
				}
				flag[nx][ny+2].k=true;
				if(flag[nx][ny].c=='N'||flag[nx][ny].c=='S') {flag[nx][ny+2].num=flag[nx][ny].num+2;flag[nx][ny+2].c='E';}
				if(flag[nx][ny].c=='W') {flag[nx][ny+2].num=flag[nx][ny].num+3;flag[nx][ny+2].c='E';}
				if(flag[nx][ny].c=='E') {flag[nx][ny+2].num=flag[nx][ny].num+1;flag[nx][ny+2].c='E';}
				q.push(flag[nx][ny+2]);
			}
			flag[nx][ny+1].k=true;
			if(flag[nx][ny].c=='N'||flag[nx][ny].c=='S') {flag[nx][ny+1].num=flag[nx][ny].num+2;flag[nx][ny+1].c='E';}
			if(flag[nx][ny].c=='W') {flag[nx][ny+1].num=flag[nx][ny].num+3;flag[nx][ny+1].c='E';}
			if(flag[nx][ny].c=='E') {flag[nx][ny+1].num=flag[nx][ny].num+1;flag[nx][ny+1].c='E';}
			q.push(flag[nx][ny+1]);
		}
		q.pop();
	}
}
int main()
{
	memset(flag,0,sizeof(flag));
	scanf("%d%d",&m,&n);
	for(int i=0;i<m;++i)
		for(int j=0;j<n;++j)
		{
			flag[i][j].x=i;flag[i][j].y=j;
			if(flag[i][j].num!=-1) flag[i][j].num=99999;
			scanf("%d",&MAP[i][j]);
			if(MAP[i][j]==1)
			{
				flag[i][j].k=true;flag[i+1][j].k=true;flag[i][j+1].k=true;flag[i+1][j+1].k=true;
				flag[i][j].num=-1;flag[i+1][j].num=-1;flag[i][j+1].num=-1;flag[i+1][j+1].num=-1;
			}
		}
	for(int i=0;i<=n;++i) {flag[0][i].k=true;flag[m][i].k=true;flag[0][i].num=-1;flag[m][i].num=-1;}
	for(int i=0;i<=m;++i) {flag[i][0].k=true;flag[i][n].k=true;flag[i][0].num=-1;flag[i][n].num=-1;}
	scanf("%d%d%d%d %c",&sx,&sy,&ex,&ey,&to);
	for(int i=0;i<=m;++i)
	{
		for(int j=0;j<=n;++j)
		{
			printf("%2d ",flag[i][j].num);
		}
		printf("\n");
	}
	for(int i=0;i<=m;++i)
	{
		for(int j=0;j<=n;++j)
		{
			printf("%2d ",flag[i][j].k);
		}
		printf("\n");
	}
	search();
	printf("aftesearch\n");
	for(int i=0;i<=m;++i)
	{
		for(int j=0;j<=n;++j)
		{
			printf("%2d ",flag[i][j].num);
		}
		printf("\n");
	}
	return 0;
}
