#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN=501;
long long int ans=0,fanganshu=1;//记录最终的答案，出口数与方案数 
int n,m,u,v,fenliangtot=0,casenum=0;//顶点数、边数、储存边的信息的临时变量（u、v）、连通分量的总数、数据组数 
int zhan[MAXN],top=0;//dfs时用到的栈 
int visit=0,dfn[MAXN],low[MAXN];//tarjan“必备组件” 
int root[MAXN],num[MAXN],roottot=0;//在进行tarjan时记录根节点以及删除该节点后的分量个数
//在做题时怕会出现图不连通的情况，于是开了个roottot记录tarjan时根节点的个数
bool vis[MAXN];//dfs时用（事实上感觉像一个弱化了的dfn数组） 
struct fenliang//记录图的每一个“联通分量”的数据 
{
	int num,gediannum;//连通分量中的非割点数及割点数 
	fenliang() {num=0;gediannum=0;}
}group[MAXN];
struct edge//邻接表存图 
{
	int v;
	edge *NEXT;
	edge() {v=0;NEXT=NULL;}
}*con[MAXN];
inline void ins(int start,int end)//往图中加边 
{
	edge *p=new(edge);
	p->v=end;
	p->NEXT=con[start];
	con[start]=p;
}
inline void tarjan(int nv,int father)//tarjan模板 
{
	dfn[nv]=low[nv]=++visit;
	for(edge *p=con[nv];p;p=p->NEXT)
	{
		//nv跟vv在同一条边上，则有两种情况（在搜索树中）：
		//1、vv是nv的祖先，此时所遍历到的边就是一条后向边
		//2、vv是nv的儿子节点
		int vv=p->v;
		if(dfn[vv]==0)//如果vv之前没有被访问过，则vv是nv的儿子 
		{
			tarjan(vv,nv);
			low[nv]=min(low[nv],low[vv]); //递归以及更新 
			if(low[vv]>=dfn[nv]) ++num[nv];
			//low[vv]>=dfn[nv]说明在nv的这一棵子树中没有任何一个节点会连到nv的祖先上去
			//所以去掉nv后图就不连通了（nv是割点）
			//但因为无论根节点去掉之后图是否连通，low[vv]>=dfn[nv]一定会成立，所以要减1（见main函数） 
		}
		else if(vv!=father) low[nv]=min(low[nv],dfn[vv]);//否则就是情况一 
	}
}
inline void dfs(int nv)
{
	vis[nv]=true;
	zhan[++top]=nv;//在遍历时把遍历到的节点入栈 
	for(edge *p=con[nv];p;p=p->NEXT)
	{
		int vv=p->v;
		if(vis[vv]==false)
		{
			dfs(vv);//事实上这个函数和上面tarjan也就是多了下面的判断 
			//在有向图求强连通分量时，我们使用过一个栈，在栈中的元素有可能在同一个强连通分量里面
			//而对于这个无向图，同样的道理，只是我们把强连通分量换成了双联通分量 
			//具体操作事实上和在求强连通的分量时的if(low[nv]==dfn[nv])时一样的
			//只不过一个点可能会在多个双联通分量里面，而一个点最多只会在一个强连通分量里面
			//所以while要换到前面来，并且在最后加一个特判（判断这个点是不是一个割点）
			if(low[vv]>=dfn[nv])
			{
				++fenliangtot; //求到了一个双连通分量 
				int place=zhan[top];
				while(place!=nv)
				{
					--top;
					if(num[place]) ++group[fenliangtot].gediannum; //现在这个点是割点 
					else ++group[fenliangtot].num; //现在这个点不是割点 
					place=zhan[top];
				}
				//对于这一棵子树的根节点的特判 
				cout<<place<<" "<<num[place]<<"fuck"<<endl;
				if(num[place]) ++group[fenliangtot].gediannum;
				else ++group[fenliangtot].num;
				cout<<group[fenliangtot].gediannum<<" "<<group[fenliangtot].num<<endl;
			}
		}
	}
}
inline int read()//日常读入优化 
{
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
	return x*f;
}
int main()
{
	while(true)
	{
		m=read();//读入边数 
		if(m==0) return 0;//输入结束 
		memset(con,0,sizeof(con));
		memset(dfn,0,sizeof(dfn));
		memset(num,0,sizeof(num));
		memset(vis,0,sizeof(vis));
		memset(group,0,sizeof(group));
		ans=n=roottot=fenliangtot=0;
		fanganshu=1;
		//该初始化的东西全部初始化一遍 
		while(m--)
		{
			u=read();v=read();
			n=max(n,max(u,v));
			ins(u,v);ins(v,u);
		}//不断往图中加边，因为是无向图，所以加两次 
		cout<<n<<endl;
		for(int i=1;i<=n;++i)
			if(dfn[i]==0)
			{root[++roottot]=i;tarjan(i,0);}//tarjan找割点 
		//记录根节点是因为根节点要特判，要在tarjan中求出的num值减一才是它的真实的num值 
		for(int i=1;i<=n;++i) cout<<dfn[i]<<" ";cout<<endl;
		for(int i=1;i<=n;++i) cout<<low[i]<<" ";cout<<endl;
		for(int i=1;i<=roottot;++i)
			if(num[root[i]]!=0) --num[root[i]];//经过这样处理后所有num值为真的点就是割点了 
		for(int i=1;i<=n;++i) cout<<num[i]<<" ";cout<<endl;
		for(int i=1;i<=n;++i)
			if(vis[i]==false) dfs(i);//dfs求点双连通分量 
		for(int i=1;i<=fenliangtot;++i)//遍历求到的双连通分量的数据 
		{
			int a=group[i].num,b=group[i].gediannum;
			cout<<a<<" "<<b<<endl;
			if(b>=2) continue;//如果这个双连通分量中割点数大于等于2，说明不要建出口 
			else if(b==1) {++ans;fanganshu*=a;}//如果割点数等于1，则需要建一个出口 
			else if(b==0) {ans+=2;fanganshu*=(a*(a-1)/2);}//如果不存在割点，则要建两个出口 
		}
		printf("Case %d: %lld %lld\n",++casenum,ans,fanganshu);
	}
}
