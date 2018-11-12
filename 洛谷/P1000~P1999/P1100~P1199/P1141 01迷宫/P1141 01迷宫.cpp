#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
struct MA
{
	int x,y;
	char c;
	int *point;
	MA(){point=NULL;}
};
MA MAP[1000][1000];
bool flag[1000][1000];
queue<int> ans;
void getready(int k)
{
	flag[0][0]=true;
	for(int i=0;i<k;++i)
		for(int j=0;j<k;++j)
			if(MAP[i][j].point==NULL)
			{
				flag[i][j]=true;
				ans.push(1);
				MAP[i][j].point=&ans.back();
				queue<MA> q;
				q.push(MAP[i][j]);
				while(!q.empty())
				{
					int nx=q.front().x,ny=q.front().y;
					if(q.front().c=='0')
					{
						if(nx!=0&&MAP[nx-1][ny].c=='1'&&flag[nx-1][ny]==false)
							{MAP[nx-1][ny].point=&ans.back();flag[nx-1][ny]=true;++ans.back();q.push(MAP[nx-1][ny]);}
						if(ny!=0&&MAP[nx][ny-1].c=='1'&&flag[nx][ny-1]==false)
							{MAP[nx][ny-1].point=&ans.back();flag[nx][ny-1]=true;++ans.back();q.push(MAP[nx][ny-1]);}
						if(nx!=k-1&&MAP[nx+1][ny].c=='1'&&flag[nx+1][ny]==false)
							{MAP[nx+1][ny].point=&ans.back();flag[nx+1][ny]=true;++ans.back();q.push(MAP[nx+1][ny]);}
						if(ny!=k-1&&MAP[nx][ny+1].c=='1'&&flag[nx][ny+1]==false)
							{MAP[nx][ny+1].point=&ans.back();flag[nx][ny+1]=true;++ans.back();q.push(MAP[nx][ny+1]);}
					}
					if(q.front().c=='1')
					{
						if(nx!=0&&MAP[nx-1][ny].c=='0'&&flag[nx-1][ny]==false)
							{MAP[nx-1][ny].point=&ans.back();flag[nx-1][ny]=true;++ans.back();q.push(MAP[nx-1][ny]);}
						if(ny!=0&&MAP[nx][ny-1].c=='0'&&flag[nx][ny-1]==false)
							{MAP[nx][ny-1].point=&ans.back();flag[nx][ny-1]=true;++ans.back();q.push(MAP[nx][ny-1]);}
						if(nx!=k-1&&MAP[nx+1][ny].c=='0'&&flag[nx+1][ny]==false)
							{MAP[nx+1][ny].point=&ans.back();flag[nx+1][ny]=true;++ans.back();q.push(MAP[nx+1][ny]);}
						if(ny!=k-1&&MAP[nx][ny+1].c=='0'&&flag[nx][ny+1]==false)
							{MAP[nx][ny+1].point=&ans.back();flag[nx][ny+1]=true;++ans.back();q.push(MAP[nx][ny+1]);}
					}
					q.pop();
				}
			}
}
int main()
{
	memset(flag,0,sizeof(flag));
	int n,m,x,y;
	scanf("%d%d\n",&n,&m);
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
		{
			MAP[i][j].x=i;MAP[i][j].y=j;
			if(j==n-1) scanf("%c\n",&MAP[i][j].c);
			else scanf("%c",&MAP[i][j].c);
		}
	getready(n);
	for(int w=0;w<m;++w)
	{
		scanf("%d%d",&x,&y);
		printf("%d\n",*MAP[x-1][y-1].point);
	}
	return 0;
}
