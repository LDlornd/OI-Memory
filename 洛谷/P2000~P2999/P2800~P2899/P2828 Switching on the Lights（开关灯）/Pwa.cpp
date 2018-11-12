#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN=10001;//最多的点数 
int n,m,xx,yy,sp,ep,ans=1; 
int to[4];//方向数组 
int dl1[MAXN],head1=1,tail1=1; //BFS时用到的队列 
int dl2[MAXN],head2=1,tail2=1; //储存打开了灯目前却不能到达的房间的队列 
bool light_up[MAXN],vis[MAXN]; //灯是否已打开   是否这个点已经被访问过 
int indl[MAXN];                //每个点在哪个队列种（或是不在队列中） 
struct edge
{
	int v;
	edge *NEXT;
	edge() {v=0;NEXT=NULL;}
}*con[MAXN];                        //采用图的方式去存可以打开的灯的信息 
inline void ins(int start,int end)  //新的关系（加一条边） 
{
	edge *p=new(edge);
	p->v=end;
	p->NEXT=con[start];
	con[start]=p;
}
inline bool check(int nowplace)          //判断点是否能够到达 
{
	for(int i=0;i<4;++i)
	{
		int place=nowplace+to[i];
		if(place<1||place>n*n) continue;
		if(place%n==0&&to[i]==-1) continue;   //防bug 
		if(place%n==1&&to[i]==1) continue;    //防bug 
		if(vis[place]) return true;
	}
	return false;
}
inline void bfs()
{
	bool flag=false;      //判断是不是要再一次遍历 
	head2=tail2=1;   //另一个队列的初始化 
	while(head1<tail1)
	{
		int nv=dl1[head1++];indl[nv]=0;         //队首元素出队 
		if(check(nv)==false&&vis[nv]==false)    //判断目前这个房间能否被到达，或是本来就被到达过（主要是为了统一 1 这个点） 
			{dl2[tail2++]=nv;continue;}
		vis[nv]=true;flag=true;               //队列中有房间可以到达，可能会产生新的变化。 
		for(edge *p=con[nv];p;p=p->NEXT)
		{
			int vv=p->v;
			if(light_up[vv]==false)
				{light_up[vv]=true;++ans;}     //点亮关着灯的房间的灯 
			if(check(vv))                            //如果这个点能够被到达 
				if(indl[vv]==0&&vis[vv]==false)        
					{dl1[tail1++]=vv;indl[vv]=1;}	//放到遍历的队列中去 
				else continue;
			else if(indl[vv]==0&&vis[vv]==false)      
					{dl2[tail2++]=vv;indl[vv]=2;}	//如果不能到达，放到另外一个队列中去，待会再搜一次 
		}               //注意：在入队时只能取不在队列且未被访问过的房间，不然会导致重复搜索，甚至无限递归 
	}
	if(flag)        //如果有房间可以被到达 
	{
		for(int i=head2;i<=tail2;++i)
			dl1[i]=dl2[i];
		head1=head2;tail1=tail2;      //上三行主要是懒得写两个函数于是用队列2覆盖队列1 
		bfs();               //继续搜索 
	}
}
inline int read()   //日常读入优化 
{
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
	return x*f;
}
int main()
{
	memset(indl,0,sizeof(indl));
	memset(light_up,0,sizeof(light_up));
	memset(vis,0,sizeof(vis));
	n=read();m=read();
	to[0]=-1*n;to[1]=1;to[2]=n;to[3]=-1;
	while(m--)
	{
		sp=(((xx=read())-1)*n+(yy=read()));  //降维操作 
		ep=(((xx=read())-1)*n+(yy=read()));	 //降维操作 
		ins(sp,ep);
	}
	dl1[tail1++]=1;indl[1]=1;
	vis[1]=true;light_up[1]=true;      //各种初始化 
	bfs();
	printf("%d",ans);
	return 0;
}
